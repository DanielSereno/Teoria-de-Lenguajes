#fichero Makefile
#Juan Romo González
#Daniel Sereno Fernández

OBJ = expresiones.o lexico.o

salida: calculadora basica.list 
	./calculadora basica.list salida.cpp

calculadora : $(OBJ) tabla.c lista.c   				#segunda fase de la traducción. Generación del código ejecutable 
	g++ -ocalculadora $(OBJ) tabla.c lista.c

expresiones.o : expresiones.c       	#primera fase de la traducción del analizador sintáctico
	g++ -c -oexpresiones.o  expresiones.c 
	
lexico.o : lex.yy.c						#primera fase de la traducción del analizador léxico
	g++ -c -olexico.o  lex.yy.c 
structura.o : structura.c	
	g++ -c -ostructura.o structura.c 

expresiones.c : expresiones.y       	#obtenemos el analizador sintáctico en C
	bison -d -oexpresiones.c expresiones.y

lex.yy.c: lexico.l						#obtenemos el analizador léxico en C
	flex lexico.l

clean : 
	rm  -f  *.c *.o 
