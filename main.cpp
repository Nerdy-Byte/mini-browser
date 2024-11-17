#include "dom_creater.h"
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLineEdit>
#include <QMap>
#include <pthread.h>
#include <queue>
#include <utility>

/**
 * @file main.cpp
 * @brief Entry point for the DOM Browser application using pthread for concurrency.
 */

/**
 * @brief Cache to store previously fetched and parsed pages.
 *
 * The cache maps URLs to a pair of parsed DOM nodes and their titles.
 */
QMap<QString, std::pair<DOMNode*, std::string>> pageCache;

/**
 * @brief Structure to pass data between threads for fetching and parsing.
 */
struct TaskData {
    QString url;
    std::string content;
    DOMNode* root = nullptr;
    std::string title;
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t condition = PTHREAD_COND_INITIALIZER;
    bool isComplete = false;
};

/**
 * @brief Thread function for fetching HTML content.
 *
 * This function fetches HTML content from the specified URL.
 * @param arg Pointer to `TaskData` containing the URL and results.
 * @return nullptr
 */
void* fetchHtmlThread(void* arg) {
    TaskData* data = static_cast<TaskData*>(arg);

    HtmlFetcher fetcher(data->url);
    std::string content = fetcher.fetchSync();

    pthread_mutex_lock(&data->mutex);
    data->content = content;
    pthread_cond_signal(&data->condition);
    pthread_mutex_unlock(&data->mutex);

    return nullptr;
}

/**
 * @brief Thread function for parsing HTML content.
 *
 * This function parses HTML content into a DOM tree.
 * @param arg Pointer to `TaskData` containing HTML content and results.
 * @return nullptr
 */
void* parseHtmlThread(void* arg) {
    TaskData* data = static_cast<TaskData*>(arg);

    HtmlParser parser(data->content);
    auto [root, title] = parser.parseSync();

    pthread_mutex_lock(&data->mutex);
    data->root = root;
    data->title = title;
    data->isComplete = true;
    pthread_cond_signal(&data->condition);
    pthread_mutex_unlock(&data->mutex);

    return nullptr;
}

/**
 * @brief Renders HTML content in a browser tab.
 *
 * Fetches and parses the content using pthread and renders it in the specified tab.
 * @param url The URL of the page to render.
 * @param tabWidget The `QTabWidget` containing browser tabs.
 * @param tabIndex The index of the tab to render the content in.
 */
void renderContent(const QString& url, QTabWidget* tabWidget, int tabIndex) {
    // Check if the page is already cached
    if (pageCache.contains(url)) {
        auto [cachedRoot, cachedTitle] = pageCache[url];
        HtmlRenderer* renderer = new HtmlRenderer(tabWidget, tabIndex);
        renderer->render(cachedRoot, cachedTitle);
        return;
    }

    // Create shared data for the fetch and parse tasks
    TaskData taskData;
    taskData.url = url;

    pthread_t fetchThread, parseThread;

    // Start the fetch thread
    pthread_create(&fetchThread, nullptr, fetchHtmlThread, &taskData);

    // Wait for fetch to complete
    pthread_mutex_lock(&taskData.mutex);
    while (taskData.content.empty()) {
        pthread_cond_wait(&taskData.condition, &taskData.mutex);
    }
    pthread_mutex_unlock(&taskData.mutex);

    // Start the parse thread
    pthread_create(&parseThread, nullptr, parseHtmlThread, &taskData);

    // Wait for parse to complete
    pthread_mutex_lock(&taskData.mutex);
    while (!taskData.isComplete) {
        pthread_cond_wait(&taskData.condition, &taskData.mutex);
    }
    pthread_mutex_unlock(&taskData.mutex);

    // Cache the result
    pageCache[url] = std::make_pair(taskData.root, taskData.title);

    // Render the content
    HtmlRenderer* renderer = new HtmlRenderer(tabWidget, tabIndex);
    renderer->render(taskData.root, taskData.title);

    // Clean up threads
    pthread_join(fetchThread, nullptr);
    pthread_join(parseThread, nullptr);
}

/**
 * @brief Creates a new browser tab with input fields for URL entry and an HTML fetch button.
 *
 * Adds a new tab to the `QTabWidget` and connects the fetch button to the `renderContent` function.
 * @param tabWidget The `QTabWidget` where the new tab will be added.
 */
void createNewTab(QTabWidget* tabWidget) {
    QWidget* newTab = new QWidget();
    QVBoxLayout* tabLayout = new QVBoxLayout(newTab);

    QLineEdit* urlInput = new QLineEdit();
    urlInput->setPlaceholderText("Enter URL here...");
    tabLayout->addWidget(urlInput);

    QPushButton* fetchButton = new QPushButton("Fetch HTML");
    tabLayout->addWidget(fetchButton);

    int currentTabIndex = tabWidget->addTab(newTab, "New Tab");
    newTab->setLayout(tabLayout);

    QObject::connect(fetchButton, &QPushButton::clicked, [=]() {
        QString url = urlInput->text();
        if (!url.isEmpty()) {
            QString fullUrl = "http://localhost:8000/" + url;
            renderContent(fullUrl, tabWidget, currentTabIndex);
        }
    });
}

/**
 * @brief The main function of the DOM Browser application.
 *
 * Initializes the Qt application, sets up the main window with a tab widget, and allows users to open, fetch, and render HTML pages.
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return The exit code of the application.
 */
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("DOM Browser");
    window.resize(900, 900);

    QTabWidget* tabWidget = new QTabWidget(&window);
    tabWidget->setTabsClosable(true);

    // Connect the tab close signal to a function that removes and cleans up the tab
    QObject::connect(tabWidget, &QTabWidget::tabCloseRequested, [tabWidget](int index) {
        QWidget* tab = tabWidget->widget(index);
        tabWidget->removeTab(index);
        delete tab; // Clean up the memory
    });

    QPushButton* addTabButton = new QPushButton("Add New Tab");
    QVBoxLayout* mainLayout = new QVBoxLayout(&window);
    mainLayout->addWidget(addTabButton);
    mainLayout->addWidget(tabWidget);
    window.setLayout(mainLayout);

    // Connect the add tab button to the function that creates a new tab
    QObject::connect(addTabButton, &QPushButton::clicked, [=]() {
        createNewTab(tabWidget);
    });

    window.show();
    return app.exec();
}
