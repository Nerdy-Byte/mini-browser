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
     H1_CLOSE = 273
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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/parser.y"
{
    DOMNode* domNode;
    DOMNodeList* domNodeList;
    char* text;
}
/* Line 1529 of yacc.c.  */
#line 91 "/Users/divyanshudwivedi2018gmail.com/Desktop/SSL/untitled/build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

