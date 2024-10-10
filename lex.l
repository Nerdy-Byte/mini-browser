%option noyywrap

%{
#include <cstring>
#include "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/dom_tree.h"
#include "parser.tab.h"

using namespace std;
%}

%x HTML_START
%x BODY_START
%x H1_START
%x HEAD_START
%x PARA

%%

<*>[ \t\n]+                      { ; }
<INITIAL>"<!DOCTYPE html>"       { return DOCTYPE; }
<INITIAL>"<html>"                { BEGIN(HTML_START); return HTML_OPEN; }
<HTML_START>"</html>"            { BEGIN(INITIAL); return HTML_CLOSE; }
<HTML_START>"<head>"             { BEGIN(HEAD_START); return HEAD_OPEN; }
<HEAD_START>"</head>"            { BEGIN(HTML_START); return HEAD_CLOSE; }
<HTML_START>"<body>"             { BEGIN(BODY_START); return BODY_OPEN; }
<BODY_START>"</body>"            { BEGIN(HTML_START); return BODY_CLOSE; }
<HEAD_START>"<title>"            { return TITLE_OPEN; }
<HEAD_START>"</title>"           { return TITLE_CLOSE; }
<BODY_START>"<p>"                { BEGIN(PARA); return P_OPEN; }
<PARA>"</p>"                     { BEGIN(BODY_START); return P_CLOSE; }
<BODY_START>"<div>"              { return DIV_OPEN; }
<BODY_START>"</div>"             { return DIV_CLOSE; }
<BODY_START>"<h1>"               { BEGIN(H1_START); return H1_OPEN; }
<H1_START>"</h1>"                { BEGIN(BODY_START); return H1_CLOSE; }
<*>[^<>]+                        { yylval.text = strdup(yytext); return TEXT; }
.                                { ; }

%%
