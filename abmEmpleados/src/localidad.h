/*
 * localidad.h
 *
 *  Created on: 9 oct. 2021
 *      Author: MAIA
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

typedef struct{
	int id;
	char descripcion[20];
} eLocalidad;

#endif /* LOCALIDAD_H_ */

int cargarDescripcionLocalidad(eLocalidad localidades[], int tam, int idLocalidad, char descripcion[]);

int mostrarLocalidades(eLocalidad localidades[], int tam);

int validarIdLocalidad(eLocalidad localidades[], int tam, int id);

