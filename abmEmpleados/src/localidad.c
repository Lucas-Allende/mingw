/*
 * localidad.c
 *
 *  Created on: 9 oct. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "localidad.h"

int cargarDescripcionLocalidad(eLocalidad localidades[], int tam, int idLocalidad, char descripcion[]){

	int excelente = 0;

	if(localidades != NULL && tam > 0 && descripcion != NULL){

		for(int i = 0; i < tam; i++){

			if(localidades[i].id == idLocalidad){
				strcpy(descripcion, localidades[i].descripcion);//ENCUENTRA LOCALIDAD QUE TIENE ID
				break;
			}
		}

		excelente = 1;
	}

	return excelente;

}


int mostrarLocalidades(eLocalidad localidades[], int tam){

	int excelente = 0;

	if(localidades != NULL && tam > 0){

		printf(" ---------- LOCALIDADES-------------\n");
		printf("                ID                   DESCRIPCIONES\n");

		for(int i = 0; i < tam; i++){
			printf("        %d               %s\n", localidades[i].id, localidades[i].descripcion);

		}
		printf("\n\n");

		excelente = 1;
	}


	return excelente;
}


int validadIdLocalidad(eLocalidad localidades[], int tam, int id){
	int existe = 0;

	if(localidades != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			if(localidades[i].id == id){
				existe = 1;
				break;
			}
		}
	}


	return existe;
}
