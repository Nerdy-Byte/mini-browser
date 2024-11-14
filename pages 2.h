#ifndef PAGES_H
#define PAGES_H

#include <string>
#include "dom_creater.h"

class Page_node {
private:
    std::string html;     // Stores the HTML content of the page
    DOMNode* dom_root;    // DOM structure of the page
    Page_node* left;      // Points to the previous page (backward navigation)
    Page_node* right;     // Points to the next page (forward navigation)

public:
    // Constructor to initialize a page node with HTML content
    Page_node(const std::string& html_input) {
        html = html_input;
        dom_root = nullptr;
        left = nullptr;
        right = nullptr;
    }

    // Function to set the DOM structure (e.g., after parsing)
    void setDOM(DOMNode* dom) {
        dom_root = dom;
    }

    // Function to get the DOM structure of the page
    DOMNode* getDOM() const {
        return dom_root;
    }

    // Getter for HTML content
    std::string getHTML() const {
        return html;
    }

    // Set the previous page (backward navigation)
    void setLeft(Page_node* prev) {
        left = prev;
    }

    // Set the next page (forward navigation)
    void setRight(Page_node* next) {
        right = next;
    }

    // Get the previous page (for back navigation)
    Page_node* getLeft() const {
        return left;
    }

    // Get the next page (for forward navigation)
    Page_node* getRight() const {
        return right;
    }

    // Navigate backward in the history (returns the previous page)
    Page_node* navigateBack() const {
        if (left) {
            return left;
        } else {
            std::cerr << "No previous page to navigate back to." << std::endl;
            return nullptr;
        }
    }

    // Navigate forward in the history (returns the next page)
    Page_node* navigateForward() const {
        if (right) {
            return right;
        } else {
            std::cerr << "No next page to navigate forward to." << std::endl;
            return nullptr;
        }
    }
};


//this class is used navigate inside the tab

class Tab {
private:
    Page_node* head;      // Points to the current page node
    Page_node* current;   // Points to the currently active page node

public:
    // Constructor for a new tab (head and current are null initially)
    Tab() {
        head = nullptr;
        current = nullptr;
    }

    // Load a new page into the tab (this creates a new Page_node and links it)
    void loadPage(const std::string& html) {
        Page_node* new_page = new Page_node(html);

        if (head == nullptr) {
            // First page in the tab
            head = new_page;
            current = head;
        } else {
            // Link the current page to the new page (forward)
            current->setRight(new_page);
            new_page->setLeft(current);
            current = new_page; // Move to the new page
        }
    }

    // Navigate back (if possible)
    void back() {
        Page_node* prev = current->getLeft();
        if (prev) {
            current = prev;
            std::cout << "Navigated back to previous page." << std::endl;
        }
    }

    // Navigate forward (if possible)
    void forward() {
        Page_node* next = current->getRight();
        if (next) {
            current = next;
            std::cout << "Navigated forward to next page." << std::endl;
        }
    }

    // Get the current page DOM
    DOMNode* getCurrentDOM() {
        if (current) {
            return current->getDOM();
        } else {
            return nullptr;
        }
    }

    // Get the current HTML content
    std::string getCurrentHTML() {
        if (current) {
            return current->getHTML();
        } else {
            return "";
        }
    }
};

#endif // PAGES_H
