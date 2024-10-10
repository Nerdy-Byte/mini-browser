%{
    #include <cstring>
    #include "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/dom_tree.h"
    #include "parser.hpp"

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
%token H1_OPEN H1_CLOSE H2_OPEN H2_CLOSE H3_OPEN H3_CLOSE H4_OPEN H4_CLOSE H5_OPEN H5_CLOSE
%token NAV_OPEN NAV_CLOSE
%token UL_OPEN UL_CLOSE
%token LI_OPEN LI_CLOSE
%token HEADER_OPEN HEADER_CLOSE
%token FOOTER_OPEN FOOTER_CLOSE
%token SECTION_OPEN SECTION_CLOSE
%token ARTICLE_OPEN ARTICLE_CLOSE
%token ASIDE_OPEN ASIDE_CLOSE
%token OL_OPEN OL_CLOSE
%token A_OPEN A_CLOSE
%token STRONG_OPEN STRONG_CLOSE
%token EM_OPEN EM_CLOSE
%token U_OPEN U_CLOSE
%token SMALL_OPEN SMALL_CLOSE
%token PRE_OPEN PRE_CLOSE
%token BLOCKQUOTE_OPEN  BLOCKQUOTE_CLOSE
%token CODE_OPEN CODE_CLOSE
%token IMG_TAG



%type <domNode> html head title body div paragraph h1 h2 h3 h4 h5 nav header list_item unordered_list
%type <domNodeList> body_content unordered_list_content
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
    | paragraph { $$ = new DOMNodeList(); $$->push_back($1); }
    | h1 { $$ = new DOMNodeList(); $$->push_back($1); }
    | h2 { $$ = new DOMNodeList(); $$->push_back($1); }
    | h3 { $$ = new DOMNodeList(); $$->push_back($1); }
    | h4 { $$ = new DOMNodeList(); $$->push_back($1); }
    | h5 { $$ = new DOMNodeList(); $$->push_back($1); }
    | nav { $$ = new DOMNodeList(); $$->push_back($1); }
    | div { $$ = new DOMNodeList(); $$->push_back($1); }
    | unordered_list { $$ = new DOMNodeList(); $$->push_back($1); }
    | body_content paragraph { $1->push_back($2); $$ = $1; }
    | body_content h1 { $1->push_back($2); $$ = $1; }
    | body_content h2 { $1->push_back($2); $$ = $1; }
    | body_content h3 { $1->push_back($2); $$ = $1; }
    | body_content h4 { $1->push_back($2); $$ = $1; }
    | body_content h5 { $1->push_back($2); $$ = $1; }
    | body_content nav { $1->push_back($2); $$ = $1; }
    | body_content div { $1->push_back($2); $$ = $1; }
    | body_content unordered_list { $1->push_back($2); $$ = $1; }
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

// H2 structure
h2:
    H2_OPEN text H2_CLOSE {
        $$ = new DOMNode(H2, $2);  // Text inside h2
    }
;

h3:
    H3_OPEN text H3_CLOSE {
        $$ = new DOMNode(H3, $2);  // Text inside h2
    }
;

h4:
    H4_OPEN text H4_CLOSE {
        $$ = new DOMNode(H4, $2);  // Text inside h2
    }
;

h5:
    H5_OPEN text H5_CLOSE {
        $$ = new DOMNode(H5, $2);  // Text inside h2
    }
;

// Navigation structure (nav)
nav:
    NAV_OPEN body_content NAV_CLOSE {
        $$ = new DOMNode(NAV);
        $$->appendChildren(*$2);  // Content inside nav
    }
;

// Header structure
header:
    HEADER_OPEN body_content HEADER_CLOSE {
        $$ = new DOMNode(HEADER);
        $$->appendChildren(*$2);  // Content inside header
    }
;

// Unordered list structure (ul)
unordered_list:
    UL_OPEN unordered_list_content UL_CLOSE {
        $$ = new DOMNode(UL);
        $$->appendChildren(*$2);  // List items inside ul
    }
;

// Unordered list content
unordered_list_content:
    list_item { $$ = new DOMNodeList(); $$->push_back($1); }
    | unordered_list_content list_item { $1->push_back($2); $$ = $1; }
;

// List item structure (li)
list_item:
    LI_OPEN text LI_CLOSE {
        $$ = new DOMNode(LI, $2);  // Text inside list item
    }
;

// Text structure
text:
    TEXT {
        $$ = strdup($1);  // Return raw text
    }
;

%%
