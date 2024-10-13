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
    DOMNode* dom_creater_main();

    void renderDOMNode(DOMNode* node, QVBoxLayout* layout);
    void renderDOMTree(DOMNode* root, QVBoxLayout* layout);

 #endif
