%{
#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "tabla.h"
#include "lista.h"
#include <map>

using namespace std;

//elementos externos al analizador sintácticos por haber sido declarados en el analizador léxico      			
extern int n_lineas;
extern int yylex();
bool errorSemantico = false;
tablaSim tabla;
lista list;
tipo_datoTS dato;
tipo_datoTS datosVar[100];
tipo_datoLista datosLis;
tipo_valorLista valorLista;
int pos;
int contVar=0;
int contLis=0;
bool ejecutar = true;

extern FILE* yyin;
extern FILE* yyout;

//definición de procedimientos auxiliares


void yyerror(const char* s){
	if(!errorSemantico)
		cout << "Error sintáctico en la instrucción " << n_lineas << endl; 
	errorSemantico=false;
	ejecutar=true;
}

%}

%union{
	int c_entero;
	float c_float;
	char c_cadena[25];
	char c_texto [100];
	bool c_bool;
	struct {
		float valor;
		bool esReal;
	} c_expresion;
}
%start entrada
%token ASIGNACION
%token COMP_ARIT1
%token COMP_ARIT2
%token COMP_IGUAL
%token COMP_DIST
%token COMP_Y
%token COMP_O
%token COMP_NO
%token SUBRANGO
%token <c_entero> ENTERO
%token <c_float> REAL
%token <c_cadena> VARIABLE
%token <c_bool> BOOL
%token <c_cadena> NOMBRE_LISTA
%token <c_entero> TIPO_VAL
%token LISTA
%token VARIABLES
%token INICIO
%token FIN
%token SI
%token SI_NO
%token ESCRIBIR
%token NUEVALINEA
%token PRIMERO
%token ULTIMO
%token ENESIMO
%token <c_texto> CADENA_CARACT
%nonassoc si_simple
%type <c_expresion> exprNum
%type <c_bool> exprBool

%left ';'
%left ','
%left COMP_O
%left COMP_Y
%left COMP_DIST COMP_IGUAL
%left COMP_ARIT2 COMP_ARIT1 '<' '>'
%left '+' '-'   
%left '*' '/' '%'
%left  COMP_NO 
%left menos

%%
saltoLinea:'\n'
	| saltoLinea '\n'
	;
saltoLineaOpcional: 
	| saltoLineaOpcional '\n'
	;
entrada:		{;} 	
      |saltoLineaOpcional bListas bVariables bInicio saltoLinea
      ;
bListas: LISTA saltoLinea secListas
	;
