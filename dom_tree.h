#ifndef DOM_TREE_H
#define DOM_TREE_H

#include <iostream>
#include <vector>
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
    ERROR
};


inline std::string tagTypeToString(TagType tagType) {
    switch (tagType) {
    case TagType::HTML: return "html";
    case TagType::HEAD: return "head";
    case TagType::TITLE: return "title";
    case TagType::BODY: return "body";
    case TagType::DIV: return "div";
    case TagType::P: return "p";
    case TagType::H1: return "h1";
    case TagType::ROOT: return "root";
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

    DOMNode(DOMNode&& other) noexcept : tag(std::move(other.tag)), content(std::move(other.content)), children(std::move(other.children)) {
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
            other.children.clear();
        }
        return *this;
    }

    void appendChildren(const std::vector<DOMNode*>& childList) {
        children.insert(children.end(), childList.begin(), childList.end());
    }

    void print(int depth = 0) const {
        std::cout << std::string(depth * 2, ' ');
        std::cout << tag << std::endl;

        for (const auto* child : children) {
            child->print(depth + 1);
        }
    }

    const std::string& getName() const {
        return tag;
    }

    const std::string& getTextContent() const {
        return content;
    }

    const std::vector<DOMNode*>& getChildren() const {
        return children;
    }

private:
    std::string tag;
    std::string content;
    std::vector<DOMNode*> children;
};

typedef std::vector<DOMNode*> DOMNodeList;

#endif
