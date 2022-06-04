%{
#include "expresiones.h"
#include <math.h>
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

using namespace std;
int n_lineas;

%}

%option noyywrap

%x COM1 
 
%%

"#"						BEGIN(COM1);
<COM1>\n					BEGIN(0);n_lineas++;return '\n';
<COM1>.					;

[L][I][S][T][A][S]				return LISTA;
[V][A][R][I][A][B][L][E][S]			return VARIABLES;
[I][N][I][C][I][O]				return INICIO;
[F][I][N]					return FIN;
[S][i]						return SI;
[S][i][_][n][o]				return SI_NO;
[E][n][t][e][r][o]				yylval.c_entero = 0; return TIPO_VAL;
[R][e][a][l]					yylval.c_entero = 1; return TIPO_VAL;
[L][o][g][i][c][o]				yylval.c_entero = 2; return TIPO_VAL;
[f][a][l][s][o]				{yylval.c_bool = false; return BOOL;}
[c][i][e][r][t][o]				{yylval.c_bool = true;return BOOL;}
[E][s][c][r][i][b][i][r]			return ESCRIBIR;
["][^"]*["]					strcpy(yylval.c_cadena, yytext); return CADENA_CARACT;
[N][u][e][v][a][L][i][n][e][a]		return NUEVALINEA;
[p][r][i][m][e][r][o]				return PRIMERO;
[u][l][t][i][m][o]				return ULTIMO;
[e][n][e][s][i][m][o]				return ENESIMO;
[.][.]						{return SUBRANGO;}
[<][-]						{return ASIGNACION;}
[<][=]						{return COMP_ARIT1;}
[>][=]						{return COMP_ARIT2;}
[=][=]						{return COMP_IGUAL;}
[<][>]						{return COMP_DIST;}
[y]						{return COMP_Y;}
[o]						{return COMP_O;}
[n][o]						{return COMP_NO;}
[0-9]+						{yylval.c_entero = atoi(yytext);return ENTERO;}
([0-9]+[.][0-9]*)|([0-9]*[.][0-9]+)		{yylval.c_float = atof(yytext);return REAL;}
[a-z][A-Za-z_0-9]*				{strcpy(yylval.c_cadena,  yytext);return VARIABLE;}
[A-Z][A-Za-z_0-9]*				{strcpy(yylval.c_cadena,  yytext);return NOMBRE_LISTA;}
\n						n_lineas++; return (yytext[0]);
[\t ]						;	
. 						{return (yytext[0]);}
%%

