#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct datos {
	string nombre;
	int linea;	
};

class identificador{
	
	private:
	
	datos identificadores [100];
	int num_datos;
	
	public:
	
		identificador();
	
		string getNombre(int posicion);
		
		int getLinea(int posicion);
		
		void insertar(string nombre, int linea);
		
		void escribirFichero(string nombre_fichero, int linea);
		

};
