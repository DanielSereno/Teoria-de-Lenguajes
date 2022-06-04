#include "lista.h"

lista:: lista(){
	numDatos=0;
}

bool lista:: insertar(tipo_datoLista valor){
	int i=0;
	if(numDatos > 20){
		return false;
	}
	else{
		strcpy(listas[numDatos].identificador, valor.identificador);
		listas[numDatos].numDatos = valor.numDatos;
		listas[numDatos].tipo = valor.tipo;
		while(i < valor.numDatos){
			if(valor.tipo == 0){
				listas[numDatos].datos[i].valor_entero = valor.datos[i].valor_entero;
			}
			else if(valor.tipo == 1){
				listas[numDatos].datos[i].valor_real = valor.datos[i].valor_real;
			}
			else if(valor.tipo == 2){
				listas[numDatos].datos[i].valor_bool = valor.datos[i].valor_bool;
			}
			else{ 
				strcpy(listas[numDatos].datos[i].valor_iden, valor.datos[i].valor_iden);
			}
			i++;
		}
		numDatos++;
		return true;
	}
}

bool lista:: encontrarLista(tipo_cadena identificador, tipo_datoLista &lista){
	int i=0;
	int j=0;
	bool encontrado = false;
	while(i < numDatos && !encontrado){
		if(strcmp(listas[i].identificador, identificador)==0){
			encontrado = true;
			strcpy(lista.identificador, listas[i].identificador);
			lista.numDatos = listas[i].numDatos;
			lista.tipo = listas[i].tipo;
			while(j < lista.numDatos){
				if(lista.tipo == 0)
					lista.datos[j].valor_entero = listas[i].datos[j].valor_entero;
				else if(lista.tipo == 1)
					lista.datos[j].valor_real = listas[i].datos[j].valor_real;
				else if(lista.tipo == 2)
					lista.datos[j].valor_bool = listas[i].datos[j].valor_bool;
				else 
					strcpy(lista.datos[j].valor_iden, listas[i].datos[j].valor_iden);
				j++;
			}
		}
		i++;
	}
	return encontrado;
}

