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
#include <omp.h>
#include <QThread>

// Forward declarations of functions
void render_html(DOMNode* root, QTabWidget* tabWidget, int tabIndex, const std::string& titleText, const QString& url);
void parse_html(const QString& html_content, QTabWidget* tabWidget, int tabIndex, const QString& url);
void fetch_html(const QString& url, QTabWidget* tabWidget, int tabIndex);

void fetch_html(const QString& url, QTabWidget* tabWidget, int tabIndex) {
    QNetworkAccessManager* manager = new QNetworkAccessManager(tabWidget);

    QObject::connect(manager, &QNetworkAccessManager::finished, [tabWidget, url, tabIndex](QNetworkReply* reply) {
        if (reply->error() != QNetworkReply::NoError) {
            std::cerr << "Error fetching URL: " << reply->errorString().toStdString() << std::endl;
            reply->deleteLater();
            return;
        }

        QString html_content = reply->readAll();
        reply->deleteLater();

#pragma omp task
        parse_html(html_content, tabWidget, tabIndex, url);
    });

    manager->get(QNetworkRequest(QUrl(url)));
}

void parse_html(const QString& html_content, QTabWidget* tabWidget, int tabIndex, const QString& url) {
    DOMNode* root = nullptr;

#pragma omp task shared(root)
    {
        root = dom_creater_string(html_content.toStdString());
    }

#pragma omp taskwait

    if (!root) return;

    std::string titleText = findTitle(root);

    QMetaObject::invokeMethod(tabWidget, [=]() {
        render_html(root, tabWidget, tabIndex, titleText, url);
    });
}

void render_html(DOMNode* root, QTabWidget* tabWidget, int tabIndex, const std::string& titleText, const QString& url) {
    QWidget* targetTab = tabWidget->widget(tabIndex);
    if (targetTab) {
        QVBoxLayout* tabLayout = qobject_cast<QVBoxLayout*>(targetTab->layout());
        if (tabLayout) {
            // Clear the previous content
            QLayoutItem* item;
            while ((item = tabLayout->takeAt(0)) != nullptr) {
                delete item->widget();
                delete item;
            }
            renderDOMTree(root, tabLayout, tabWidget);

            // Set the tab name
            QString tabName = QString::fromStdString(titleText.empty() ? "Untitled" : titleText);
            tabWidget->setTabText(tabIndex, tabName);
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

                int currentTabIndex = tabWidget->addTab(newTab, "Tab " + QString::number(tabCounter++));
                newTab->setLayout(tabLayout);

                QObject::connect(fetchButton, &QPushButton::clicked, [=]() {
                    QString url = urlInput->text();
                    if (!url.isEmpty()) {
                        QString fullUrl = "http://localhost:8000/" + url;
#pragma omp task
                        fetch_html(fullUrl, tabWidget, currentTabIndex);
                    }
                });
            }
        }
    });

    window.show();
    return app.exec();
}