secListas:NOMBRE_LISTA '=' '{' var '}'saltoLinea		{if(!errorSemantico){
									strcpy(datosLis.identificador, $1);
									datosLis.numDatos = contVar;
									datosLis.tipo = 3;
									int i=0;
									while(i<contVar){
										strcpy(datosLis.datos[i].valor_iden, datosVar[i].identificador);
										i++;
									}
									list.insertar(datosLis);
									datosLis.numDatos=0;
									contVar = 0;
								}
								errorSemantico=false;
								}
	|NOMBRE_LISTA '=' '{' listaNum '}'saltoLinea	{if(!errorSemantico){
								strcpy(datosLis.identificador, $1);
								datosLis.numDatos = contLis;
								list.insertar(datosLis);
								datosLis.numDatos=0;
								contLis = 0;
							}
							errorSemantico=false;
							}
	|NOMBRE_LISTA '=' '{' listaLog '}'saltoLinea	{if(!errorSemantico){
								strcpy(datosLis.identificador, $1);
								datosLis.tipo = 2;
								datosLis.numDatos = contLis;
								list.insertar(datosLis);
								datosLis.numDatos=0;
								contLis = 0;
							}
							errorSemantico=false;
							}
	|NOMBRE_LISTA '=' '{' exprNum SUBRANGO exprNum'}'saltoLinea	{if(!errorSemantico){
										int mayor = int($6.valor);
										int menor = int($4.valor);
										int i = 0;
										strcpy(datosLis.identificador, $1);
										datosLis.tipo = 0;
										while (menor <= mayor){
											datosLis.datos[i].valor_entero = menor;
											menor++;
											i++;
										}
										datosLis.numDatos= i;
										list.insertar(datosLis);
										datosLis.numDatos=0;
									}
									errorSemantico=false;
									}
	|secListas NOMBRE_LISTA '=' '{' var '}'saltoLinea		{if(!errorSemantico){
										strcpy(datosLis.identificador, $2);
										datosLis.numDatos = contVar;
										datosLis.tipo = 3;
										int i=0;
										while(i<contVar){
											strcpy(datosLis.datos[i].valor_iden, datosVar[i].identificador);
											i++;
										}
										list.insertar(datosLis);
										datosLis.numDatos=0;
										contVar = 0;
									}
									errorSemantico=false;
									}
									
	|secListas NOMBRE_LISTA '=' '{' listaNum '}'saltoLinea	{if(!errorSemantico){
										strcpy(datosLis.identificador, $2);
										datosLis.numDatos = contLis;
										list.insertar(datosLis);
										datosLis.numDatos=0;
										contLis = 0;
									}
									errorSemantico=false;
									}
									
	|secListas NOMBRE_LISTA '=' '{' listaLog '}'saltoLinea	{if(!errorSemantico){
										strcpy(datosLis.identificador, $2);
										datosLis.tipo = 2;
										datosLis.numDatos = contLis;
										list.insertar(datosLis);
										datosLis.numDatos=0;
										contLis = 0;
									}
									errorSemantico=false;
									}
									
	|secListas NOMBRE_LISTA '=' '{' ENTERO SUBRANGO ENTERO'}'saltoLinea	{if(!errorSemantico){
											int mayor = $7;
											int menor = $5;
											if(menor<mayor){
												int i = 0;
												strcpy(datosLis.identificador, $2);
												datosLis.tipo = 0;
												while (menor <= mayor){
													datosLis.datos[i].valor_entero = menor;
													menor++;
													i++;
												}
												datosLis.numDatos= i;
												list.insertar(datosLis);
												datosLis.numDatos=0;
											}
										}
										errorSemantico=false;
										}
	;
bVariables: VARIABLES saltoLinea saltosVariables
	;
saltosVariables:secVariables saltoLinea
	|saltosVariables secVariables saltoLinea
	;
secVariables:TIPO_VAL var';' 		{if(!errorSemantico){
						dato.tipo = $1;
						int i=0;
						while(i<contVar){
							strcpy(dato.identificador, datosVar[i].identificador);
							tabla.insertar(dato);
							i++;
						}
						contVar=0;
					}
					errorSemantico=false;
					}
	|NOMBRE_LISTA var';' 		{if(!errorSemantico){
						tipo_datoLista valorLista;
						if(list.encontrarLista($1, valorLista)){
							dato.tipo = valorLista.tipo;
							strcpy(dato.nomLista, $1);
							int i=0;
							while(i<contVar){
								strcpy(dato.identificador, datosVar[i].identificador);
								tabla.insertar(dato);
								i++;
							}
							contVar=0;
						}
					}
					errorSemantico=false;
					}
	|secVariables TIPO_VAL var';' 	{if(!errorSemantico){
							dato.tipo = $2;
							int i=0;
							while(i<contVar){
								strcpy(dato.identificador, datosVar[i].identificador);
								tabla.insertar(dato);
								i++;
							}
							contVar=0;
						}
						errorSemantico=false;
						}
						
	|secVariables NOMBRE_LISTA var';' 	{if(!errorSemantico){
						tipo_datoLista valorLista;
						if(list.encontrarLista($2, valorLista)){
							dato.tipo = valorLista.tipo;
							strcpy(dato.nomLista, $2);
							int i=0;
							while(i<contVar){
								strcpy(dato.identificador, datosVar[i].identificador);
								tabla.insertar(dato);
								i++;
							}
							contVar=0;
						}
					}
					errorSemantico=false;
					}
	;
var: VARIABLE				{if(!errorSemantico){
						strcpy(datosVar[contVar].identificador, $1);
						contVar++;
						datosLis.tipo = 3;
					}
					}
	|var ',' VARIABLE		{if(!errorSemantico){
						strcpy(datosVar[contVar].identificador, $3);
						contVar++;
						datosLis.tipo = 3;
					}
					}
					
	;
bInicio:INICIO saltoLinea bloqueInstruc FIN
	;
