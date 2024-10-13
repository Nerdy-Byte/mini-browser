
#include "dom_creater.h"

using namespace std;



int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("DOM Browser");
    window.resize(700, 700);
    DOMNode* root = dom_creater_main("/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/input.html");

    if (root == nullptr) {
        std::cerr << "Error: DOM root is null." << std::endl;
        return -1;
    } else {
        root->print();
    }

    QTabWidget* tabWidget = new QTabWidget(&window);
    QWidget* tab1 = new QWidget();
    QVBoxLayout* tabLayout1 = new QVBoxLayout(tab1);
    renderDOMTree(root, tabLayout1);
    tab1->setLayout(tabLayout1);
    tabWidget->addTab(tab1, "DOM View");

    // QWidget* tab2 = new QWidget();
    // QVBoxLayout* tabLayout2 = new QVBoxLayout(tab2);
    // tab2->setLayout(tabLayout2);
    // tabWidget->addTab(tab2, "Another View");

    QVBoxLayout* mainLayout = new QVBoxLayout(&window);
    mainLayout->addWidget(tabWidget);

    window.setLayout(mainLayout);
    window.show();

    return app.exec();
}
