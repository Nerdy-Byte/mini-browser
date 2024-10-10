/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TEXT = 258,
     DOCTYPE = 259,
     HTML_OPEN = 260,
     HTML_CLOSE = 261,
     HEAD_OPEN = 262,
     HEAD_CLOSE = 263,
     TITLE_OPEN = 264,
     TITLE_CLOSE = 265,
     BODY_OPEN = 266,
     BODY_CLOSE = 267,
     DIV_OPEN = 268,
     DIV_CLOSE = 269,
     P_OPEN = 270,
     P_CLOSE = 271,
     H1_OPEN = 272,
     H1_CLOSE = 273,
     H2_OPEN = 274,
     H2_CLOSE = 275,
     H3_OPEN = 276,
     H3_CLOSE = 277,
     H4_OPEN = 278,
     H4_CLOSE = 279,
     H5_OPEN = 280,
     H5_CLOSE = 281,
     NAV_OPEN = 282,
     NAV_CLOSE = 283,
     UL_OPEN = 284,
     UL_CLOSE = 285,
     LI_OPEN = 286,
     LI_CLOSE = 287,
     HEADER_OPEN = 288,
     HEADER_CLOSE = 289,
     FOOTER_OPEN = 290,
     FOOTER_CLOSE = 291,
     SECTION_OPEN = 292,
     SECTION_CLOSE = 293,
     ARTICLE_OPEN = 294,
     ARTICLE_CLOSE = 295,
     ASIDE_OPEN = 296,
     ASIDE_CLOSE = 297,
     OL_OPEN = 298,
     OL_CLOSE = 299,
     A_OPEN = 300,
     A_CLOSE = 301,
     STRONG_OPEN = 302,
     STRONG_CLOSE = 303,
     EM_OPEN = 304,
     EM_CLOSE = 305,
     U_OPEN = 306,
     U_CLOSE = 307,
     SMALL_OPEN = 308,
     SMALL_CLOSE = 309,
     PRE_OPEN = 310,
     PRE_CLOSE = 311,
     BLOCKQUOTE_OPEN = 312,
     BLOCKQUOTE_CLOSE = 313,
     CODE_OPEN = 314,
     CODE_CLOSE = 315,
     IMG_TAG = 316
   };
#endif
/* Tokens.  */
#define TEXT 258
#define DOCTYPE 259
#define HTML_OPEN 260
#define HTML_CLOSE 261
#define HEAD_OPEN 262
#define HEAD_CLOSE 263
#define TITLE_OPEN 264
#define TITLE_CLOSE 265
#define BODY_OPEN 266
#define BODY_CLOSE 267
#define DIV_OPEN 268
#define DIV_CLOSE 269
#define P_OPEN 270
#define P_CLOSE 271
#define H1_OPEN 272
#define H1_CLOSE 273
#define H2_OPEN 274
#define H2_CLOSE 275
#define H3_OPEN 276
#define H3_CLOSE 277
#define H4_OPEN 278
#define H4_CLOSE 279
#define H5_OPEN 280
#define H5_CLOSE 281
#define NAV_OPEN 282
#define NAV_CLOSE 283
#define UL_OPEN 284
#define UL_CLOSE 285
#define LI_OPEN 286
#define LI_CLOSE 287
#define HEADER_OPEN 288
#define HEADER_CLOSE 289
#define FOOTER_OPEN 290
#define FOOTER_CLOSE 291
#define SECTION_OPEN 292
#define SECTION_CLOSE 293
#define ARTICLE_OPEN 294
#define ARTICLE_CLOSE 295
#define ASIDE_OPEN 296
#define ASIDE_CLOSE 297
#define OL_OPEN 298
#define OL_CLOSE 299
#define A_OPEN 300
#define A_CLOSE 301
#define STRONG_OPEN 302
#define STRONG_CLOSE 303
#define EM_OPEN 304
#define EM_CLOSE 305
#define U_OPEN 306
#define U_CLOSE 307
#define SMALL_OPEN 308
#define SMALL_CLOSE 309
#define PRE_OPEN 310
#define PRE_CLOSE 311
#define BLOCKQUOTE_OPEN 312
#define BLOCKQUOTE_CLOSE 313
#define CODE_OPEN 314
#define CODE_CLOSE 315
#define IMG_TAG 316




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
{
    DOMNode* domNode;
    DOMNodeList* domNodeList;
    char* text;
}
/* Line 1529 of yacc.c.  */
#line 177 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