bloqueInstruc:secInstruc saltoLinea
	|condicional 
	|bloqueInstruc secInstruc saltoLinea
	|bloqueInstruc condicional 
	;
condicional:parteSi  parteSiNo 	{ejecutar=true;}
	;
parteSi:SI '(' exprBool ')' {ejecutar=$3;} saltoLineaOpcional '[' saltoLineaOpcional bloqueInstruc ']' saltoLinea
	;
parteSiNo: 		%prec si_simple
	|SI_NO {ejecutar=!ejecutar;} saltoLineaOpcional '[' saltoLineaOpcional bloqueInstruc ']' saltoLinea
	;
secInstruc:VARIABLE ASIGNACION exprBool';' 	{if(ejecutar){
							if(!errorSemantico){
								
								if(tabla.buscar($1, dato, pos)){
									if(dato.tipo == 2){
										dato.valor.valor_bool = $3;
										if(!tabla.modificar(pos, dato.valor)){
											cout<< "Error al modificar" << endl;
										}
									}
									else if(dato.tipo == 0){
										cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo entero y recibe un logico" 									<< endl;
										errorSemantico=true;
									}
									else if(dato.tipo == 1){
										cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo real y recibe un logico" 										<< endl;
										errorSemantico=true;
									}
								}
								else{
									cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< $1 << " no existe" << endl; 
	       							errorSemantico=true;
								}
							}	
							errorSemantico=false;
						}
						
						}
	|VARIABLE ASIGNACION exprNum';' 	{if(ejecutar){
							if(!errorSemantico){
								if($3.esReal){
									if(tabla.buscar($1, dato, pos)){
										if(dato.tipo == 1){
											dato.valor.valor_real = $3.valor;
											if(!tabla.modificar(pos, dato.valor)){
												cout<< "Error al modificar" << endl;
											}
										}
										else if(dato.tipo == 0){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo entero y recibe un real" 										<< endl;
											errorSemantico=true;
										}
										else if(dato.tipo == 2){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo logico y recibe un real" 										<< endl;
											errorSemantico=true;
										}
									}
									else{
										cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< $1 << " no existe" << endl; 
		       							errorSemantico=true;
									}
								}
								else{
									if(tabla.buscar($1, dato, pos)){
										if(dato.tipo == 0){
											dato.valor.valor_entero = $3.valor;
											if(!tabla.modificar(pos, dato.valor)){
												cout<< "Error al modificar" << endl;
											}
										}
										else if(dato.tipo == 1){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo real y recibe un entero" 										<< endl;
											errorSemantico=true;
										}
										else if(dato.tipo == 2){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo logico y recibe un entero" 									<< endl;
											errorSemantico=true;
										}
									}
									else{
										cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< $1 << " no existe" << endl; 
		       							errorSemantico=true;
									} 
								}
						}
						errorSemantico=false;
					}
					
					}
	|VARIABLE ASIGNACION PRIMERO'('NOMBRE_LISTA')'  ';'		{if(ejecutar){
										if(tabla.buscar($1, dato, pos)){
											if(strcmp(dato.nomLista, $5)==0){
												tipo_datoLista valorLista; 
												if(list.encontrarLista($5, valorLista)){
													if(valorLista.tipo == 0)
														dato.valor.valor_entero=valorLista.datos[0].valor_entero;
													else if(valorLista.tipo == 1)
														dato.valor.valor_real=valorLista.datos[0].valor_real;
													else if(valorLista.tipo == 2)
														dato.valor.valor_bool=valorLista.datos[0].valor_bool;
													else 
														strcpy(dato.valor.valor_iden, valorLista.datos[0].valor_iden);
													tabla.modificar(pos, dato.valor);
												}
											}
										}
									}
									
									}
	|VARIABLE ASIGNACION ULTIMO'('NOMBRE_LISTA')'  ';'		{if(ejecutar){
										if(tabla.buscar($1, dato, pos)){
											if(strcmp(dato.nomLista, $5)==0){
												tipo_datoLista valorLista;
												if(list.encontrarLista($5, valorLista)){
													if(valorLista.tipo == 0)
														dato.valor.valor_entero=valorLista.datos[valorLista.numDatos-1].valor_entero;
													else if(valorLista.tipo == 1)
														dato.valor.valor_real=valorLista.datos[valorLista.numDatos-1].valor_real;
													else if(valorLista.tipo == 2)
														dato.valor.valor_bool=valorLista.datos[valorLista.numDatos-1].valor_bool;
													else 
														strcpy(dato.valor.valor_iden, valorLista.datos[valorLista.numDatos-1].valor_iden);
													tabla.modificar(pos, dato.valor);
												}
											}
										}
									}
							
									}
	|VARIABLE ASIGNACION ENESIMO'('NOMBRE_LISTA','exprNum')'  ';'	{if(ejecutar){
											if(tabla.buscar($1, dato, pos)){
												if(strcmp(dato.nomLista, $5)==0){
													tipo_datoLista valorLista;
													if(list.encontrarLista($5, valorLista)){
														if(valorLista.tipo == 0)
															dato.valor.valor_entero=valorLista.datos[int($7.valor)-1].valor_entero;
														else if(valorLista.tipo == 1)
															dato.valor.valor_real=valorLista.datos[int($7.valor)-1].valor_real;
														else if(valorLista.tipo == 2)
															dato.valor.valor_bool=valorLista.datos[int($7.valor)-1].valor_bool;
														else 
															strcpy(dato.valor.valor_iden, valorLista.datos[int($7.valor)-1].valor_iden);
														tabla.modificar(pos, dato.valor);
													}
												}
											}
										}
										
										}
	|ESCRIBIR '('secuenciaVal')'';'
	|NUEVALINEA ';' 		{if(ejecutar){
						fprintf(yyout, "cout << endl;\n");
					}
					
					}
	|secInstruc VARIABLE ASIGNACION exprBool';' 	{if(ejecutar){
								if(!errorSemantico){
									if(tabla.buscar($2, dato, pos)){
										if(dato.tipo == 2){
											dato.valor.valor_bool = $4;
											if(!tabla.modificar(pos, dato.valor)){
												cout<< "Error al modificar" << endl;
											}
										}
										else if(dato.tipo == 0){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo entero y recibe un logico" 									<< endl;
											errorSemantico=true;
										}
										else if(dato.tipo == 1){
											cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo real y recibe un logico" 										<< endl;
											errorSemantico=true;
										}
									}
									else{
										cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< $2 << " no existe" << endl; 
		       							errorSemantico=true;
										}
								}	
								errorSemantico=false;
							}
							
							}
							
	|secInstruc VARIABLE ASIGNACION exprNum';' 	{if(ejecutar){
								if(!errorSemantico){
									if($4.esReal){
										if(tabla.buscar($2, dato, pos)){
											if(dato.tipo == 1){
												dato.valor.valor_real = $4.valor;
												if(!tabla.modificar(pos, dato.valor)){
													cout<< "Error al modificar" << endl;
												}
											}
											else if(dato.tipo == 0){
												cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo entero y recibe un real" 										<< endl;
												errorSemantico=true;
											}
											else if(dato.tipo == 2){
												cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo logico y recibe un real" 										<< endl;
												errorSemantico=true;
											}
										}
										else{
											cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< $2 << " no existe" << endl; 
			       							errorSemantico=true;
										}
									}
									else{
										if(tabla.buscar($2, dato, pos)){
											if(dato.tipo == 0){
												dato.valor.valor_entero = $4.valor;
												if(!tabla.modificar(pos, dato.valor)){
													cout<< "Error al modificar" << endl;
												}
											}
											else if(dato.tipo == 1){
												cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo real y recibe un entero" 										<< endl;
												errorSemantico=true;
											}
											else if(dato.tipo == 2){
												cout << "Error semantico en la instruccion " << n_lineas-1 << " " << dato.identificador<< " es de tipo logico y recibe un entero" 									<< endl;
												errorSemantico=true;
											}
										}
										else{
											cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< $2 << " no existe" << endl; 
			       							errorSemantico=true;
										} 
									}
								}
								errorSemantico=false;
							}
							
							}
	|secInstruc VARIABLE ASIGNACION PRIMERO'('NOMBRE_LISTA')'  ';'		{if(ejecutar){
												if(tabla.buscar($2, dato, pos)){
													if(strcmp(dato.nomLista, $6)==0){
														tipo_datoLista valorLista;
														if(list.encontrarLista($6, valorLista)){
															if(valorLista.tipo == 0)
																dato.valor.valor_entero=valorLista.datos[0].valor_entero;
															else if(valorLista.tipo == 1)
																dato.valor.valor_real=valorLista.datos[0].valor_real;
															else if(valorLista.tipo == 2)
																dato.valor.valor_bool=valorLista.datos[0].valor_bool;
															else 
																strcpy(dato.valor.valor_iden, valorLista.datos[0].valor_iden);
															tabla.modificar(pos, dato.valor);
														}
													}
												}
											}
											
											}
											
	|secInstruc VARIABLE ASIGNACION ULTIMO'('NOMBRE_LISTA')'  ';'		{if(ejecutar){
												if(tabla.buscar($2, dato, pos)){
													if(strcmp(dato.nomLista, $6)==0){
														tipo_datoLista valorLista;
														if(list.encontrarLista($6, valorLista)){
															if(valorLista.tipo == 0)
																dato.valor.valor_entero=valorLista.datos[valorLista.numDatos-1].valor_entero;
															else if(valorLista.tipo == 1)
																dato.valor.valor_real=valorLista.datos[valorLista.numDatos-1].valor_real;
															else if(valorLista.tipo == 2)
																dato.valor.valor_bool=valorLista.datos[valorLista.numDatos-1].valor_bool;
															else 
																strcpy(dato.valor.valor_iden, valorLista.datos[valorLista.numDatos-1].valor_iden);
															tabla.modificar(pos, dato.valor);
														}
													}
												}
											}
											
											}
	|secInstruc VARIABLE ASIGNACION ENESIMO'('NOMBRE_LISTA','exprNum')'  ';'	{if(ejecutar){
												if(tabla.buscar($2, dato, pos)){
													if(strcmp(dato.nomLista, $6)==0){
														tipo_datoLista valorLista;
														if(list.encontrarLista($6, valorLista)){
															if(valorLista.tipo == 0)
																dato.valor.valor_entero=valorLista.datos[int($8.valor)-1].valor_entero;
															else if(valorLista.tipo == 1)
																dato.valor.valor_real=valorLista.datos[int($8.valor)-1].valor_real;
															else if(valorLista.tipo == 2)
																dato.valor.valor_bool=valorLista.datos[int($8.valor)-1].valor_bool;
															else 
																strcpy(dato.valor.valor_iden, valorLista.datos[int($8.valor)-1].valor_iden);
															tabla.modificar(pos, dato.valor);
														}
													}
												}
											}
											
											}
	|secInstruc ESCRIBIR '('secuenciaVal')'';'
	|secInstruc NUEVALINEA ';' 		{if(ejecutar){
							fprintf(yyout, "cout << endl;\n");
						}
						
						}
	;
