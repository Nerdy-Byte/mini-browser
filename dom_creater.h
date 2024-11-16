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
    #include <QObject>
    #include <QString>

    #include "dom_tree.h"
    DOMNode* dom_creater_main(char*);
    DOMNode* dom_creater_string(const std::string& input);

    void renderDOMNode(DOMNode* node, QVBoxLayout* layout, QWidget* mainWindow = nullptr);
    void renderDOMTree(DOMNode* root, QVBoxLayout* layout, QTabWidget* tabWidget);
    std::string findTitle(DOMNode* node);

    //fetch the
    class HtmlFetcher : public QObject {
        Q_OBJECT

    public:
        HtmlFetcher(const QString& url, QTabWidget* tabWidget, int tabIndex)
            : m_url(url), m_tabWidget(tabWidget), m_tabIndex(tabIndex) {}

        void fetch() {
            QNetworkAccessManager* manager = new QNetworkAccessManager(this);
            QObject::connect(manager, &QNetworkAccessManager::finished, this, &HtmlFetcher::onFetchFinished);
            manager->get(QNetworkRequest(QUrl(m_url)));
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

            QString html_content = reply->readAll();
            reply->deleteLater();
            emit fetchFinished(html_content);
        }

    private:
        QString m_url;
        QTabWidget* m_tabWidget;
        int m_tabIndex;
    };



    class HtmlParser : public QObject {
        Q_OBJECT

    public:
        HtmlParser(const QString& html_content)
            : m_html_content(html_content) {}

        void parse() {
            DOMNode* root = dom_creater_string(m_html_content.toStdString());
            if (!root) {
                emit parsingFinished(nullptr, "");
                return;
            }

            std::string titleText = findTitle(root);
            emit parsingFinished(root, titleText);
        }

    signals:
        void parsingFinished(DOMNode* root, const std::string& titleText);

    private:
        QString m_html_content;
    };



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
