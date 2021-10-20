/*
 * almuerzo.h
 *
 *  Created on: 18 oct. 2021
 *      Author: MAIA
 */

#ifndef ALMUERZO_H_
#define ALMUERZO_H_
#include "fecha.h"
#include "personas.h"
#include "localidad.h"
#include  "comida.h"

typedef struct {
	int id;
	int idPersona;
	int idComida;
	eFecha fecha;
	int isEmpty;
}eAlmuerzo;

#endif /* ALMUERZO_H_ */

int inicializarAlmuerzo(eAlmuerzo almuerzos[], int tam); //INICIALIZA EL CAMPO ISEMPTY EN 1 DE TODAS LAS PESONA

int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam); //RETORNA EL INDICE DE LA PRIMER ESTRUCTURA LIBRE O TAMBIEN  -1

int altaAlmuerzo(eAlmuerzo almuerzos[], int tama, ePersona lista[] , int tam, eLocalidad localidades[], int tamLocalidades, eComida comidas[], int tamc, int* pIdAlmuerzo);

int mostrarAlmuerzos(eAlmuerzo almuerzos[], int tama, ePersona lista[] , eLocalidad localidades[], int tamLocalidades, eComida comidas[], int tamc);

void mostrarAlmuerzo(eAlmuerzo unAlmuerzo);