listaNum: exprNum			{if(!errorSemantico){
						if(contLis == 0){
							if($1.esReal){
								datosLis.tipo = 1;
								datosLis.datos[contLis].valor_real = $1.valor;
								contLis++;
							}
							else{
								datosLis.tipo = 0;
								datosLis.datos[contLis].valor_entero = $1.valor;
								contLis++;
							}
						}
						else{
							if(datosLis.tipo == 0){
								if($1.esReal){
									cout<< "Error semántico en la instrucción "<< n_lineas << ": no se pueden introducir elementos de distinto tipo del de la lista" 										<< endl; 	
       								errorSemantico=true;
								}
								else{
									datosLis.datos[contLis].valor_entero = $1.valor;
									contLis++;
								}
							}
							else if(datosLis.tipo==1){
								if(!$1.esReal){
									cout<< "Error semántico en la instrucción "<< n_lineas << ": no se pueden introducir elementos de distinto tipo del de la lista" 										<< endl; 	
       								errorSemantico=true;
								}
								else{
									datosLis.datos[contLis].valor_real = $1.valor;
									contLis++;
								}
							}
						}
					}
					}
	|listaNum ',' exprNum		{if(!errorSemantico){
						if(contLis == 0){
							if($3.esReal){
								datosLis.tipo = 1;
								datosLis.datos[contLis].valor_real = $3.valor;
								contLis++;
							}
							else{
								datosLis.tipo = 0;
								datosLis.datos[contLis].valor_entero = $3.valor;
								contLis++;
							}
						}
						else{
							if(datosLis.tipo == 0){
								if($3.esReal){
									cout<< "Error semántico en la instrucción "<< n_lineas << ": no se pueden introducir elementos de distinto tipo del de la lista" 										<< endl; 	
       								errorSemantico=true;
								}
								else{
									datosLis.datos[contLis].valor_entero = $3.valor;
									contLis++;
								}
							}
							else if(datosLis.tipo==1){
								if(!$3.esReal){
									cout<< "Error semántico en la instrucción "<< n_lineas << ": no se pueden introducir elementos de distinto tipo del de la lista" 										<< endl; 	
       								errorSemantico=true;
								}
								else{
									datosLis.datos[contLis].valor_real = $3.valor;
									contLis++;
								}
							}
						}
					}
					}
	;
