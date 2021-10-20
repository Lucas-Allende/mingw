/*
 * dataWarehouse.c
 *
 *  Created on: 8 oct. 2021
 *      Author: MAIA
 */
#include "dataWarehouse.h"
#include <string.h>

char nombres[10][20] = {
		"Juan",
		"Pedro",
		"Sofia",
		"Miguel",
		"Valentina",
		"Camila",
		"Andrea",
		"Luis",
		"Diego",
		"Analia"};

char sexos[10] = {'m','m','f', 'm', 'f','f', 'f','m','m','f'};
int edades[10] = { 23, 21, 28,31,45,29,39,23,28,27 };

float alturas[10] = {1.65, 1.67, 1.9, 1.78, 1.75, 1.7, 1.65, 1.73, 1.69, 1.53};

int idLocalidades[10] = {1000, 1002, 1000, 1001, 1001, 1003, 1004, 1002, 1004, 1001};


int hardCodearPersonas(ePersona lista[], int tam, int cantidad, int* pId){

	int contador = -1;

	if(lista != NULL && tam > 0 && cantidad >= 0 && cantidad <= tam && pId != NULL){
		contador = 0;

		for(int i = 0; i < tam; i++){

			lista[i].id = *pId;
			(*pId)++;

		  strcpy(lista[i].nombre, nombres[i]);
		  lista[i].sexo = sexos[i];
		  lista[i].edad = edades[i];
		  lista[i].altura = alturas[i];
		  lista[i].idLocalidad = idLocalidades[i];
		  lista[i].isEmpty = 0;

		  contador++;
		}
	}

	return contador;
}
