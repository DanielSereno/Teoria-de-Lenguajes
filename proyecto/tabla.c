#include "tabla.h"

tablaSim:: tablaSim(){
	numDatos=0;
}

bool tablaSim:: insertar(tipo_datoTS dato){
	bool insertado=false;
	if(numDatos <100){
		strcpy(datos[numDatos].identificador, dato.identificador);
		datos[numDatos].tipo= dato.tipo;
		if(dato.tipo == 3){
			strcpy(datos[numDatos].valor.valor_iden, dato.valor.valor_iden);
		}
		else
			datos[numDatos].valor= dato.valor;
		strcpy(datos[numDatos].nomLista, dato.nomLista);
		numDatos++;
		insertado=true;
	}
	return insertado;
}

bool tablaSim:: buscar(tipo_cadena nombre, tipo_datoTS &dato, int &pos){
	bool encontrado=false;
	int i=0;
	while(i < numDatos && !encontrado){
		if(strcmp(nombre, datos[i].identificador) == 0){
			encontrado = true;
			strcpy(dato.identificador, datos[i].identificador);
			strcpy(dato.nomLista, datos[i].nomLista);
			dato.tipo= datos[i].tipo;
			if(dato.tipo == 3)
				strcpy(dato.valor.valor_iden, datos[i].valor.valor_iden);
			else
				dato.valor= datos[i].valor;
			pos = i;
		}
		i++; 
	}
	return encontrado;
}

void tablaSim:: buscarPos(int pos, tipo_datoTS &dato){
	strcpy(dato.identificador, datos[pos].identificador);
	dato.tipo= datos[pos].tipo;
	if(dato.tipo == 3)
		strcpy(dato.valor.valor_iden, datos[pos].valor.valor_iden);
	else
		dato.valor= datos[pos].valor;
}

bool tablaSim:: modificar(int pos, tipo_valor valor){
	bool modificado=false;
	if(pos < numDatos){
		if(datos[pos].tipo == 3)
			strcpy(datos[pos].valor.valor_iden, valor.valor_iden);
		else if(datos[pos].tipo == 0){
			datos[pos].valor.valor_entero = valor.valor_entero;
		}
		else if(datos[pos].tipo == 1)
			datos[pos].valor.valor_real = valor.valor_real;
		else 
			datos[pos].valor.valor_bool = valor.valor_bool;
		modificado = true;
	}
	return modificado;
}

int tablaSim:: getnumDatos(){
	return numDatos;
}
