/*
 * comida.c
 *
 *  Created on: 18 oct. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#include "localidad.h"
#include  "comida.h"

int mostrarComidas(eComida comidas[], int tam)
{

	int excelente = 0;

	if(comidas != NULL && tam > 0){

		printf(" ---------------------------- COMIDAS--------------------\n");
		printf("                ID                   DESCRIPCIONES               PRECIOS\n");
		printf("---------------------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++){
			printf(" %d     %s    %f\n", comidas[i].id, comidas[i].descripcion, comidas[i].precio);

		}
		printf("\n\n");

		excelente = 1;
	}


	return excelente;
}



int validadIdComida(eComida comidas[], int tamc, int id){
	int existe = 0;

	if(comidas != NULL && tamc > 0){
		for(int i = 0; i < tamc; i++){
			if(comidas[i].id == id){
				existe = 1;
				break;
			}
		}
	}


	return existe;
}
