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

#include <omp.h>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>

using namespace std;

/**
 * @brief Finds the title of the webpage within the DOM tree.
 *
 * This helper function searches through the DOM tree to find the <title> tag and
 * returns its content as a string. The search is performed recursively through
 * the child nodes of the given DOM node.
 *
 * @param node A pointer to the current DOM node to start the search.
 *
 * @return The content of the <title> tag as a string. If no title tag is found,
 *         an empty string is returned.
 */

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


/**
 * @brief Recursively renders the DOM tree into a GUI layout.
 *
 * This function processes a DOMNode and renders it into a GUI layout using QVBoxLayout.
 * It handles different tag types (e.g., paragraphs, headers, divs, etc.) and processes
 * their children recursively. Depending on the tag type, the node is displayed with
 * appropriate formatting (e.g., paragraphs with text, headers with varying font sizes).
 * The function also skips rendering certain tags like <title> which are handled separately.
 *
 * @param node A pointer to the current DOM node to render.
 * @param layout A pointer to the QVBoxLayout where the rendered content is added.
 * @param mainWindow A pointer to the main QWidget window for GUI management.
 * @param tabWidget A pointer to the QTabWidget, used for managing tabs if applicable.
 *
 * @note This function does not return any value and performs the rendering directly to the GUI.
 */


