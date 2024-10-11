#ifndef DOM_TREE_H
#define DOM_TREE_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

// Enumeration for HTML tags
enum TagType {
    ROOT,
    HTML,
    HEAD,
    TITLE,
    BODY,
    DIV,
    P,
    H1,
    H2,
    H3,
    H4,
    H5,
    SECTION,
    ARTICLE,
    ASIDE,
    IMG,
    A,
    STRONG,
    EM,
    U,
    SMALL,
    BLOCK_QUOTE,
    PRE,
    CODE,
    NAV,
    OL,
    UL,
    LI,
    HEADER,
    FOOTER,
    ERROR
};


inline std::string tagTypeToString(TagType tagType) {
    switch (tagType) {
    case TagType::HTML: return "html";
    case TagType::HEAD: return "head";
    case TagType::TITLE: return "title";
    case TagType::BODY: return "body";
    case TagType::NAV: return "nav";
    case TagType::DIV: return "div";
    case TagType::P: return "p";
    case TagType::H1: return "h1";
    case TagType::ROOT: return "root";
    case TagType::H2: return "h2";
    case TagType::H3: return "h3";
    case TagType::H4: return "h4";
    case TagType::H5: return "h5";
    case TagType::SECTION: return "section";
    case TagType::EM: return "em";
    case TagType::ARTICLE: return "article";
    case TagType::ASIDE: return "side";
    case TagType::IMG: return "img";
    case TagType::A: return "a";
    case TagType::STRONG: return "strong";
    case TagType::BLOCK_QUOTE: return "block_quote";
    case TagType::U: return "u";
    case TagType::SMALL: return "small";
    case TagType::PRE: return "pre";
    case TagType::OL: return "ol";
    case TagType::UL: return "ul";
    case TagType::LI: return "li";
    case TagType::HEADER: return "header";
    case TagType::FOOTER: return "footer";


    default: return "unknown";
    }
}

inline TagType getTagType(const std::string& tagName) {
    if (tagName == "html") return TagType::HTML;
    if (tagName == "head") return TagType::HEAD;
    if (tagName == "title") return TagType::TITLE;
    if (tagName == "body") return TagType::BODY;
    if (tagName == "div") return TagType::DIV;
    if (tagName == "p") return TagType::P;
    if (tagName == "h1") return TagType::H1;
    if (tagName == "h2") return TagType::H2;
    if (tagName == "h3") return TagType::H3;
    if (tagName == "h4") return TagType::H4;
    if (tagName == "h5") return TagType::H5;
    if (tagName == "section") return TagType::SECTION;
    if (tagName == "article") return TagType::ARTICLE;
    if (tagName == "aside") return TagType::ASIDE;
    if (tagName == "img") return TagType::IMG;
    if (tagName == "a") return TagType::A;
    if (tagName == "strong") return TagType::STRONG;
    if (tagName == "em") return TagType::EM;
    if (tagName == "u") return TagType::U;
    if (tagName == "small") return TagType::SMALL;
    if (tagName == "block_quote") return TagType::BLOCK_QUOTE;
    if (tagName == "pre") return TagType::PRE;
    if (tagName == "code") return TagType::CODE;
    if (tagName == "nav") return TagType::NAV;
    if (tagName == "ol") return TagType::OL;
    if (tagName == "ul") return TagType::UL;
    if (tagName == "li") return TagType::LI;
    if (tagName == "header") return TagType::HEADER;
    if (tagName == "footer") return TagType::FOOTER;
    if (tagName == "root") return TagType::ROOT;

    return TagType::ERROR;
}


class DOMNode {
public:
    DOMNode(TagType t) : tag(tagTypeToString(t)), content("") {}
    DOMNode(TagType t, const std::string& c) : tag(tagTypeToString(t)), content(c) {}

    ~DOMNode() {
        for (auto* child : children) {
            delete child;
        }
    }

    DOMNode(const DOMNode&) = delete;
    DOMNode& operator=(const DOMNode&) = delete;

    DOMNode(DOMNode&& other) noexcept : tag(std::move(other.tag)), content(std::move(other.content)), children(std::move(other.children)), attributes(std::move(other.attributes)) {
        other.children.clear();
    }

    DOMNode& operator=(DOMNode&& other) noexcept {
        if (this != &other) {
            for (auto* child : children) {
                delete child;
            }
            tag = std::move(other.tag);
            content = std::move(other.content);
            children = std::move(other.children);
            attributes = std::move(other.attributes);
            other.children.clear();
        }
        return *this;
    }

    // Method to append children nodes
    void appendChildren(const std::vector<DOMNode*>& childList) {
        children.insert(children.end(), childList.begin(), childList.end());
    }

    // Method to set an attribute
    void setAttribute(const std::string& name, const std::string& value) {
        attributes[name] = value;
    }

    // Method to get an attribute
    std::string getAttribute(const std::string& name) const {
        auto it = attributes.find(name);
        if (it != attributes.end()) {
            return it->second;
        }
        return "";
    }

    // Method to print the DOM tree (recursive)
    void print(int depth = 0) const {
        std::cout << std::string(depth * 2, ' ');
        std::cout << tag;
        if (!content.empty()) {
            std::cout << ": " << content;
        }

        // Print attributes
        for (const auto& [key, value] : attributes) {
            std::cout << " (" << key << "=\"" << value << "\")";
        }
        std::cout << std::endl;

        for (const auto* child : children) {
            child->print(depth + 1);
        }
    }

    // Getter for the tag name
    const std::string& getName() const {
        return tag;
    }

    // Getter for the text content
    const std::string& getTextContent() const {
        return content;
    }

    // Getter for child nodes
    const std::vector<DOMNode*>& getChildren() const {
        return children;
    }

private:
    std::string tag;  // Tag name (e.g., "p", "img")
    std::string content;  // Text content of the node
    std::vector<DOMNode*> children;  // Children of this node
    std::map<std::string, std::string> attributes;  // Attributes (e.g., src for img, href for a)
};

typedef std::vector<DOMNode*> DOMNodeList;


#endif
