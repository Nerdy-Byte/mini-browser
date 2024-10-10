%option noyywrap

%{
#include <cstring>
#include <stack>
#include <string>
#include "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/dom_tree.h"
#include "parser.hpp"
using namespace std;
stack<string> prev_state;
%}

%x HTML
%x BODY
%x HEAD
%x PARA
%x H1

%%

<*>[ \t\n]+                        { ; }


<INITIAL>"<!DOCTYPE html>"   { prev_state.push("initial"); return DOCTYPE; }
<INITIAL>"<html>"            { BEGIN(HTML); return HTML_OPEN; }
<HTML>"</html>"              { BEGIN(INITIAL); return HTML_CLOSE; }


<HTML>"<head>"               { BEGIN(HEAD); prev_state.push("head"); return HEAD_OPEN; }
<HEAD>"</head>"              { BEGIN(HTML); return HEAD_CLOSE; }
<HEAD>"<title>"              { return TITLE_OPEN; }
<HEAD>"</title>"             { return TITLE_CLOSE; }


<HTML>"<body>"               { BEGIN(BODY); return BODY_OPEN; }
<BODY>"</body>"              { BEGIN(HTML); return BODY_CLOSE; }
<BODY>"<nav>"                { return NAV_OPEN; }
<BODY>"</nav>"               { return NAV_CLOSE; }
<BODY>"<header>"             { return HEADER_OPEN; }
<BODY>"</header>"            { return HEADER_CLOSE; }
<BODY>"<footer>"             { return FOOTER_OPEN; }
<BODY>"</footer>"            { return FOOTER_CLOSE; }
<BODY>"<section>"            { return SECTION_OPEN; }
<BODY>"</section>"           { return SECTION_CLOSE; }
<BODY>"<article>"            { return ARTICLE_OPEN; }
<BODY>"</article>"           { return ARTICLE_CLOSE; }
<BODY>"<aside>"              { return ASIDE_OPEN; }
<BODY>"</aside>"             { return ASIDE_CLOSE; }


<BODY>"<ul>"                 { return UL_OPEN; }
<BODY>"</ul>"                { return UL_CLOSE; }
<BODY>"<ol>"                 { return OL_OPEN; }
<BODY>"</ol>"                { return OL_CLOSE; }
<BODY>"<li>"                 { return LI_OPEN; }
<BODY>"</li>"                { return LI_CLOSE; }


<BODY>"<a>"                  { return A_OPEN; }
<BODY>"</a>"                 { return A_CLOSE; }
<BODY>"<strong>"             { return STRONG_OPEN; }
<BODY>"</strong>"            { return STRONG_CLOSE; }
<BODY>"<em>"                 { return EM_OPEN; }
<BODY>"</em>"                { return EM_CLOSE; }
<BODY>"<u>"                  { return U_OPEN; }
<BODY>"</u>"                 { return U_CLOSE; }
<BODY>"<small>"              { return SMALL_OPEN; }
<BODY>"</small>"             { return SMALL_CLOSE; }


<BODY>"<blockquote>"         { return BLOCKQUOTE_OPEN; }
<BODY>"</blockquote>"        { return BLOCKQUOTE_CLOSE; }
<BODY>"<pre>"                { return PRE_OPEN; }
<BODY>"</pre>"               { return PRE_CLOSE; }
<BODY>"<code>"               { return CODE_OPEN; }
<BODY>"</code>"              { return CODE_CLOSE; }


<BODY>"<p>"                  { BEGIN(PARA); return P_OPEN; }
<PARA>"</p>"                 { BEGIN(BODY); return P_CLOSE; }
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


<BODY>"<img[^>]*>"           { return IMG_TAG; }


<*>[^<>]+                    { yylval.text = strdup(yytext); return TEXT; }


.                            { ; }

%%

