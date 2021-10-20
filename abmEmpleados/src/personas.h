/*
 * persona.h
 *
 *  Created on: 6 oct. 2021
 *      Author: MAIA
 */

#ifndef PERSONAS_H_
#define PERSONAS_H_
#include "localidad.h"


typedef struct {    //DEFINICION DE ESTRUCTURAS VA EN BIBLIOTECA.H
	int id;
	char nombre[20];
	char sexo;
	int edad;
	float altura;
	int idLocalidad;
	int isEmpty; // ES UN TIPO DE BANDERA
}ePersona;

#endif /* PERSONA_H_ */

int menu();
int inicializarPersona(ePersona lista[], int tam); //INICIALIZA EL CAMPO ISEMPTY EN 1 DE TODAS LAS PESONA

int buscarLibre(ePersona lista[], int tam); //RETORNA EL INDICE DE LA PRIMER ESTRUCTURA LIBRE O TAMBIEN  -1
int altaPersona(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades, int* pId); // UNO SI DIO D ALTA A PERSONA - 0 SI HUBO PROBLEMA
int mostrarPersonas(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades);

void mostrarPersona(ePersona unaPersona, eLocalidad localidades[], int tamLocalidades);

int buscarPersonaId(ePersona lista[], int tam, int id);

int bajaPersona(ePersona lista[], int tam,  eLocalidad localidades[], int tamLocalidades);
int modificarPersona(ePersona lista[], int tam,  eLocalidad localidades[], int tamLocalidades);
int menuModificacion();
int ordenarPersonas(ePersona lista[], int tam);

int mostrarMujeres(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades); //SOLO TIENE QUE MOSTRAR PERSONAS DE SEXO FEMENINO
int informePersonasLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades);
int mostrarPersonasIdLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades, int idLocalidad);
int informePersonasAllLocalidades(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades);

int promedioEdadVaronesLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades);

int informePersonaMasAltaLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades);

int localidadMujerJoven(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades);

int cantidadPersonasLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades);
int localidadMasHabitada(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades);


