#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
using namespace std;

typedef char tipo_cadena [25];

union tipo_valor{
	int		valor_entero;
	float		valor_real;
	bool		valor_bool;
	tipo_cadena	valor_iden;
};

struct tipo_datoTS{
	tipo_cadena	identificador;
	int		tipo;
	tipo_valor	valor;
	tipo_cadena 	nomLista;
};


class tablaSim{
	
	private:
	
		tipo_datoTS datos [100];
		int numDatos;
		
	public:
	
		tablaSim();
		bool insertar(tipo_datoTS dato);
		bool buscar(tipo_cadena nombre, tipo_datoTS &dato, int &pos);
		void buscarPos(int pos, tipo_datoTS &dato);
		bool modificar(int pos, tipo_valor valor);
		int getnumDatos();
};
