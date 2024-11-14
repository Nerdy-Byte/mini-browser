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

// Function to fetch HTML asynchronously and update an existing tab with the content
void fetch_html_async(const QString& url, QTabWidget* tabWidget) {
    for (int i = 0; i < tabWidget->count(); ++i) {
        if (tabWidget->tabText(i) == url) {
            tabWidget->setCurrentIndex(i);
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

        DOMNode* root = dom_creater_string(html_content.toStdString());
        if (!root) return;

        std::string titleText = findTitle(root);

        QWidget* currentTab = tabWidget->currentWidget();
        if (currentTab) {
            QVBoxLayout* tabLayout = qobject_cast<QVBoxLayout*>(currentTab->layout());
            if (tabLayout) {
                QLayoutItem* item;
                while ((item = tabLayout->takeAt(0)) != nullptr) {
                    delete item->widget();
                    delete item;
                }

                renderDOMTree(root, tabLayout, tabWidget);
                QString tabName = QString::fromStdString(titleText.empty() ? "Untitled" : titleText);
                tabWidget->setTabText(tabWidget->currentIndex(), tabName);
            }
        }

    });
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
                fetch_html_async(fullUrl, tabWidget);
            }
        });
        newTab->setLayout(tabLayout);
        tabWidget->addTab(newTab, "Tab " + QString::number(tabCounter++));
    });

    window.show();
    return app.exec();
}
