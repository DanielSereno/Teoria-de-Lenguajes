#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
using namespace std;

typedef char tipo_cadena [25];


union tipo_valorLista{
	int		valor_entero;
	float		valor_real;
	bool		valor_bool;
	tipo_cadena	valor_iden;
};

struct tipo_datoLista{
	tipo_cadena	identificador;
	tipo_valorLista datos [50];
	int tipo;
	int numDatos;
};

class lista{
	
	private:
	
		tipo_datoLista listas[20];
		int numDatos;
		
	public:
	
		lista();
		bool insertar(tipo_datoLista valor);
		bool encontrarLista(tipo_cadena identificador, tipo_datoLista &lista);
};
