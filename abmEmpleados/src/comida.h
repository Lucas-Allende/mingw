/*
 * comida.h
 *
 *  Created on: 18 oct. 2021
 *      Author: MAIA
 */

#ifndef COMIDA_H_
#define COMIDA_H_

typedef struct {
	int id;
	char descripcion;
	float precio;

}eComida;

#endif /* COMIDA_H_ */

int mostrarComidas(eComida comidas[], int tam);

int validadIdComida(eComida comidas[], int tamc, int id);
