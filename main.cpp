#include "dom_creater.h"
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLineEdit>
#include <QMap>
#include <future>

/**
 * @file main.cpp
 * @brief Entry point for the DOM Browser application. Implements HTML fetching, parsing, rendering, and tabbed browsing with caching.
 */

/**
 * @brief Cache to store previously fetched and parsed pages.
 *
 * The cache maps URLs to a pair of parsed DOM nodes and their titles.
 */
QMap<QString, std::pair<DOMNode*, std::string>> pageCache;

/**
 * @brief Fetches HTML content from the specified URL.
 *
 * This function performs a synchronous HTTP request to retrieve the HTML content.
 * @param url The URL to fetch content from.
 * @return The fetched HTML content as a `std::string`.
 */
std::string fetchHtmlContent(const QString& url) {
    HtmlFetcher fetcher(url);
    return fetcher.fetchSync(); // A synchronous fetch implementation
}

/**
 * @brief Parses the fetched HTML content into a DOM tree.
 *
 * This function performs synchronous parsing of the HTML content and returns the root DOM node and page title.
 * @param content The HTML content to parse.
 * @return A pair containing the root DOM node and the page title.
 */
std::pair<DOMNode*, std::string> parseHtmlContent(const std::string& content) {
    HtmlParser parser(content);
    return parser.parseSync(); // A synchronous parse implementation returning root node and title
}

/**
 * @brief Renders HTML content in a browser tab.
 *
 * Fetches and parses the content either from the cache or by making HTTP requests and parsing in parallel.
 * If the content is fetched and parsed successfully, it is rendered in the specified tab.
 * @param url The URL of the page to render.
 * @param tabWidget The `QTabWidget` containing browser tabs.
 * @param tabIndex The index of the tab to render the content in.
 */
void renderContent(const QString& url, QTabWidget* tabWidget, int tabIndex) {
    // Check if the page is already cached (non-parallel)
    if (pageCache.contains(url)) {
        auto [cachedRoot, cachedTitle] = pageCache[url];

        // Render the cached content
        HtmlRenderer* renderer = new HtmlRenderer(tabWidget, tabIndex);
        renderer->render(cachedRoot, cachedTitle);
        return;
    }

    // Fetch and parse HTML in parallel
    auto fetchFuture = std::async(std::launch::async, fetchHtmlContent, url);
    std::string content = fetchFuture.get(); // Wait for fetch to complete

    auto parseFuture = std::async(std::launch::async, parseHtmlContent, content);
    auto [root, titleText] = parseFuture.get(); // Wait for parse to complete

    // Cache the parsed result (non-parallel)
    pageCache[url] = std::make_pair(root, titleText);

    // Render the DOM tree (non-parallel)
    HtmlRenderer* renderer = new HtmlRenderer(tabWidget, tabIndex);
    renderer->render(root, titleText);
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
