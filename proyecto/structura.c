#include "structura.h"

identificador:: identificador(){
	num_datos = 0;
}

int identificador:: getLinea(int posicion){
	int lin=0;
	if(posicion < num_datos){
		lin = identificadores[posicion].linea;
	}
	return lin;
}

string identificador:: getNombre(int posicion){
	string nom="error";
	if(posicion < num_datos){
		nom = identificadores[posicion].nombre;
	}
	return nom;
}

void identificador:: insertar(string nombre, int linea){
	if(num_datos > 0){
		int i=0;
		bool encontrado= false;
		while (i < num_datos && !encontrado){
			if(identificadores[i].nombre.compare(nombre) == 0){
				encontrado= true;
			}
			i ++;
		}
		if(!encontrado){
			identificadores[i].nombre= nombre;
			identificadores[i].linea= linea;
			num_datos ++;
		}
	}
	else{
		identificadores[0].nombre= nombre;
		identificadores[0].linea= linea;
		num_datos ++;
	}
}

void identificador:: escribirFichero(string nombre_fichero, int linea){


	ofstream flujo;
	flujo.open(nombre_fichero);
	if(!flujo.is_open()){
		cout<< "Error al abrir el fichero"<<endl;
	}else{
		flujo<<"Lista de identificadores:\n";
		for(int i = 0; i < num_datos; i++){
			flujo << identificadores[i].nombre << "              " << identificadores[i].linea << endl;
		}
		flujo<<"Número total de líneas del fichero de entrada: "<<linea<<endl;
		flujo.close();
	}
	






}