listaLog: exprBool			{if(!errorSemantico){
						datosLis.datos[contLis].valor_bool = $1;
						contLis++;
					}
					}
	|listaLog ',' exprBool		{if(!errorSemantico){
						datosLis.datos[contLis].valor_bool = $3;
						contLis++;
					}}
	;
secuenciaVal:VARIABLE			{if(ejecutar){
						if(!errorSemantico){
							if(tabla.buscar($1, dato, pos)){
								if(dato.tipo == 0)
									
									fprintf(yyout, "%s %d %s", "cout <<", dato.valor.valor_entero , ";\n");
								else if(dato.tipo == 1)
									fprintf(yyout, "%s %f %s", "cout <<", dato.valor.valor_real , ";\n");
								else if(dato.tipo == 2){
									if(dato.valor.valor_bool)
										fprintf(yyout, "cout << true;\n");
									else
										fprintf(yyout, "cout << false;\n");
								}
								else
									fprintf(yyout, "%s %s %s", "cout <<", dato.valor.valor_iden , ";\n");
							}
							else{
	       						cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< $1 << " no existe" << endl; 
	       						errorSemantico=true;
	       					}
						}
					}
					
					}
	|exprNum			{if(ejecutar){
						if(!errorSemantico){
							if($1.esReal)
								fprintf(yyout, "%s %f %s", "cout <<", $1.valor, ";\n");
							else
								fprintf(yyout, "%s %d %s", "cout <<", int($1.valor), ";\n");
						}
					}
					
					}
	|CADENA_CARACT			{if(ejecutar){
						if(!errorSemantico){
							fprintf(yyout, "%s %s %s", "cout <<", $1, ";\n");
						}
					}
					
					}
					
	|PRIMERO'('NOMBRE_LISTA')'	{if(ejecutar){
						tipo_datoLista valorLista;
						if(list.encontrarLista($3, valorLista)){
							if(valorLista.tipo == 0)
								fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[0].valor_entero , ";\n");
							else if(valorLista.tipo == 1)
								fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[0].valor_real , ";\n");
							else if(valorLista.tipo == 2){
								if(valorLista.datos[0].valor_bool)
									fprintf(yyout, "cout << true;\n");
								else
									fprintf(yyout, "cout << false;\n");
							}
							else 
								fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[0].valor_iden , ";\n");
						}
					}
					
					}
	|ULTIMO'('NOMBRE_LISTA')'	{if(ejecutar){
						tipo_datoLista valorLista;
						if(list.encontrarLista($3, valorLista)){
							if(valorLista.tipo == 0)
								fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_entero , ";\n");
							else if(valorLista.tipo == 1)
								fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_real , ";\n");
							else if(valorLista.tipo == 2){
								if(valorLista.datos[valorLista.numDatos-1].valor_bool)
									fprintf(yyout, "cout << true;\n");
								else
									fprintf(yyout, "cout << false;\n");
							}
							else 
								fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_iden , ";\n");
						}
					}
					
					}
					
	|ENESIMO'('NOMBRE_LISTA','exprNum')'	{if(ejecutar){
							tipo_datoLista valorLista;
							if(list.encontrarLista($3, valorLista)){
								if(valorLista.tipo == 0)
									fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[int($5.valor)-1].valor_entero , ";\n");
								else if(valorLista.tipo == 1)
									cout<<"cout << " << valorLista.datos[int($5.valor)-1].valor_real <<endl;
								else if(valorLista.tipo == 2){
									if(valorLista.datos[int($5.valor-1)].valor_bool)
										
										fprintf(yyout, "cout << true;\n");
									else
										
										fprintf(yyout, "cout << false;\n");
								}
								else 
									fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[int($5.valor)-1].valor_iden , ";\n");
							}
						}
						
						}
						
	|secuenciaVal ',' VARIABLE			{if(ejecutar){
								if(!errorSemantico){
									if(tabla.buscar($3, dato, pos)){
										if(dato.tipo == 0)
											fprintf(yyout, "%s %d %s", "cout <<", dato.valor.valor_entero , ";\n");
										else if(dato.tipo == 1)
											fprintf(yyout, "%s %f %s", "cout <<", dato.valor.valor_real , ";\n");
										else if(dato.tipo == 2){
											if(dato.valor.valor_bool)
												fprintf(yyout, "cout << true;\n");
											else
												fprintf(yyout, "cout << false;\n");
										}
										else
											fprintf(yyout, "%s %s %s", "cout <<", dato.valor.valor_iden , ";\n");
									}
									else{
			       						cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< $3 << " no existe" << endl; 
			       						errorSemantico=true;
			       					}
								}
							}
							
							}
							
	|secuenciaVal ',' exprNum			{if(ejecutar){
								if(!errorSemantico){
									if($3.esReal)
										fprintf(yyout, "%s %f %s", "cout <<", $3.valor, ";\n");
									else
										fprintf(yyout, "%s %d %s", "cout <<", int($3.valor), ";\n");
								}
							}
							
							}
							
	|secuenciaVal ',' CADENA_CARACT		{if(ejecutar){
								if(!errorSemantico){
									fprintf(yyout, "%s %s %s", "cout <<", $3, ";\n");
								}
							}
							
							}
							
	|secuenciaVal ',' PRIMERO'('NOMBRE_LISTA')'	{if(ejecutar){
								tipo_datoLista valorLista;
								if(list.encontrarLista($5, valorLista)){
									if(valorLista.tipo == 0)
										fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[0].valor_entero , ";\n");
									else if(valorLista.tipo == 1)
										fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[0].valor_real , ";\n");
									else if(valorLista.tipo == 2){
										if(valorLista.datos[0].valor_bool)
											fprintf(yyout, "cout << true;\n");
										else
											fprintf(yyout, "cout << false;\n");
									}
									else 
										fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[0].valor_iden , ";\n");
								}
							}
							
							}
							
	|secuenciaVal ',' ULTIMO'('NOMBRE_LISTA')'	{if(ejecutar){
								tipo_datoLista valorLista;
								if(list.encontrarLista($5, valorLista)){
									if(valorLista.tipo == 0)
										fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_entero, ";\n");
									else if(valorLista.tipo == 1)
										fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_real, ";\n");
									else if(valorLista.tipo == 2){
										if(valorLista.datos[valorLista.numDatos-1].valor_bool)
											fprintf(yyout, "cout << true;\n");
										else
											fprintf(yyout, "cout << false;\n");
									}
									else 
										fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[valorLista.numDatos-1].valor_iden, ";\n");
								}
							}
							
							}
							
	|secuenciaVal ',' ENESIMO'('NOMBRE_LISTA','exprNum')'	{if(ejecutar){
										tipo_datoLista valorLista;
										if(list.encontrarLista($5, valorLista)){
											if(valorLista.tipo == 0)
												fprintf(yyout, "%s %d %s", "cout <<", valorLista.datos[int($7.valor)-1].valor_entero, ";\n");
											else if(valorLista.tipo == 1)
												fprintf(yyout, "%s %f %s", "cout <<", valorLista.datos[int($7.valor)-1].valor_real, ";\n");
											else if(valorLista.tipo == 2){
												if(valorLista.datos[int($7.valor-1)].valor_bool)
													fprintf(yyout, "cout << true;\n");
												else
													fprintf(yyout, "cout << false;\n");
											}
											else 
												fprintf(yyout, "%s %s %s", "cout <<", valorLista.datos[int($7.valor)-1].valor_iden, ";\n");
										}
									}
									
									}
	;
