/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_USERS_DIVYANSHUDWIVEDI2018GMAIL_COM_DESKTOP_SSL_UNTITLED_PARSER_HPP_INCLUDED
# define YY_YY_USERS_DIVYANSHUDWIVEDI2018GMAIL_COM_DESKTOP_SSL_UNTITLED_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TEXT = 258,                    /* TEXT  */
    DOCTYPE = 259,                 /* DOCTYPE  */
    HTML_OPEN = 260,               /* HTML_OPEN  */
    HTML_CLOSE = 261,              /* HTML_CLOSE  */
    HEAD_OPEN = 262,               /* HEAD_OPEN  */
    HEAD_CLOSE = 263,              /* HEAD_CLOSE  */
    TITLE_OPEN = 264,              /* TITLE_OPEN  */
    TITLE_CLOSE = 265,             /* TITLE_CLOSE  */
    BODY_OPEN = 266,               /* BODY_OPEN  */
    BODY_CLOSE = 267,              /* BODY_CLOSE  */
    DIV_OPEN = 268,                /* DIV_OPEN  */
    DIV_CLOSE = 269,               /* DIV_CLOSE  */
    P_OPEN = 270,                  /* P_OPEN  */
    P_CLOSE = 271,                 /* P_CLOSE  */
    H1_OPEN = 272,                 /* H1_OPEN  */
    H1_CLOSE = 273,                /* H1_CLOSE  */
    H2_OPEN = 274,                 /* H2_OPEN  */
    H2_CLOSE = 275,                /* H2_CLOSE  */
    H3_OPEN = 276,                 /* H3_OPEN  */
    H3_CLOSE = 277,                /* H3_CLOSE  */
    H4_OPEN = 278,                 /* H4_OPEN  */
    H4_CLOSE = 279,                /* H4_CLOSE  */
    H5_OPEN = 280,                 /* H5_OPEN  */
    H5_CLOSE = 281,                /* H5_CLOSE  */
    NAV_OPEN = 282,                /* NAV_OPEN  */
    NAV_CLOSE = 283,               /* NAV_CLOSE  */
    UL_OPEN = 284,                 /* UL_OPEN  */
    UL_CLOSE = 285,                /* UL_CLOSE  */
    LI_OPEN = 286,                 /* LI_OPEN  */
    LI_CLOSE = 287,                /* LI_CLOSE  */
    HEADER_OPEN = 288,             /* HEADER_OPEN  */
    HEADER_CLOSE = 289,            /* HEADER_CLOSE  */
    FOOTER_OPEN = 290,             /* FOOTER_OPEN  */
    FOOTER_CLOSE = 291,            /* FOOTER_CLOSE  */
    SECTION_OPEN = 292,            /* SECTION_OPEN  */
    SECTION_CLOSE = 293,           /* SECTION_CLOSE  */
    ARTICLE_OPEN = 294,            /* ARTICLE_OPEN  */
    ARTICLE_CLOSE = 295,           /* ARTICLE_CLOSE  */
    ASIDE_OPEN = 296,              /* ASIDE_OPEN  */
    ASIDE_CLOSE = 297,             /* ASIDE_CLOSE  */
    OL_OPEN = 298,                 /* OL_OPEN  */
    OL_CLOSE = 299,                /* OL_CLOSE  */
    A_OPEN = 300,                  /* A_OPEN  */
    A_CLOSE = 301,                 /* A_CLOSE  */
    STRONG_OPEN = 302,             /* STRONG_OPEN  */
    STRONG_CLOSE = 303,            /* STRONG_CLOSE  */
    EM_OPEN = 304,                 /* EM_OPEN  */
    EM_CLOSE = 305,                /* EM_CLOSE  */
    U_OPEN = 306,                  /* U_OPEN  */
    U_CLOSE = 307,                 /* U_CLOSE  */
    SMALL_OPEN = 308,              /* SMALL_OPEN  */
    SMALL_CLOSE = 309,             /* SMALL_CLOSE  */
    PRE_OPEN = 310,                /* PRE_OPEN  */
    PRE_CLOSE = 311,               /* PRE_CLOSE  */
    BLOCKQUOTE_OPEN = 312,         /* BLOCKQUOTE_OPEN  */
    BLOCKQUOTE_CLOSE = 313,        /* BLOCKQUOTE_CLOSE  */
    CODE_OPEN = 314,               /* CODE_OPEN  */
    CODE_CLOSE = 315,              /* CODE_CLOSE  */
    IMG_TAG = 316                  /* IMG_TAG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"

    DOMNode* domNode;
    DOMNodeList* domNodeList;
    char* text;

#line 131 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_USERS_DIVYANSHUDWIVEDI2018GMAIL_COM_DESKTOP_SSL_UNTITLED_PARSER_HPP_INCLUDED  */
