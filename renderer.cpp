#include "dom_creater.h"
#include "dom_tree.h"
#include <QDesktopServices>
#include <QUrl>
#include <QFileInfo>
#include <QDir>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QScrollArea>
#include <iostream>


#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>

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

    case TagType::OL: {
        QListWidget* listWidget = new QListWidget();
        listWidget->setUniformItemSizes(true);
        layout->addWidget(listWidget);

        int itemNumber = 1;
        for (DOMNode* child : node->getChildren()) {
            TagType childTagType = getTagType(child->getName());
            if (childTagType == TagType::LI) {
                QString numberedItem = QString::number(itemNumber) + ". " + QString::fromStdString(child->getTextContent());
                QListWidgetItem* item = new QListWidgetItem(numberedItem);
                listWidget->addItem(item);
                itemNumber++;
            } else {
                cout << "ERROR: Expected <li> in <ol>, but found: " << child->getName() << endl;
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

    case TagType::PRE: {
        QTextEdit* textEdit = new QTextEdit();
        textEdit->setReadOnly(true);
        textEdit->setFontFamily("Courier");
        textEdit->setText(QString::fromStdString(node->getTextContent()));
        layout->addWidget(textEdit);
        return;
    }

    case TagType::CODE: {
        QLabel* codeLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont monospaceFont("Monospace");
        monospaceFont.setStyleHint(QFont::TypeWriter);
        codeLabel->setFont(monospaceFont);
        layout->addWidget(codeLabel);
        return;
    }

    case TagType::ARTICLE: {
        QLabel* articleLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(articleLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout); 
        }
        return;
    }

    case TagType::ASIDE: {
        QLabel* asideLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(asideLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout); 
        }
        return;
    }

    case TagType::FOOTER: {
        QLabel* footerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(footerLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout); 
        }
        return;
    }

case TagType::A: {
            QString href = QString::fromStdString(node->getAttribute("href"));
            QLabel* anchorLabel = new QLabel("<a href=\"" + href + "\">" + QString::fromStdString(node->getTextContent()) + "</a>");
            anchorLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
            anchorLabel->setOpenExternalLinks(false);  // Disable automatic opening

            // Click handling for both external and local links
            QObject::connect(anchorLabel, &QLabel::linkActivated, [href]() {
                QString formattedHref = href;
                // Check if it's an external URL or a local file
                if (!href.startsWith("http://") && !href.startsWith("https://")) {
                    if (href.contains(".")) {
                        // Assume it's an external link if there's a dot (.)
                        formattedHref = "http://" + href;
                    } else {
                        // Local link, open as a local file
                        QString localPath = QDir::currentPath() + "/" + href;
                        QFileInfo checkFile(localPath);
                        if (checkFile.exists() && checkFile.isFile()) {
                            QDesktopServices::openUrl(QUrl::fromLocalFile(localPath));
                            return;
                        } else {
                            std::cerr << "File does not exist: " << localPath.toStdString() << std::endl;
                            return;
                        }
                    }
                }
                // Open the external URL
                QDesktopServices::openUrl(QUrl(formattedHref));
            });

            layout->addWidget(anchorLabel);
            return;
        }

case TagType::IMG: {
    QString imgTag = QString::fromStdString(node->getTextContent());

    // Extract src
    int srcStart = imgTag.indexOf("src=\"") + 5;
    int srcEnd = imgTag.indexOf("\"", srcStart);
    QString src = srcStart > 4 ? imgTag.mid(srcStart, srcEnd - srcStart) : "";

    // Extract alt
    int altStart = imgTag.indexOf("alt=\"") + 5;
    int altEnd = imgTag.indexOf("\"", altStart);
    QString alt = altStart > 4 ? imgTag.mid(altStart, altEnd - altStart) : "No alt text";

    QLabel* imageLabel = new QLabel();
    QPixmap pixmap;

    // Load the image using the src
    if (src.startsWith("http://") || src.startsWith("https://")) {
        // For network images
        QNetworkAccessManager manager;
        QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(src)));
        QEventLoop loop;
        QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
        loop.exec();
        
        if (reply->error() == QNetworkReply::NoError) {
            pixmap.loadFromData(reply->readAll());
        }
        reply->deleteLater();
    } else {
        // Load from a local file
        pixmap.load(src);
    }

    if (pixmap.isNull()) {
        // If loading failed, display alt text or a placeholder
        QLabel* errorLabel = new QLabel(alt.isEmpty() ? "Image not found" : alt);
        errorLabel->setStyleSheet("background-color: #f0f0f0; padding: 5px; border: 1px solid #ccc;");
        layout->addWidget(errorLabel);
    } else {
        imageLabel->setPixmap(pixmap.scaled(400, 300, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        imageLabel->setToolTip(alt);
        layout->addWidget(imageLabel);
    }
    return;
}


    default:
        cout << "ERROR: Unknown tag type: " << node->getName() << endl;
        return;
    }
}

void renderDOMTree(DOMNode* root, QVBoxLayout* parentLayout) {
    if (root == nullptr) {
        std::cout << "DOM root is null" << std::endl;
        return;
    }

    std::cout << "Rendering DOM Tree..." << std::endl;

    // Create a widget to hold the DOM content
    QWidget* domContentWidget = new QWidget();
    QVBoxLayout* domContentLayout = new QVBoxLayout(domContentWidget);

    // Render the DOM inside the layout
    renderDOMNode(root, domContentLayout);

    // Add the scroll area
    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(domContentWidget);

    // Add the scroll area to the parent layout
    parentLayout->addWidget(scrollArea);
}
