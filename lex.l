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
<COMMENT>[^\-]+             { /* Ignore comment content, can capture if needed */ }
<COMMENT>"-"                { /* Ignore stray dashes within comments */ }



<INITIAL>"<!DOCTYPE html>"   {printf("Token: DOCTYPE\n"); prev_state.push("initial"); return DOCTYPE; }
<INITIAL>"<html>"            {printf("Token: HTML_OPEN\n"); BEGIN(HTML); return HTML_OPEN; }
<HTML>"</html>"              {printf("Token: HTML_CLOSE\n"); BEGIN(INITIAL); return HTML_CLOSE; }


<HTML>"<head>"               {printf("Token: HEAD_OPEN\n"); BEGIN(HEAD); prev_state.push("head"); return HEAD_OPEN; }
<HEAD>"</head>"              {printf("Token: HEAD_CLOSE\n"); BEGIN(HTML); return HEAD_CLOSE; }
<HEAD>"<title>"              {printf("Token: TITLE_OPEN\n"); return TITLE_OPEN; }
<HEAD>"</title>"             {printf("Token: TITLE_CLOSE\n"); return TITLE_CLOSE; }


<HTML>"<body>"               {printf("Token: BODY_OPEN\n"); BEGIN(BODY); return BODY_OPEN; }
<BODY>"</body>"              {printf("Token: BODY_CLOSE\n"); BEGIN(HTML); return BODY_CLOSE; }
<BODY>"<nav>"                {printf("Token: NAV_OPEN\n"); return NAV_OPEN; }
<BODY>"</nav>"               {printf("Token: NAV_CLOSE\n"); return NAV_CLOSE; }
<BODY>"<header>"             {printf("Token: HEADER_OPEN\n"); return HEADER_OPEN; }
<BODY>"</header>"            {printf("Token: HEADER_CLOSE\n"); return HEADER_CLOSE; }
<BODY>"<footer>"             {printf("Token: FOOTER_OPEN\n"); return FOOTER_OPEN; }
<BODY>"</footer>"            {printf("Token: FOOTER_CLOSE\n"); return FOOTER_CLOSE; }
<BODY>"<section>"            {printf("Token: SECTION_OPEN\n"); return SECTION_OPEN; }
<BODY>"</section>"           {printf("Token: SECTION_CLOSE\n"); return SECTION_CLOSE; }
<BODY>"<article>"            {printf("Token: ARTICLE_OPEN\n"); return ARTICLE_OPEN; }
<BODY>"</article>"           {printf("Token: ARTICLE_CLOSE\n"); return ARTICLE_CLOSE; }
<BODY>"<aside>"              {printf("Token: ASIDE_OPEN\n"); return ASIDE_OPEN; }
<BODY>"</aside>"             {printf("Token: ASIDE_CLOSE\n"); return ASIDE_CLOSE; }


<BODY>"<ul>"                 {printf("Token: UL_OPEN\n"); return UL_OPEN; }
<BODY>"</ul>"                {printf("Token: UL_CLOSE\n"); return UL_CLOSE; }
<BODY>"<ol>"                 {printf("Token: OL_OPEN\n"); return OL_OPEN; }
<BODY>"</ol>"                {printf("Token: OL_CLOSE\n"); return OL_CLOSE; }
<BODY>"<li>"                 {printf("Token: LI_OPEN\n"); return LI_OPEN; }
<BODY>"</li>"                {printf("Token: LI_CLOSE\n"); return LI_CLOSE; }

<BODY>"<strong>"             {printf("Token: STRONG_OPEN\n"); return STRONG_OPEN; }
<BODY>"</strong>"            {printf("Token: STRONG_CLOSE\n"); return STRONG_CLOSE; }
<BODY>"<em>"                 {printf("Token: EM_OPEN\n"); return EM_OPEN; }
<BODY>"</em>"                {printf("Token: EM_CLOSE\n"); return EM_CLOSE; }
<BODY>"<u>"                  {printf("Token: U_OPEN\n"); return U_OPEN; }
<BODY>"</u>"                 {printf("Token: U_CLOSE\n"); return U_CLOSE; }
<BODY>"<small>"              {printf("Token: SMALL_OPEN\n"); return SMALL_OPEN; }
<BODY>"</small>"             {printf("Token: SMALL_CLOSE\n"); return SMALL_CLOSE; }