exprNum:    ENTERO 	       	{$$.valor=$1;
					$$.esReal=false;}
       | REAL                 	{$$.valor=$1;
       				$$.esReal=true;} 
       | VARIABLE			{if(tabla.buscar($1, dato, pos)){
       					if(dato.tipo == 0){
       						$$.valor = dato.valor.valor_entero;
       						$$.esReal = false;
       					}
       					else if(dato.tipo == 1){
       						$$.valor = dato.valor.valor_real;
       						$$.esReal = true;
       					}
       					else{
       						cout<< "Error semántico en la instrucción "<< n_lineas << ": no se permiten variables de tipo lógico a la derecha de la igualdad" << endl; 
       						errorSemantico=true;
       					}
       				}
       				else{
       					cout<< "Error semántico en la instrucción "<< n_lineas << ": la variable "<< $1 << " no existe" << endl; 
       					errorSemantico=true;
       				}
       				}   
       | exprNum '+' exprNum        	{$$.valor=$1.valor+$3.valor;
       				$$.esReal=$1.esReal||$3.esReal;}              
       | exprNum '-' exprNum        	{$$.valor=$1.valor-$3.valor;
       				$$.esReal=$1.esReal||$3.esReal;}            
       | exprNum '*' exprNum        	{$$.valor=$1.valor*$3.valor;
       				$$.esReal=$1.esReal||$3.esReal;}
       | exprNum '/' exprNum        	{$$.esReal=$1.esReal||$3.esReal;
       				if($3.valor!=0){
       					if($$.esReal)
       						$$.valor=$1.valor/$3.valor;
       					else
       						$$.valor=int($1.valor)/int($3.valor);
       				}
       				else{
       					cout<< "Error semántico en la instrucción "<< n_lineas << ": división por cero" << endl; 
       					errorSemantico=true;
       				}
       				}
       | exprNum '%' exprNum        	{if($1.esReal||$3.esReal){
       					cout<< "Error semántico en la instrucción "<< n_lineas << ": se usa la operación % con operandos reales" << endl; 
       					errorSemantico=true;
       				}
       				else{
       					if($3.valor!=0){
       						$$.valor=int($1.valor)%int($3.valor);
       					}
       					else{
       						cout<< "Error semántico en la instrucción "<< n_lineas << ": modulo de division por cero" << endl; 
       						errorSemantico=true;	
       					}
       				}
       				$$.esReal=false;}  
       |'-' exprNum %prec menos  	{$$.valor=-$2.valor;
					$$.esReal=$2.esReal;}
       |'(' exprNum ')'		{$$.valor=$2.valor;
					$$.esReal=$2.esReal;}
       ;