void renderDOMNode(DOMNode* node, QVBoxLayout* layout, QWidget* mainWindow, QTabWidget* tabWidget) {
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
            renderDOMNode(child, layout, mainWindow, tabWidget);
        }
        return;

    case TagType::P: {
        QString paraText;
        // Loop through the children of the paragraph node and render inline elements
        for (DOMNode* child : node->getChildren()) {
            TagType childTagType = getTagType(child->getName());

            switch (childTagType) {
                case TagType::STRONG:
                    paraText += "<strong>" + QString::fromStdString(child->getTextContent()) + "</strong>";
                    break;
                case TagType::EM:
                    paraText += "<em>" + QString::fromStdString(child->getTextContent()) + "</em>";
                    break;
                case TagType::U:
                    paraText += "<u>" + QString::fromStdString(child->getTextContent()) + "</u>";
                    break;
                case TagType::SMALL:
                    paraText += "<small>" + QString::fromStdString(child->getTextContent()) + "</small>";
                    break;
                default:
                    // Render normal text content
                    paraText += QString::fromStdString(child->getTextContent());
                    break;
            }
        }

        QLabel* paraLabel = new QLabel();
        paraLabel->setText(paraText);
        paraLabel->setWordWrap(true);
        layout->addWidget(paraLabel);
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
            renderDOMNode(child, layout, mainWindow, tabWidget);
        }
        return;
    }
    case TagType::UL: {
        QVBoxLayout* listLayout = new QVBoxLayout();  
        listLayout->setContentsMargins(20, 0, 0, 10);  

        for (DOMNode* child : node->getChildren()) {
            TagType childTagType = getTagType(child->getName());

            if (childTagType == TagType::LI) {
                QHBoxLayout* listItemLayout = new QHBoxLayout();
                listItemLayout->setContentsMargins(0, 0, 0, 5);  

                // Add bullet point
                QLabel* bulletLabel = new QLabel("•");
                bulletLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);  
                listItemLayout->addWidget(bulletLabel);  

                QVBoxLayout* listItemContentLayout = new QVBoxLayout();

                for (DOMNode* grandChild : child->getChildren()) {
                    renderDOMNode(grandChild, listItemContentLayout, mainWindow, tabWidget);  
                }

                listItemLayout->addLayout(listItemContentLayout);  
                listLayout->addLayout(listItemLayout);  
            } else {
                cout << "ERROR: Expected <li> in <ul>, but found: " << child->getName() << endl;
            }
        }

        layout->addLayout(listLayout);  // Add the entire list layout to the main layout
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
                    renderDOMNode(grandChild, listItemLayout, mainWindow, tabWidget);  // Render child content (including <a> tags)
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
            renderDOMNode(child, layout, mainWindow, tabWidget);
        }
        return;
    }

    case TagType::NAV: {
        QLabel* navLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(navLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout, mainWindow, tabWidget);
        }
        return;
    }

    case TagType::SECTION: {
        QLabel* sectionLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(sectionLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout, mainWindow, tabWidget);
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
            renderDOMNode(child, layout, mainWindow, tabWidget); 
        }
        return;
    }

    case TagType::ASIDE: {
        QLabel* asideLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(asideLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout, mainWindow, tabWidget); 
        }
        return;
    }

    case TagType::FOOTER: {
        QLabel* footerLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        layout->addWidget(footerLabel);
        for (DOMNode* child : node->getChildren()) {
            renderDOMNode(child, layout, mainWindow, tabWidget); 
        }
        return;
    }
    
    case TagType::A: {
        QString href = QString::fromStdString(node->getAttribute("href"));
        QLabel* anchorLabel = new QLabel("<a href=\"" + href + "\">" + QString::fromStdString(node->getTextContent()) + "</a>");
        anchorLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
        anchorLabel->setOpenExternalLinks(false);  // Disable automatic opening

        QObject::connect(anchorLabel, &QLabel::linkActivated, [href, tabWidget, mainWindow]() {
            if (href.startsWith("http://") || href.startsWith("https://")) {
                // External link: Open in system's default web browser
                QDesktopServices::openUrl(QUrl(href));
            } else {
                // Internal link handling
                QString localPath = QDir::currentPath() + "/" + href;

                // Check if the tab already exists
                bool tabFound = false;
                for (int i = 0; i < tabWidget->count(); i++) {
                    if (tabWidget->tabText(i) == href) {  // Use the href as tab name for simplicity
                        tabWidget->setCurrentIndex(i);
                        tabFound = true;
                        break;
                    }
                }

                if (!tabFound) {
                    // Fetch and create a new tab for the internal link
                    QString url = "http://localhost:8000/" + href;  // Assume localhost serves the internal files
                    QNetworkAccessManager* manager = new QNetworkAccessManager(mainWindow);

                    QObject::connect(manager, &QNetworkAccessManager::finished, [tabWidget, href](QNetworkReply* reply) {
                        if (reply->error() != QNetworkReply::NoError) {
                            std::cerr << "Error fetching URL: " << reply->errorString().toStdString() << std::endl;
                            reply->deleteLater();
                            return;
                        }

                        QString html_content = reply->readAll();
                        reply->deleteLater();

                        DOMNode* root = dom_creater_string(html_content.toStdString());
                        if (!root) return;

                        // Extract the title from the newly loaded page content
                        std::string titleText = findTitle(root);

                        QWidget* tab = new QWidget();
                        QVBoxLayout* tabLayout = new QVBoxLayout(tab);
                        renderDOMTree(root, tabLayout, tabWidget);  
                        tab->setLayout(tabLayout);

                        // Set the tab name based on the extracted title, or use the href as a fallback
                        QString tabTitle = QString::fromStdString(titleText.empty() ? href.toStdString() : titleText);
                        tabWidget->addTab(tab, tabTitle);
                        tabWidget->setCurrentWidget(tab);  // Switch to the new tab
                    });

                    manager->get(QNetworkRequest(QUrl(url)));
                }
            }
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

    case TagType::TXT: {
        QLabel* textLabel = new QLabel(QString::fromStdString(node->getTextContent()));
        textLabel->setWordWrap(true);  // Enable word wrapping for long text
        layout->addWidget(textLabel);
        return;
    }


    default:
        cout << "ERROR: Unknown tag type: " << node->getName() << endl;
        return;
    }
}

/**
 * @brief Renders the entire DOM tree into a GUI layout.
 *
 * This function is responsible for rendering the full DOM tree, starting from the root node. It sets up
 * the necessary widgets and layouts, including a scrollable area for the content. The function begins by
 * finding the title of the page (if available) and then processes the root DOM node using the `renderDOMNode`
 * function to render the content into a `QVBoxLayout`.
 *
 * The rendered DOM tree is displayed in a scrollable area that is added to the parent layout. The layout is
 * intended to be used in the main window of the application, and the rendering is done in a single thread.
 *
 * @param root A pointer to the root node of the DOM tree to render.
 * @param parentLayout A pointer to the parent QVBoxLayout where the scrollable content will be added.
 * @param tabWidget A pointer to the QTabWidget used to manage different content tabs, if applicable.
 *
 * @note The function handles the creation of necessary GUI elements (widgets, layouts, scroll area) and starts
 *       the rendering process for the DOM tree.
 */

void renderDOMTree(DOMNode* root, QVBoxLayout* parentLayout, QTabWidget* tabWidget) {
    if (root == nullptr) {
        std::cout << "DOM root is null" << std::endl;
        return;
    }
    std::cout << "Rendering DOM Tree..." << std::endl;

    std::string title = findTitle(root);
    QWidget* domContentWidget = new QWidget();
    QVBoxLayout* domContentLayout = new QVBoxLayout(domContentWidget);

    // parent widget (main window)
    QWidget* mainWindow = parentLayout->parentWidget()->window();

    // Scroll area setup
    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(domContentWidget);
    parentLayout->addWidget(scrollArea);

    // Start rendering the root node with the layout and main window (single thread)
    renderDOMNode(root, domContentLayout, mainWindow, tabWidget);
}

