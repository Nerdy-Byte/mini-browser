#ifndef DOM_CREATER_H
#define DOM_CREATER_H

#include <QApplication>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QListWidget>
#include <QTabWidget>
#include <string>
#include <cstdlib>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QObject>
#include <QString>

#include "dom_tree.h"

/**
 * @brief Creates a DOM tree from an HTML string.
 *
 * This function takes an HTML string as input and processes it to create a corresponding DOM tree structure.
 * The tree is represented as a hierarchy of DOMNode objects.
 *
 * @param input The HTML content as a string.
 * @return A pointer to the root node of the generated DOM tree.
 */

DOMNode* dom_creater_main(char*);

/**
 * @brief Creates a DOM tree from a file.
 *
 * This function creates a DOM tree from an HTML file specified by the file path.
 * It reads the file content and parses it into a DOM tree.
 *
 * @param filePath The file path to the HTML content.
 * @return A pointer to the root node of the generated DOM tree.
 */

DOMNode* dom_creater_string(const std::string& input);

/**
 * @brief Renders a single DOM node into the given layout.
 *
 * This function is responsible for rendering a DOM node into a specific layout in the GUI. It takes the node,
 * processes its content, and adds it to the provided layout. Optionally, a main window can be provided.
 *
 * @param node A pointer to the DOM node to render.
 * @param layout A pointer to the QVBoxLayout where the node's content will be added.
 * @param mainWindow (Optional) A pointer to the main window (default is nullptr).
 */

void renderDOMNode(DOMNode* node, QVBoxLayout* layout, QWidget* mainWindow = nullptr);

/**
 * @brief Renders the entire DOM tree into a layout.
 *
 * This function is responsible for rendering the entire DOM tree into the given layout. It processes the root
 * node and adds each node's content to the layout, setting up a scrollable area for the rendered content.
 *
 * @param root A pointer to the root node of the DOM tree to render.
 * @param layout A pointer to the parent QVBoxLayout where the content will be displayed.
 * @param tabWidget A pointer to the QTabWidget used to manage different content tabs.
 */

void renderDOMTree(DOMNode* root, QVBoxLayout* layout, QTabWidget* tabWidget);

/**
 * @brief Finds the title of a DOM node.
 *
 * This function attempts to extract the title from a given DOM node, typically from the <title> tag in an HTML document.
 * If no title is found, it returns an empty string.
 *
 * @param node A pointer to the DOM node where the title is to be found.
 * @return A string containing the title of the node, or an empty string if no title is found.
 */

std::string findTitle(DOMNode* node);

// HtmlFetcher class to fetch HTML content
/**
 * @brief A class that fetches HTML content from a URL.
 *
 * This class provides methods to asynchronously or synchronously fetch HTML content from a specified URL.
 * The asynchronous method uses signals and slots, while the synchronous method returns the HTML content as a string.
 */

class HtmlFetcher : public QObject {
    Q_OBJECT

public:
    HtmlFetcher(const QString& url)
        : m_url(url) {}

    void fetchAsync() {
        QNetworkAccessManager* manager = new QNetworkAccessManager(this);
        QObject::connect(manager, &QNetworkAccessManager::finished, this, &HtmlFetcher::onFetchFinished);
        manager->get(QNetworkRequest(QUrl(m_url)));
    }

    std::string fetchSync() {
        QNetworkAccessManager manager;
        QEventLoop loop;

        // Connect manager's finished signal to the event loop's quit slot
        QObject::connect(&manager, &QNetworkAccessManager::finished, &loop, &QEventLoop::quit);

        // Make the request
        QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(m_url)));
        loop.exec(); // Wait for the request to finish

        // Handle the reply
        if (reply->error() != QNetworkReply::NoError) {
            QString error = reply->errorString();
            reply->deleteLater();
            throw std::runtime_error(error.toStdString());
        }

        QString htmlContent = reply->readAll();
        reply->deleteLater();
        return htmlContent.toStdString(); // Convert to std::string
    }


signals:
    void fetchFinished(const QString& content);
    void errorOccurred(const QString& error);

private slots:
    void onFetchFinished(QNetworkReply* reply) {
        if (reply->error() != QNetworkReply::NoError) {
            emit errorOccurred(reply->errorString());
            reply->deleteLater();
            return;
        }

        QString htmlContent = reply->readAll();
        reply->deleteLater();
        emit fetchFinished(htmlContent);
    }

private:
    QString m_url;
};

// HtmlParser class to parse HTML content into a DOM tree
/**
 * @brief A class to parse HTML content into a DOM tree.
 *
 * This class provides methods to parse HTML content into a DOM tree structure. It supports both asynchronous
 * and synchronous parsing.
 */

class HtmlParser : public QObject {
    Q_OBJECT

public:
    HtmlParser(const std::string& html_content)
        : m_html_content(QString::fromStdString(html_content)) {} // Convert std::string to QString

    void parseAsync() {
        DOMNode* root = dom_creater_string(m_html_content.toStdString());
        if (!root) {
            emit parsingFinished(nullptr, "");
            return;
        }

        std::string titleText = findTitle(root);
        emit parsingFinished(root, titleText);
    }

    std::pair<DOMNode*, std::string> parseSync() {
        DOMNode* root = dom_creater_string(m_html_content.toStdString());
        if (!root) {
            throw std::runtime_error("Failed to parse HTML content.");
        }

        std::string titleText = findTitle(root);
        return {root, titleText};
    }

signals:
    void parsingFinished(DOMNode* root, const std::string& titleText);

private:
    QString m_html_content;
};


// HtmlRenderer class to render the DOM tree into the GUI
/**
 * @brief A class to render the DOM tree into a GUI layout.
 *
 * This class is responsible for rendering the DOM tree into a specific tab within a QTabWidget. It processes
 * the DOM tree and renders it into a QVBoxLayout, updating the tab with the title text.
 */


class HtmlRenderer : public QObject {
    Q_OBJECT

public:
    HtmlRenderer(QTabWidget* tabWidget, int tabIndex)
        : m_tabWidget(tabWidget), m_tabIndex(tabIndex) {}

    void render(DOMNode* root, const std::string& titleText) {
        QWidget* targetTab = m_tabWidget->widget(m_tabIndex);
        if (targetTab) {
            QVBoxLayout* tabLayout = qobject_cast<QVBoxLayout*>(targetTab->layout());
            if (tabLayout) {
                // Clear the previous content
                QLayoutItem* item;
                while ((item = tabLayout->takeAt(0)) != nullptr) {
                    delete item->widget();
                    delete item;
                }

                // Render the DOM tree
                renderDOMTree(root, tabLayout, m_tabWidget);

                // Set the tab name
                QString tabName = QString::fromStdString(titleText.empty() ? "Untitled" : titleText);
                m_tabWidget->setTabText(m_tabIndex, tabName);
            }
        }
    }

private:
    QTabWidget* m_tabWidget;
    int m_tabIndex;
};

#endif
