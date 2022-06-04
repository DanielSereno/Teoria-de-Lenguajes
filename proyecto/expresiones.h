/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_EXPRESIONES_H_INCLUDED
# define YY_YY_EXPRESIONES_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASIGNACION = 258,
    COMP_ARIT1 = 259,
    COMP_ARIT2 = 260,
    COMP_IGUAL = 261,
    COMP_DIST = 262,
    COMP_Y = 263,
    COMP_O = 264,
    COMP_NO = 265,
    SUBRANGO = 266,
    ENTERO = 267,
    REAL = 268,
    VARIABLE = 269,
    BOOL = 270,
    NOMBRE_LISTA = 271,
    TIPO_VAL = 272,
    LISTA = 273,
    VARIABLES = 274,
    INICIO = 275,
    FIN = 276,
    SI = 277,
    SI_NO = 278,
    ESCRIBIR = 279,
    NUEVALINEA = 280,
    PRIMERO = 281,
    ULTIMO = 282,
    ENESIMO = 283,
    CADENA_CARACT = 284,
    si_simple = 285,
    menos = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "expresiones.y"

	int c_entero;
	float c_float;
	char c_cadena[25];
	char c_texto [100];
	bool c_bool;
	struct {
		float valor;
		bool esReal;
	} c_expresion;

#line 101 "expresiones.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_EXPRESIONES_H_INCLUDED  */
