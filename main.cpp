#include <QApplication>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <iostream>
#include "dom_creater.h"

using namespace std;

void renderDOMNode(DOMNode* node, QVBoxLayout* layout) {
    if (node == nullptr) {
        cout << "tree is empty!" << endl;
        return;
    }

    TagType tagType = getTagType(node->getName());
    switch (tagType) {
    case TagType::ROOT:
    case TagType::HTML:
    case TagType::HEAD:
    case TagType::BODY:
        // cout<<"Start"<<endl;
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout);
        }
        return;

    case TagType::P: {
        // cout<<"P"<<endl;
        QTextEdit* paragraphDisplay = new QTextEdit();
        paragraphDisplay->setReadOnly(true);
        paragraphDisplay->setPlainText(QString::fromStdString(node->getTextContent()));
        layout->addWidget(paragraphDisplay);
        return;
    }

    case TagType::TITLE:
        // cout<<"TITLE"<<endl;
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout);
        }
        return;

    case TagType::H1: {
        // cout<<"H1"<<endl;
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(18);
        headerLabel->setFont(font);
        layout->addWidget(headerLabel);
        return;
    }

    case TagType::DIV: {
        // cout<<"DIV"<<endl;
        QLabel* divLabel = new QLabel("Div Section:");
        layout->addWidget(divLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout);
        }
        return;
    }

    default:
        cout << "ERROR: Unknown tag type: " << node->getName() << endl;
        return;
    }
}

void renderDOMTree(DOMNode* root, QVBoxLayout* layout) {
    if (root == nullptr) {
        std::cout << "DOM root is null" << std::endl;
        return;
    }

    std::cout << "Rendering DOM Tree..." << std::endl;

    renderDOMNode(root, layout);

}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("DOM Browser");
    window.resize(700, 700);
    DOMNode* root = dom_creater_main();

    if (root == nullptr) {
        std::cerr << "Error: DOM root is null." << std::endl;
        return -1;
    } else {
        root->print();
    }

    QVBoxLayout* mainLayout = new QVBoxLayout(&window);

    renderDOMTree(root, mainLayout);

    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}