<BODY>"<blockquote>"         {printf("Token: BLOCKQUOTE_OPEN\n"); return BLOCKQUOTE_OPEN; }
<BODY>"</blockquote>"        {printf("Token: BLOCKQUOTE_CLOSE\n"); return BLOCKQUOTE_CLOSE; }
<BODY>"<pre>"                {printf("Token: PRE_OPEN\n"); return PRE_OPEN; }
<BODY>"</pre>"               {printf("Token: PRE_CLOSE\n"); return PRE_CLOSE; }
<BODY>"<code>"               {printf("Token: CODE_OPEN\n"); return CODE_OPEN; }
<BODY>"</code>"              {printf("Token: CODE_CLOSE\n"); return CODE_CLOSE; }


<BODY>"<p>"                  {printf("Token: P_OPEN\n"); BEGIN(PARA); return P_OPEN; }
<PARA>"</p>"                 {printf("Token: P_CLOSE\n"); BEGIN(BODY); return P_CLOSE; }
<BODY>"<h1>"                 {printf("Token: H1_OPEN\n"); BEGIN(H1); return H1_OPEN; }
<H1>"</h1>"                  {printf("Token: H1_CLOSE\n"); BEGIN(BODY); return H1_CLOSE; }
<BODY>"<h2>"                 {printf("Token: H2_OPEN\n"); return H2_OPEN; }
<BODY>"</h2>"                {printf("Token: H2_CLOSE\n"); return H2_CLOSE; }
<BODY>"<h3>"                 {printf("Token: H3_OPEN\n"); return H3_OPEN; }
<BODY>"</h3>"                {printf("Token: H3_CLOSE\n"); return H3_CLOSE; }
<BODY>"<h4>"                 {printf("Token: H4_OPEN\n"); return H4_OPEN; }
<BODY>"</h4>"                {printf("Token: H4_CLOSE\n"); return H4_CLOSE; }
<BODY>"<h5>"                 {printf("Token: H5_OPEN\n"); return H5_OPEN; }
<BODY>"</h5>"                {printf("Token: H5_CLOSE\n"); return H5_CLOSE; }


<BODY>"<a"[ \t\n]*           {printf("Token: A_OPEN\n"); BEGIN(ANCHOR); return A_OPEN;}


<ANCHOR>href[ \t\n]*=[ \t\n]*\"([^\"]*)\" {
    printf("Token: HREF_TOK with value: %s\n", yytext);
    // Extract just the URL part between quotes
    char* start = strchr(yytext, '"');
    if (start) {
        start++; // Skip the opening quote
        char* end = strrchr(start, '"');
        if (end) {
            *end = '\0';
            yylval.text = strdup(start);
            printf("Extracted URL: %s\n", yylval.text);
            return HREF_TOK;
        }
    }
    // If we couldn't parse properly, return the whole thing
    yylval.text = strdup(yytext);
    return HREF_TOK;
}

<ANCHOR>">"                 {printf("Token: ANCHOR_CLOSE_TAG\n"); BEGIN(BODY); return '>'; }
<BODY>"</a>"                {printf("Token: A_CLOSE\n"); return A_CLOSE; }


<BODY>"<img"[ \t\n]*         {printf("Token: IMG_OPEN\n"); BEGIN(IMG); return IMG_OPEN;}

<IMG>[^>]+ {
    printf("Token: IMG_CONTENT with value: %s\n", yytext);
    yylval.text = strdup(yytext);  // Capture the entire content between <img and >
    return TEXT;
}

<IMG>">"                     {printf("Token: IMG_CLOSE\n"); BEGIN(BODY); return IMG_CLOSE; }


<*>[^<>]+                    {printf("Token: TEXT %s\n",yytext); yylval.text = strdup(yytext); return TEXT; }


.                            { ; }

%%

