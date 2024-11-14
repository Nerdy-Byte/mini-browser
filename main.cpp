#include "pages.h"
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMetaObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QLineEdit>
#include <iostream>

using namespace std;

void render_html(DOMNode* root, QTabWidget* tabWidget, const std::string& titleText, const QString& url);
void parse_html(const QString& html_content, QTabWidget* tabWidget, const QString& url);

// Function to fetch HTML asynchronously
void fetch_html(const QString& url, QTabWidget* tabWidget) {
    QNetworkAccessManager* manager = new QNetworkAccessManager(tabWidget);

    // Connect network request to handle fetched HTML content
    QObject::connect(manager, &QNetworkAccessManager::finished, [tabWidget, url](QNetworkReply* reply) {
        if (reply->error() != QNetworkReply::NoError) {
            cerr << "Error fetching URL: " << reply->errorString().toStdString() << endl;
            reply->deleteLater();
            return;
        }

        QString html_content = reply->readAll();
        reply->deleteLater();

        // Call the parse_html function to parse the content
        parse_html(html_content, tabWidget, url);
    });

    manager->get(QNetworkRequest(QUrl(url)));
}

// Function to parse the fetched HTML content
void parse_html(const QString& html_content, QTabWidget* tabWidget, const QString& url) {
    DOMNode* root = dom_creater_string(html_content.toStdString());
    if (!root) return;

    std::string titleText = findTitle(root);

    // Call the render_html function to render the parsed DOM content in the tab
    render_html(root, tabWidget, titleText, url);
}

// Function to render the parsed HTML content in the tab
void render_html(DOMNode* root, QTabWidget* tabWidget, const std::string& titleText, const QString& url) {
    QWidget* currentTab = tabWidget->currentWidget();
    if (currentTab) {
        QVBoxLayout* tabLayout = qobject_cast<QVBoxLayout*>(currentTab->layout());
        if (tabLayout) {
            // Clear the previous content
            QLayoutItem* item;
            while ((item = tabLayout->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }

            // Render the new DOM content
            renderDOMTree(root, tabLayout, tabWidget);

            // Set the tab name
            QString tabName = QString::fromStdString(titleText.empty() ? "Untitled" : titleText);
            tabWidget->setTabText(tabWidget->currentIndex(), tabName);
        }
    }
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("DOM Browser");
    window.resize(900, 900);

    QTabWidget* tabWidget = new QTabWidget(&window);
    QVBoxLayout* mainLayout = new QVBoxLayout(&window);

    QPushButton* addTabButton = new QPushButton("Add New Tab");
    mainLayout->addWidget(addTabButton);
    mainLayout->addWidget(tabWidget);
    window.setLayout(mainLayout);

    int tabCounter = 1;

    QObject::connect(addTabButton, &QPushButton::clicked, [&]() {

        QWidget* newTab = new QWidget();
        QVBoxLayout* tabLayout = new QVBoxLayout(newTab);

        QLineEdit* urlInput = new QLineEdit();
        urlInput->setPlaceholderText("Enter URL here...");
        tabLayout->addWidget(urlInput);

        QPushButton* fetchButton = new QPushButton("Fetch HTML");
        tabLayout->addWidget(fetchButton);

        QObject::connect(fetchButton, &QPushButton::clicked, [=]() {
            QString url = urlInput->text();
            if (!url.isEmpty()) {
                QString fullUrl = "http://localhost:8000/" + url;
                fetch_html(fullUrl, tabWidget);  // Fetch HTML
            }
        });

        newTab->setLayout(tabLayout);
        tabWidget->addTab(newTab, "Tab " + QString::number(tabCounter++));
    });

    window.show();
    return app.exec();
}
