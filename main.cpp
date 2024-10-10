#include <QApplication>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QListWidget>
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
        paragraphDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        int contentHeight = paragraphDisplay->document()->size().height();
        paragraphDisplay->setMinimumHeight(contentHeight + 10);
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

    case TagType::H2: {
        // cout<<"H1"<<endl;
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(16);
        headerLabel->setFont(font);
        layout->addWidget(headerLabel);
        return;
    }

    case TagType::H3: {
        // cout<<"H1"<<endl;
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(14);
        headerLabel->setFont(font);
        layout->addWidget(headerLabel);
        return;
    }

    case TagType::H4: {
        // cout<<"H1"<<endl;
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(12);
        headerLabel->setFont(font);
        layout->addWidget(headerLabel);
        return;
    }

    case TagType::H5: {
        // cout<<"H1"<<endl;
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(10);
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

    case TagType::UL: {
        QListWidget* listWidget = new QListWidget();
        layout->addWidget(listWidget);
        for (DOMNode* child : node->getChildren()) {
            TagType childTagType = getTagType(child->getName());
            if (childTagType == TagType::LI) {
                QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(child->getTextContent()));
                listWidget->addItem(item);
            } else {
                cout << "ERROR: Expected <li> in <ul>, but found: " << child->getName() << endl;
            }
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
