%option noyywrap

%{
#include <cstring>
#include <stack>
#include <string>
#include "../dom_tree.h"
#include "parser.hpp"
using namespace std;
stack<string> prev_state;
%}

%x HTML
%x BODY
%x HEAD
%x PARA
%x H1
%x IMG
%x ANCHOR
%x COMMENT

%%

<*>[ \t\n]+                 { ; }
<BODY,INITIAL>"<!--"        { BEGIN(COMMENT); /* Switch to comment mode */ }
<COMMENT>"-->"              { BEGIN(BODY); /* End of comment, return to normal mode */ }
<COMMENT>[^\-]+             { /* Ignore comment content */ }
<COMMENT>"-"                { /* Ignore stray dashes within comments */ }



<INITIAL>"<!DOCTYPE html>"   { prev_state.push("initial"); return DOCTYPE; }
<INITIAL>"<html>"            { BEGIN(HTML); return HTML_OPEN; }
<HTML>"</html>"              { BEGIN(INITIAL); return HTML_CLOSE; }


<HTML>"<head>"               { BEGIN(HEAD); prev_state.push("head"); return HEAD_OPEN; }
<HEAD>"</head>"              { BEGIN(HTML); return HEAD_CLOSE; }
<HEAD>"<title>"              { return TITLE_OPEN; }
<HEAD>"</title>"             { return TITLE_CLOSE; }


<HTML>"<body>"               { BEGIN(BODY); return BODY_OPEN; }
<BODY>"</body>"              { BEGIN(HTML); return BODY_CLOSE; }
<BODY,PARA>"<nav>"                { return NAV_OPEN; }
<BODY,PARA>"</nav>"               { return NAV_CLOSE; }
<BODY>"<header>"             { return HEADER_OPEN; }
<BODY>"</header>"            { return HEADER_CLOSE; }
<BODY>"<footer>"             { return FOOTER_OPEN; }
<BODY>"</footer>"            { return FOOTER_CLOSE; }
<BODY,PARA>"<section>"            { return SECTION_OPEN; }
<BODY,PARA>"</section>"           { return SECTION_CLOSE; }
<BODY,PARA>"<article>"            { return ARTICLE_OPEN; }
<BODY,PARA>"</article>"           { return ARTICLE_CLOSE; }
<BODY,PARA>"<aside>"              { return ASIDE_OPEN; }
<BODY,PARA>"</aside>"             { return ASIDE_CLOSE; }


<BODY,PARA>"<ul>"                 { return UL_OPEN; }
<BODY,PARA>"</ul>"                { return UL_CLOSE; }
<BODY,PARA>"<ol>"                 { return OL_OPEN; }
<BODY,PARA>"</ol>"                { return OL_CLOSE; }
<BODY,PARA>"<li>"                 { return LI_OPEN; }
<BODY,PARA>"</li>"                { return LI_CLOSE; }

<BODY,PARA>"<strong>"             { return STRONG_OPEN; }
<BODY,PARA>"</strong>"            { return STRONG_CLOSE; }
<BODY,PARA>"<em>"                 { return EM_OPEN; }
<BODY,PARA>"</em>"                { return EM_CLOSE; }
<BODY,PARA>"<u>"                  { return U_OPEN; }
<BODY,PARA>"</u>"                 { return U_CLOSE; }
<BODY,PARA>"<small>"              { return SMALL_OPEN; }
<BODY,PARA>"</small>"             { return SMALL_CLOSE; }


<BODY,PARA>"<blockquote>"         { return BLOCKQUOTE_OPEN; }
<BODY,PARA>"</blockquote>"        { return BLOCKQUOTE_CLOSE; }
<BODY,PARA>"<pre>"                { return PRE_OPEN; }
<BODY,PARA>"</pre>"               { return PRE_CLOSE; }
<BODY,PARA>"<code>"               { return CODE_OPEN; }
<BODY,PARA>"</code>"              { return CODE_CLOSE; }


<BODY>"<p>"                  { BEGIN(PARA); return P_OPEN; }
<BODY,PARA>"</p>"            { BEGIN(BODY); return P_CLOSE; }
<BODY>"<h1>"                 { BEGIN(H1); return H1_OPEN; }
<H1>"</h1>"                  { BEGIN(BODY); return H1_CLOSE; }
<BODY>"<h2>"                 { return H2_OPEN; }
<BODY>"</h2>"                { return H2_CLOSE; }
<BODY>"<h3>"                 { return H3_OPEN; }
<BODY>"</h3>"                { return H3_CLOSE; }
<BODY>"<h4>"                 { return H4_OPEN; }
<BODY>"</h4>"                { return H4_CLOSE; }
<BODY>"<h5>"                 { return H5_OPEN; }
<BODY>"</h5>"                { return H5_CLOSE; }


<BODY>"<a"[ \t\n]*           { BEGIN(ANCHOR); return A_OPEN;}


<ANCHOR>href[ \t\n]*=[ \t\n]*\"([^\"]*)\" {
    // Extracting just the URL part between quotes
    char* start = strchr(yytext, '"');
    if (start) {
        start++; // Skip the opening quote
        char* end = strrchr(start, '"');
        if (end) {
            *end = '\0';
            yylval.text = strdup(start);
            return HREF_TOK;
        }
    }
    // If we couldn't parse properly, return the whole thing
    yylval.text = strdup(yytext);
    return HREF_TOK;
}

<ANCHOR>">"                 { BEGIN(BODY); return '>'; }
<BODY>"</a>"                { return A_CLOSE; }


<BODY>"<img"[ \t\n]*         { BEGIN(IMG); return IMG_OPEN;}

<IMG>[^>]+ {
    yylval.text = strdup(yytext);  // Capturing the entire content between <img and >
    return TEXT;
}

<IMG>">"                     { BEGIN(BODY); return IMG_CLOSE; }


<*>[^<>]+                    { yylval.text = strdup(yytext); return TEXT; }


.                            { ; }

%%

