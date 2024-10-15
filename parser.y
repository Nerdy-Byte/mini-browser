%{
    #include <cstring>
    #include "../../dom_tree.h"
    #include "parser.hpp"

    extern int yylex();
    extern FILE *yyin;
    void yyerror(const char *s) {
    extern int yylineno; // Declare yylineno here
    fprintf(stderr, "Parse error! Message: %s at line %d\n", s, yylineno);
    exit(-1);
}

    using namespace std;
    DOMNode* root = nullptr;
%}

%union {
    DOMNode* domNode;
    DOMNodeList* domNodeList;
    char* text;
}

%start start

%token <text> TEXT SRC_TOK ALT_TOK
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
%token IMG_TAG IMG_CLOSE



%type <domNode> html head title body div paragraph h1 h2 h3 h4 h5 nav header list_item unordered_list ordered_list section strong em u small
%type <domNode> blockquote pre code img
%type <domNodeList> body_content unordered_list_content ordered_list_content
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
    | body_content paragraph { $1->push_back($2); $$ = $1; }
    | body_content h1 { $1->push_back($2); $$ = $1; }
    | body_content h2 { $1->push_back($2); $$ = $1; }
    | body_content h3 { $1->push_back($2); $$ = $1; }
    | body_content h4 { $1->push_back($2); $$ = $1; }
    | body_content h5 { $1->push_back($2); $$ = $1; }
    | body_content nav { $1->push_back($2); $$ = $1; }
    | body_content header { $1->push_back($2); $$ = $1; }
    | body_content unordered_list { $1->push_back($2); $$ = $1; }
    | body_content ordered_list { $1->push_back($2); $$ = $1; }
    | body_content section { $1->push_back($2); $$ = $1; }
    | body_content div { $1->push_back($2); $$ = $1; }
    | body_content strong { $1->push_back($2); $$ = $1; }
    | body_content em { $1->push_back($2); $$ = $1; }
    | body_content u { $1->push_back($2); $$ = $1; }
    | body_content small { $1->push_back($2); $$ = $1; }
    | body_content blockquote { $1->push_back($2); $$ = $1; }
    | body_content pre { $1->push_back($2); $$ = $1; }
    | body_content code { $1->push_back($2); $$ = $1; }
    | body_content img { $1->push_back($2); $$ = $1; }
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

//Ordered list structure (ul)
ordered_list:
    OL_OPEN ordered_list_content OL_CLOSE {
        $$ = new DOMNode(OL);
        $$->appendChildren(*$2);  // List items inside ol
    }
;


// Unordered list content
unordered_list_content:
    list_item { $$ = new DOMNodeList(); $$->push_back($1); }
    | unordered_list_content list_item { $1->push_back($2); $$ = $1; }
;

//ordered list content
ordered_list_content:
    list_item { $$ = new DOMNodeList(); $$->push_back($1); }
    | unordered_list_content list_item { $1->push_back($2); $$ = $1; }
;

// List item structure (li)
list_item:
    LI_OPEN text LI_CLOSE {
        $$ = new DOMNode(LI, $2);  // Text inside list item
    }
;

// Section structure
section:
    SECTION_OPEN body_content SECTION_CLOSE {
        $$ = new DOMNode(SECTION);
        $$->appendChildren(*$2);  // Content inside section
    }
;

// Strong structure
strong:
    STRONG_OPEN text STRONG_CLOSE {
        $$ = new DOMNode(STRONG, $2);  // Text inside strong (bold)
    }
;

// Emphasis (em) structure
em:
    EM_OPEN text EM_CLOSE {
        $$ = new DOMNode(EM, $2);  // Text inside em (italic)
    }
;

// Underline (u) structure
u:
    U_OPEN text U_CLOSE {
        $$ = new DOMNode(U, $2);  // Text inside u (underline)
    }
;

// Small tag structure
small:
    SMALL_OPEN text SMALL_CLOSE {
        $$ = new DOMNode(SMALL, $2);  // Text inside small (smaller font)
    }
;

// Blockquote structure
blockquote:
    BLOCKQUOTE_OPEN text BLOCKQUOTE_CLOSE {
        $$ = new DOMNode(BLOCK_QUOTE, $2);  // Create a DOMNode for blockquote with its text content
    }
;


// Preformatted text (pre) structure
pre:
    PRE_OPEN text PRE_CLOSE {
        $$ = new DOMNode(PRE, $2);  // Create a DOMNode for pre with its text content
    }
;

// Code structure
code:
    CODE_OPEN text CODE_CLOSE {
        $$ = new DOMNode(CODE, $2);  // Text inside code
    }
;

//image tag
img:
    IMG_TAG SRC_TOK TEXT ALT_TOK TEXT IMG_CLOSE {
        $$ = new DOMNode(IMG);

        // Create DOMNode for src and alt
        DOMNode* srcNode = new DOMNode(SRC, $3);
        DOMNode* altNode = new DOMNode(ALT, $5);

        // Append children using vector
        std::vector<DOMNode*> children;
        children.push_back(srcNode);
        children.push_back(altNode);

        $$->appendChildren(children);
    }
;


// Text structure
text:
    TEXT {
        $$ = strdup($1);  // Return raw text
    }
;


%%
