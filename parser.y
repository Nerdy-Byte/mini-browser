%{
    #include <cstring>
    #include "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/dom_tree.h"
    #include "parser.tab.h"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(const char *s);
    using namespace std;
    DOMNode* root = nullptr;
%}

%union {
    DOMNode* domNode;
    DOMNodeList* domNodeList;
    char* text;
}

%start start

%token <text> TEXT
%token DOCTYPE HTML_OPEN HTML_CLOSE
%token HEAD_OPEN HEAD_CLOSE
%token TITLE_OPEN TITLE_CLOSE
%token BODY_OPEN BODY_CLOSE
%token DIV_OPEN DIV_CLOSE
%token P_OPEN P_CLOSE
%token H1_OPEN H1_CLOSE

%type <domNode> html head title body div paragraph h1
%type <domNodeList> body_content
%type <text> text

%%

// Start rule
start:
    DOCTYPE html {
        root = new DOMNode(ROOT);
        DOMNodeList* nodeList = new DOMNodeList();
        nodeList->push_back($2);   // Wrap the single node in a list
        root->appendChildren(*nodeList);
    }
;

// HTML structure
html:
    HTML_OPEN head body HTML_CLOSE {
        $$ = new DOMNode(HTML);
        DOMNodeList* htmlContent = new DOMNodeList();
        htmlContent->push_back($2);  // Head node
        htmlContent->push_back($3);  // Body node
        $$->appendChildren(*htmlContent);
    }
;

// Head structure
head:
    HEAD_OPEN title HEAD_CLOSE {
        $$ = new DOMNode(HEAD);
        DOMNodeList* headContent = new DOMNodeList();
        headContent->push_back($2);  // Title node
        $$->appendChildren(*headContent);
    }
;

// Title structure
title:
    TITLE_OPEN TEXT TITLE_CLOSE {
        $$ = new DOMNode(TITLE, $2);  // Text inside title
    }
;

// Body structure
body:
    BODY_OPEN body_content BODY_CLOSE {
        $$ = new DOMNode(BODY);
        $$->appendChildren(*$2);  // Append body content (list of nodes)
    }
;

// Body content structure
body_content:
    /* empty */ { $$ = new DOMNodeList(); }  // Empty body content
    | body_content paragraph {
        $1->push_back($2);
        $$ = $1;
    }
    | body_content div {
        $1->push_back($2);
        $$ = $1;
    }
    | body_content h1 {
        $1->push_back($2);
        $$ = $1;
    }
;

// Paragraph structure
paragraph:
    P_OPEN text P_CLOSE {
        $$ = new DOMNode(P, $2);  // Text inside paragraph
    }
;

// Div structure
div:
    DIV_OPEN body_content DIV_CLOSE {
        $$ = new DOMNode(DIV);
        $$->appendChildren(*$2);  // Content inside div
    }
;

// H1 structure
h1:
    H1_OPEN text H1_CLOSE {
        $$ = new DOMNode(H1, $2);  // Text inside h1
    }
;

// Text structure
text:
    TEXT {
        $$ = strdup($1);  // Return raw text
    }
;

%%

// Error function
//void yyerror(const char *s) {
//    std::cerr << "Error: " << s << std::endl;
//}

//int main() {
//    return yyparse();
//}
