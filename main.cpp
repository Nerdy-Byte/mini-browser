#include "dom_creater.h"
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMetaObject>
#include <QLineEdit>
#include <QMap>
#include <omp.h>

// Forward declarations
void fetch_and_parse(const QString& url, QTabWidget* tabWidget, int tabIndex);

// Cache to store previously fetched and parsed pages
QMap<QString, std::pair<DOMNode*, std::string>> pageCache;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("DOM Browser");
    window.resize(900, 900);

    QTabWidget* tabWidget = new QTabWidget(&window);
    QVBoxLayout* mainLayout = new QVBoxLayout(&window);

    // Enable close buttons on each tab
    tabWidget->setTabsClosable(true);

    // Connect the close request to remove and delete the tab
    QObject::connect(tabWidget, &QTabWidget::tabCloseRequested, [tabWidget](int index) {
        QWidget* tab = tabWidget->widget(index);
        tabWidget->removeTab(index);
        delete tab;  // Clean up the memory
    });

    QPushButton* addTabButton = new QPushButton("Add New Tab");
    mainLayout->addWidget(addTabButton);
    mainLayout->addWidget(tabWidget);
    window.setLayout(mainLayout);

    QObject::connect(addTabButton, &QPushButton::clicked, [&]() {
#pragma omp parallel num_threads(2)
        {
#pragma omp single
            {
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

                        // Check if the page is already cached
                        if (pageCache.contains(fullUrl)) {
                            std::pair<DOMNode*, std::string> cachedData = pageCache[fullUrl];
                            DOMNode* cachedRoot = cachedData.first;
                            std::string cachedTitle = cachedData.second;

                            // Render the cached content directly
                            HtmlRenderer* renderer = new HtmlRenderer(tabWidget, currentTabIndex);
                            renderer->render(cachedRoot, cachedTitle);
                        } else {
                            // Fetch the HTML if not cached
                            HtmlFetcher* fetcher = new HtmlFetcher(fullUrl, tabWidget, currentTabIndex);
                            QObject::connect(fetcher, &HtmlFetcher::fetchFinished, [=](const QString& content) {
                                // Parse the HTML
                                HtmlParser* parser = new HtmlParser(content);
                                QObject::connect(parser, &HtmlParser::parsingFinished, [=](DOMNode* root, const std::string& titleText) {
                                    // Cache the parsed result
                                    pageCache[fullUrl] = std::make_pair(root, titleText);

                                    // Render the DOM tree
                                    HtmlRenderer* renderer = new HtmlRenderer(tabWidget, currentTabIndex);
                                    renderer->render(root, titleText);
                                });
                                parser->parse();
                            });

                            fetcher->fetch();
                        }
                    }
                });
            }
        }
    });

    window.show();
    return app.exec();
}