exprBool: BOOL				{$$=$1;}
	|'(' exprBool ')'		{$$=$2;}
	| exprNum '<' exprNum		{$$=$1.valor<$3.valor;}
	| exprNum '>' exprNum		{$$=$1.valor>$3.valor;}
	| exprNum COMP_ARIT1 exprNum	{$$=$1.valor<=$3.valor;}
	| exprNum COMP_ARIT2 exprNum	{$$=$1.valor>=$3.valor;}
	| exprNum COMP_IGUAL exprNum	{$$=$1.valor==$3.valor;}
	| exprNum COMP_DIST exprNum	{$$=$1.valor!=$3.valor;}
	| exprBool COMP_IGUAL exprBool {$$=$1==$3;}
	| exprBool COMP_DIST exprBool	{$$=$1!=$3;}
	| exprBool COMP_Y exprBool	{$$=$1&&$3;}
	| exprBool COMP_O exprBool	{$$=$1||$3;}
	| COMP_NO exprBool		{$$=!$2;}
	;

%%

int main(int argc, char *argv[]){
     
     n_lineas = 1;
     int i = 0;
     int numDatos = 0;
     tipo_datoTS dato;
     
     yyin = fopen(argv[1],"rt");
     yyout = fopen(argv[2], "wt");
     
     
     fprintf(yyout, "%s %s %s %s","#include <iostream>\n","using namespace std;\n","int main(){\n","\n // Inicio del bloque de código\n");
     yyparse();
      fprintf(yyout, "%s %s %s ","// Final del bloque de código\n","\nreturn 0;\n","}\n");
     	
     fclose(yyin);
     fclose(yyout);
     return 0;
}
