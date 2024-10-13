 #ifndef DOM_CREATER_H
 #define DOM_CREATER_H

    #include <QApplication>
    #include <QTextEdit>
    #include <QVBoxLayout>
    #include <QLabel>
    #include <QWidget>
    #include <QListWidget>
    #include <QTabWidget>
    #include "dom_tree.h"
    DOMNode* dom_creater_main(char*);

    void renderDOMNode(DOMNode* node, QVBoxLayout* layout);
    void renderDOMTree(DOMNode* root, QVBoxLayout* layout);

    //functions for featching the pages.

    // void fetchHTML(const std::string& url, const std::string& filename);
    // size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp);
    // DOMNode* fetched_pages();

 #endif
