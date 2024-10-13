
#include "dom_creater.h"
#include "dom_tree.h"

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

    case TagType::HEADER: {
        QLabel* headerLabel = new QLabel("Header:");
        layout->addWidget(headerLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout);
        }
        return;
    }

    case TagType::NAV: {
        QLabel* navLabel = new QLabel("Nav");
        layout->addWidget(navLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout);
        }
        return;
    }

    case TagType::SECTION: {
        QLabel* sectionLabel = new QLabel("Section:");
        layout->addWidget(sectionLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout);
        }
        return;
    }

    case TagType::STRONG: {
        QLabel* strongLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = strongLabel->font();
        font.setBold(true);
        strongLabel->setFont(font);
        layout->addWidget(strongLabel);
        return;
    }

    case TagType::EM: {
        QLabel* emLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = emLabel->font();
        font.setItalic(true);  // Make the text italic
        emLabel->setFont(font);
        layout->addWidget(emLabel);
        return;
    }

    case TagType::U: {
        QLabel* underlineLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = underlineLabel->font();
        font.setUnderline(true);  // Underline the text for <u>
        underlineLabel->setFont(font);
        layout->addWidget(underlineLabel);
        return;
    }
    case TagType::SMALL: {
        QLabel* smallLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = smallLabel->font();
        font.setPointSize(8);  // Set the font size smaller for <small>
        smallLabel->setFont(font);
        layout->addWidget(smallLabel);
        return;
    }
    case TagType::BLOCK_QUOTE: {
        QTextEdit* blockquoteDisplay = new QTextEdit();
        blockquoteDisplay->setReadOnly(true);
        blockquoteDisplay->setPlainText(QString::fromStdString(node->getTextContent()));
        blockquoteDisplay->setFrameStyle(QFrame::NoFrame);  // Disable the default frame/border
        blockquoteDisplay->setStyleSheet("background-color: #d3d3d3; padding: 10px;"); // No border
        blockquoteDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        int contentHeight = blockquoteDisplay->document()->size().height();
        blockquoteDisplay->setMinimumHeight(contentHeight + 20);
        layout->addWidget(blockquoteDisplay);
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
