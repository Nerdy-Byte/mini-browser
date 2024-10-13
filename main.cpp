#include "pages.h"
#include <curl/curl.h>
#include <thread>
#include <mutex>
using namespace std;
// Mutex for synchronizing access to shared resources
std::mutex tab_mutex;

// Callback function to write data from curl to a string
size_t write_callback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size * nmemb;
    s->append((char*)contents, newLength);
    return newLength;
}

// Function to fetch HTML content from a URL using libcurl
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

// Function to handle fetching and rendering a tab (runs in a thread)
void createTab(QTabWidget* tabWidget, const std::string& url, const std::string& tabName) {
    std::string html_content = fetch_html_from_url(url);

    // Critical section: modify shared tab widget
    std::lock_guard<std::mutex> lock(tab_mutex);
    // cout<<html_content<<endl;
    DOMNode* root = dom_creater_string(html_content);  // Create DOM from fetched HTML
    if (root == nullptr) {
        std::cerr << "Error: DOM root is null for URL: " << url << std::endl;
        return;
    }

    QWidget* tab = new QWidget();
    QVBoxLayout* tabLayout = new QVBoxLayout(tab);
    renderDOMTree(root, tabLayout);  // Render DOM in the new tab
    tab->setLayout(tabLayout);
    tabWidget->addTab(tab, QString::fromStdString(tabName));
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("DOM Browser");
    window.resize(700, 700);

    DOMNode* root = dom_creater_main("/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/input.html"); //modify to your input.html file path

    if (root == nullptr) {
        std::cerr << "Error: DOM root is null." << std::endl;
        return -1;
    } else {
        root->print();
    }

    //code for testing development

    QTabWidget* tabWidget = new QTabWidget(&window);
    QWidget* tab1 = new QWidget();
    QVBoxLayout* tabLayout1 = new QVBoxLayout(tab1);
    renderDOMTree(root, tabLayout1);
    tab1->setLayout(tabLayout1);
    tabWidget->addTab(tab1, "DOM View");


    //#########################uncomment to make different threads it pulls the html pages from localhost######################################

    // QTabWidget* tabWidget = new QTabWidget(&window);

    // Create threads for different tabs
    // std::thread tab1_thread(createTab, tabWidget, "http://localhost:8000/html_page_1.html", "Tab 1");
    // std::thread tab2_thread(createTab, tabWidget, "http://localhost:8000/html_page_2.html", "Tab 2");

    // // Wait for both threads to finish before proceeding
    // tab1_thread.join();
    // tab2_thread.join();

    //##########################################################################################################################################

    QVBoxLayout* mainLayout = new QVBoxLayout(&window);
    mainLayout->addWidget(tabWidget);
    window.setLayout(mainLayout);

    window.show();
    return app.exec();
}
