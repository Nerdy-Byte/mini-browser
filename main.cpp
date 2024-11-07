#include "pages.h"
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QMetaObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <iostream>

using namespace std;

// Function to fetch HTML asynchronously and create a new tab
void fetch_html_async(const QString& url, QTabWidget* tabWidget) {
    // Check if the tab with the same URL title already exists
    for (int i = 0; i < tabWidget->count(); ++i) {
        if (tabWidget->tabText(i) == url) {
            tabWidget->setCurrentIndex(i);  // Switch to the existing tab
            return;
        }
    }

    // Initialize the network manager, owned by tabWidget to avoid memory leaks
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

        // Create DOM from fetched HTML content
        DOMNode* root = dom_creater_string(html_content.toStdString());
        if (!root) return;

        std::string titleText = findTitle(root);

        // Create new tab for the content
        QWidget* tab = new QWidget();
        QVBoxLayout* tabLayout = new QVBoxLayout(tab);
        renderDOMTree(root, tabLayout, tabWidget);  // Pass tabWidget here

        QString tabName = QString::fromStdString(titleText.empty() ? "Untitled" : titleText);
        tab->setLayout(tabLayout);
        tabWidget->addTab(tab, tabName);
        tabWidget->setCurrentWidget(tab);  // Switch to the new tab
    });

    // Send the network request
    manager->get(QNetworkRequest(QUrl(url)));
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
        QString url = "http://localhost:8000/html_page_" + QString::number(tabCounter) + ".html";
        fetch_html_async(url, tabWidget);  // Call the async fetch function
        tabCounter = (tabCounter % 5) + 1;
    });

    window.show();
    return app.exec();
}
