#include "pages.h"
#include <curl/curl.h>
#include <thread>
#include <mutex>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QTabWidget>
#include <QString>
#include <QMetaObject>
#include <iostream>

using namespace std;

std::mutex tab_mutex;


size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    s->append((char*)contents, newLength);
    return newLength;
}

std::string fetch_html_from_url(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string html_content;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html_content);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    return html_content;
}

void fetch_and_create_tab(QTabWidget* tabWidget, const std::string& url) {
    std::string html_content = fetch_html_from_url(url);

    QMetaObject::invokeMethod(tabWidget, [tabWidget, html_content]() {
        DOMNode* root = dom_creater_string(html_content);
        if (root == nullptr) return;

        std::string titleText = findTitle(root); 

        QWidget* tab = new QWidget();
        QVBoxLayout* tabLayout = new QVBoxLayout(tab);
        renderDOMTree(root, tabLayout); 


        QString tabName = QString::fromStdString(titleText.empty() ? "Untitled" : titleText);
        tab->setLayout(tabLayout);
        tabWidget->addTab(tab, tabName);
    }, Qt::QueuedConnection);
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
        std::string url = "http://localhost:8000/html_page_" + std::to_string(tabCounter) + ".html";
        std::thread fetch_thread(fetch_and_create_tab, tabWidget, url); 
        fetch_thread.detach();

        tabCounter = (tabCounter%5)+1;
    });

    window.show();
    return app.exec();
}

