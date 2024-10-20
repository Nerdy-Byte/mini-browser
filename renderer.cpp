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

std::string findTitle(DOMNode* node) {  // helper that finds the title of the webpage
    if (node == nullptr) return "";
    if (getTagType(node->getName()) == TagType::TITLE) {
        return node->getTextContent();
    }
    for (DOMNode* child : node->getChildren()) {
        std::string title = findTitle(child);
        if (!title.empty()) return title;
    }
    return "";
}


void renderDOMNode(DOMNode* node, QVBoxLayout* layout, QWidget* mainWindow) {
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
            renderDOMNode(child, layout, mainWindow);
        }
        return;

    case TagType::P: {
        QLabel* paragraphDisplay = new QLabel();
        paragraphDisplay->setText(QString::fromStdString(node->getTextContent()));
        paragraphDisplay->setWordWrap(true);  
        paragraphDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);          
        paragraphDisplay->adjustSize();  // Adjust the size to fit the text content
        layout->addWidget(paragraphDisplay);
        return;
    }

    case TagType::TITLE: { // title tag is handled separately
        return;
    }

    case TagType::H1: {
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(18);  // H1 size
        headerLabel->setFont(font);        
        headerLabel->setStyleSheet("margin-top: 5px; margin-bottom: 10px;");        
        headerLabel->adjustSize();  
        layout->addWidget(headerLabel);
        return;
    }

    case TagType::H2: {
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(16);  // H2 size
        headerLabel->setFont(font);        
        headerLabel->setStyleSheet("margin-top: 8px; margin-bottom: 8px;");        
        headerLabel->adjustSize();  
        layout->addWidget(headerLabel);
        return;
    }

    case TagType::H3: {
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(14);  // H3 size
        headerLabel->setFont(font);        
        headerLabel->setStyleSheet("margin-top: 6px; margin-bottom: 6px;");        
        headerLabel->adjustSize();  
        layout->addWidget(headerLabel);
        return;
    }

    case TagType::H4: {
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(12);  // H4 size
        headerLabel->setFont(font);        
        headerLabel->setStyleSheet("margin-top: 4px; margin-bottom: 4px;");        
        headerLabel->adjustSize();  
        layout->addWidget(headerLabel);
        return;
    }

    case TagType::H5: {
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        QFont font = headerLabel->font();
        font.setPointSize(10);  // H5 size
        headerLabel->setFont(font);        
        headerLabel->setStyleSheet("margin-top: 2px; margin-bottom: 2px;");        
        headerLabel->adjustSize();  
        layout->addWidget(headerLabel);
        return;
    }

    case TagType::DIV: {
        // cout<<"DIV"<<endl;
        QLabel* divLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(divLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout);
        }
        return;
    }
    case TagType::UL: {
        QVBoxLayout* listLayout = new QVBoxLayout();  // new layout for the list
        listLayout->setContentsMargins(20, 0, 0, 10);

        for (DOMNode* child : node->getChildren()) {
            TagType childTagType = getTagType(child->getName());
            if (childTagType == TagType::LI) {
                // Create a new layout for each list item
                QVBoxLayout* listItemLayout = new QVBoxLayout();
                listItemLayout->setContentsMargins(0, 0, 0, 5);  // Spacing between list items

                // Render the contents of the list item, including nested <a> tags
                for (DOMNode* grandChild : child->getChildren()) {
                    renderDOMNode(grandChild, listItemLayout);
                }

                listLayout->addLayout(listItemLayout);  // Add each list item layout to the main list layout
            } else {
                cout << "ERROR: Expected <li> in <ul>, but found: " << child->getName() << endl;
            }
        }
        layout->addLayout(listLayout);
        return;
    }

    case TagType::OL: {
        QVBoxLayout* listLayout = new QVBoxLayout();
        listLayout->setContentsMargins(20, 0, 0, 10);
        int itemNumber = 1;  // Start numbering from 1

        for (DOMNode* child : node->getChildren()) {
            TagType childTagType = getTagType(child->getName());
            if (childTagType == TagType::LI) {
                // Create a new layout for each numbered list item
                QVBoxLayout* listItemLayout = new QVBoxLayout();
                listItemLayout->setContentsMargins(0, 0, 0, 5);  // Spacing between list items

                // Render the contents of the list item, including nested <a> tags
                QLabel* numberedLabel = new QLabel(QString::number(itemNumber) + ". ");
                listItemLayout->addWidget(numberedLabel);

                for (DOMNode* grandChild : child->getChildren()) {
                    renderDOMNode(grandChild, listItemLayout);  // Render child content (including <a> tags)
                }

                listLayout->addLayout(listItemLayout);  // Add each list item layout to the main list layout
                itemNumber++;  // Increment the list number
            } else {
                cout << "ERROR: Expected <li> in <ol>, but found: " << child->getName() << endl;
            }
        }
        layout->addLayout(listLayout);
        return;
    }

    case TagType::HEADER: {
        QLabel* headerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(headerLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout);
        }
        return;
    }

    case TagType::NAV: {
        QLabel* navLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(navLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout);
        }
        return;
    }

    case TagType::SECTION: {
        QLabel* sectionLabel = new QLabel(QString::fromStdString(node->getTextContent()));
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
        QLabel* blockquoteDisplay = new QLabel(QString::fromStdString(node->getTextContent()));
        blockquoteDisplay->setWordWrap(true);  
        blockquoteDisplay->setFrameStyle(QFrame::NoFrame); 
        blockquoteDisplay->setStyleSheet("background-color: #d3d3d3; padding: 10px; margin-bottom: 10px;");
        blockquoteDisplay->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        QSize contentSize = blockquoteDisplay->sizeHint();
        blockquoteDisplay->setFixedHeight(contentSize.height() + 10);  
        layout->addWidget(blockquoteDisplay);
        return;
    }

   case TagType::PRE: {
        QTextEdit* textEdit = new QTextEdit();
        textEdit->setReadOnly(true);
        textEdit->setFontFamily("Courier");  // Monospace font for preformatted text

        QString content = QString::fromStdString(node->getTextContent()).trimmed();
        textEdit->setPlainText(content);    
        textEdit->setFrameStyle(QFrame::NoFrame);    
        textEdit->setStyleSheet("background: transparent; margin: 0px; padding: 0px;");    
        textEdit->setContentsMargins(0, 0, 0, 0);
        textEdit->document()->setDocumentMargin(0);

        // resize based on content
        textEdit->document()->setTextWidth(textEdit->viewport()->width());
        int contentHeight = textEdit->document()->size().height();
        textEdit->setFixedHeight(contentHeight); 

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
                // Check for external URL or local file
                if (!href.startsWith("http://") && !href.startsWith("https://")) {
                    if (href.contains(".")) {
                        // Assuming it's an external link if there's a dot (.)
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

    // Load image using src
    if (src.startsWith("http://") || src.startsWith("https://")) {
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
        // loading failed display alt text or a placeholder
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

    // Find title
    std::string title = findTitle(root);
    QLabel* titleLabel = new QLabel(QString::fromStdString(title));
    titleLabel->setStyleSheet("font-weight: bold; font-size: 14px;");
    parentLayout->addWidget(titleLabel);
    QWidget* domContentWidget = new QWidget();
    QVBoxLayout* domContentLayout = new QVBoxLayout(domContentWidget);

    // parent widget (main window)
    QWidget* mainWindow = parentLayout->parentWidget()->window();

    // Render the DOM inside the layout passing the main window
    renderDOMNode(root, domContentLayout, mainWindow);

    // scroll bar
    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(domContentWidget);

    parentLayout->addWidget(scrollArea);
}