/*
 ============================================================================
 Name        : EJEMPLO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#include "localidad.h"
#include  "comida.h"
#include "almuerzo.h"

#define TAM 10
#define TAM_LOC 5
#define TAM_C 5
#define TAM_A 50
//PARA HACER ALTA A ALGUIEN, HAY QUE BUSCAR LIBRE, SI HAY LUGAR O NO (CO FUNCION BUSCARLIBRE). PUEDE DEVOLVER INDICE DE LUGAR QUE ESTE LIBRE
//SI FUNCION DEVUELVE -1 NO HAY LUGAR
//CUANDO SE NCUENTRA LUGAR LIBRE SE PIDE DATOS Y SE GUARDAN EN INDICE LIBRE
//PARA QUE LUGAR NO ESTE MAS LIBRE ISEMPTY TIENE QUE CAMBIAR VALOR A 0 (ESTRUCTURA NO ESTA DISPONIBLE)
//LA HACER BAJA LOGICA EN ESTRUCTURA SE HACE BAJA DE PERSOINAS EN ESTRUCTURA
//CON BANDERA ISEMPTY SE TIENE EN CUENTA O NO, SE HACE UNA BAJA LOGICA

//DAR DE BAJA Y MODIFICAR SON CASI LO MISMO EL ALGORITMO (CODIGP):
//SE TIENE QUE PEDIR ID (PARA SABER QUIEN SE DA DE BAJA Y SI EXISTE O NO EL ID),
//SE NECESITA FUNCION BUSCAR PERSONA, CON EL ID QUE SE VA A DAR DE BAJA

//DEBERIA DEVOLVER INDICE EN DONDE ESTA ESA PERSONA O -1.
// AL SABER EN QUE INDICE ESTA SE DEBE IR A BUSCAR ESA PERSONA.


// FUNCION BUSCARPERSONA DEVUELVE INDICE EN DONDE ESTA LA PERSONA QUE TIENE ESE ID. O -1 SI NO ESTA.
//BUSCAR PERSONA RESIVE----> LISTA TAMÑO Y ID COMO PARAMETRO.
//TIENE QUE BUSCAR EN PERSONA QUE TENGA ISEMPTY EN 0. (ES IMPORTANTE QUE ESTE EN 0)
//TENGO QUE DEVOLVER UBICACIOND E PERSONA QUE TIENE ESE ID Y ESTA DADA DE ALTA EN EL SISTEMA
//SI LO QUE DEVUELVE ES -1 , SE INFORMA QUE NO EXISTE ESE ID, SI EXISTE ES PORQUE TENEMOSINDICE EN DONDE ESTA UBICADA
//SI EXISTE SE MUESTRA LA PERSONA, CON FUNCION MOSTRAR PERSONA PARA PEDIR CONFIRMACION DE BORRADO EN EL SISTEMA.
// SI NO CONFIRMA , NO PASA NADA . SI CONFIRMA DAR DE BAJA A LA PERSONA. , SE CAMBIA ISEMPTY A 1. == SE DA DE BAJA.

//EN BAJA SOLO SE PERMITE CONFIRMA BORRADO ;
//EN MOSTRAR PERSONA SE HACE SUB MENU!! , PREGUNTA QUE SE QUIERE MODIFICAR; SEXO , EDAD O ALTURA.  (EJ CON SWITCH PARA CADA CASO)

//SE PUEDE AGREGAR MENU PARA PREGUNTAR COMO SE QUIERE ORDENAR , DEPSUES SE LLAMA FNCION LISTAR PERSONAS QUE ESTAN DADAS DE ALTA.


//TAREA
//HACER BUSCAR PERSONA , MODIFICAR PERSONA

//PARA DAR DE BAJA SE MUESTRA LISTADO DE PERSONAS, PARA VER QUIEN SE VA A DAR DE BAJA) ES UNA OPCION POR EJ



int main() {

	setbuf(stdout, NULL);

	char seguir = 's';
	ePersona lista[TAM];
	int nextId = 2000;
	int nextIdAlmuerzo = 5000;
	eAlmuerzo almuerzos[TAM_A];

	eLocalidad localidades[TAM_LOC] = {
			{1000, "Avellaneda"},
			{1001, "Bernal"},
			{1002, "Quilmes"},
			{1003, "Lanus"},
			{1004, "Sarandi"}};

	eComida comidas[TAM_C] = {
	    {5000, "Milanesa", 450.70},
	    {5001, "Pizza", 400.50},
	    {5002, "Ensalada", 530.75},
	    {5003, "Fideos", 390.10},
	    {5004, "Hamburguesa", 478.40}};

	if(!inicializarPersona(lista,TAM)){  //CON ! SE TRANSFORMA EN 1
		printf("ocurrio un problema \n"); //pone el 1 los isEmpty
	}

	if(!inicializarAlmuerzos(almuerzos,TAM_A)){  //CON ! SE TRANSFORMA EN 1
			printf("ocurrio un problema \n"); //pone el 1 los isEmpty
		}
	//hardCodearPersona(lista, TAM, 4, &nextId);  //FUNCION PARA HARDCODEAR DATOS

	do{

		switch(menu()){ //opciones del tp

		case 1:
			if(altaPersona(lista, TAM, localidades, TAM_LOC, &nextId)){
				printf("alta exitosa\n"); //si devuelve 1

			}
			else
			{
				printf("hubo un problema al hacer el alta\n"); //SI DEVUELVE EL 0, HUBO ERROR
			}
			break;

		case 2:
			if(bajaPersona(lista, TAM, localidades, TAM_LOC)){
				printf("baja existosa\n"); //si devuelve 1

			}
			else
			{
				printf("hubo un problema la baja\n"); //SI DEVUELVE EL 0, HUBO ERROR
			}
			break;
		case 3:
		    if(modificarPersona(lista, TAM, localidades, TAM_LOC)){
						printf("modificacion existosa\n"); //si devuelve 1

					}
					else
					{
						printf("hubo un problema la modificacion\n"); //SI DEVUELVE EL 0, HUBO ERROR
					}

			break;
		case 4:
		if(ordenarPersonas(lista, TAM)){
			printf("ordenamiento exitoso\n"); //si devuelve 1

			}
			else
			{
				printf("hubo un problema al ordenar personas\n"); //SI DEVUELVE EL 0, HUBO ERROR
			}

			break;
		case 5:

			if(!mostrarPersonas(lista, TAM, localidades, TAM_LOC))
			{
				printf("no se pudo mostrar las personas\n");
			}
			break;

		case 6:
			system("cls");
			mostrarMujeres(lista, TAM, localidades, TAM_LOC);
				break;

		case 7:
			mostrarLocalidades(localidades, TAM_LOC);
			break;
		case 8:
		    informePersonasLocalidad(lista, TAM ,localidades,TAM_LOC);
			break;

		case 9:
			informePersonasAllLocalidades(lista, TAM, localidades, TAM_LOC);
			break;
		case 10:
			promedioEdadVaronesLocalidad(lista, TAM, localidades, TAM_LOC);
			break;

		case 11:
			informePersonaMasAltaLocalidad(lista, TAM, localidades, TAM_LOC);
			break;
		case 12:
			localidadMujerJoven(lista, TAM, localidades, TAM_LOC);
			break;
		case 13:
			cantidadPersonasLocalidad(lista, TAM, localidades, TAM_LOC);
			break;
		case 14:
			localidadMasHabitada(lista, TAM, localidades, TAM_LOC);
			break;
		case 15:
			mostrarComidas(comidas, TAM_C);
			break;
		case 16:

			break;

		 case 20:
			seguir = 'n';
			break;
		default:
			printf("opcion invalida");
			break;

		}

	}while(seguir == 's');


	return EXIT_SUCCESS;
}
