/*
 * almuerzo.c
 *
 *  Created on: 18 oct. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include "almuerzo.h"

int inicializarAlmuerzo(eAlmuerzo almuerzos[], int tam){
	int excelente = 0;

		if(almuerzos != NULL && tam > 0){
			for(int i = 0; i < tam; i++){
				almuerzos[i].isEmpty = 1;
			}
			excelente = 1;
		}


   return excelente;
}

int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam)
{
	int indice;


		if(almuerzos != NULL && tam > 0)
		{
			for(int i = 0; i < tam; i++)
			{

			   if(almuerzos[i].isEmpty == 1)
			   {
				   indice = i;

					break;
				}
			}
			//excelente = 1;
		}
		return indice;
}

int altaAlmuerzo(eAlmuerzo almuerzos[], int tama, ePersona lista[] , int tam, eLocalidad localidades[], int tamLocalidades, eComida comidas[], int tamc, int* pIdAlmuerzo)
{
	int excelente = 0;
		int indice;
		eAlmuerzo auxAlmuerzo;

		if(lista != NULL && tama > 0 && pIdAlmuerzo != NULL && localidades != NULL && comidas != NULL && tamLocalidades > 0){


			system("cls");

			printf("--------------------------------------ALTA ALMUERZO--------------------------------------\n");

			indice = buscarLibreAlmuerzo(almuerzos, tama);

			if(indice == -1) //no hay lugar
			{
				printf("no hay lugar\n");
			}
			else  //hay lugar
			{
				auxAlmuerzo.id = *pIdAlmuerzo;  //se cargar en auxpersona
				(*pIdAlmuerzo)++; //SE ACTUALIZA EL ID DEL MAIN AOLO, SE VA INCREMENTANDO
				//MEDIANTE PUNTERO SE INCREMETNA VARIAVBLE GETSIS EN EL MAIN

				//------------------------------ Se piden datos:

				mostrarPersonas(lista, tam, localidades, tamLocalidades);
				printf("Ingrese id localidad\n");
				scanf("%d", &auxAlmuerzo.idPersona);

				while( buscarPersonaId(lista, tam, auxAlmuerzo.idPersona) != -1)
				{ //VALIDA QUE  EL ID DE LA LOCALIDAD SEA VALIDO
					                                                      //LA LOCALIDAD CON ESE ID SI EXISTE

					printf("error id invalido, reingrese id persona\n");
					scanf("%d", &auxAlmuerzo.idPersona);
			    }


				mostrarComidas(comidas, tamc);
				printf("Ingrese id localidad\n");
				scanf("%d", &auxAlmuerzo.idComida);

				while( validarIdComida(comidas, tamc, auxAlmuerzo.idComida))
				{ //VALIDA QUE  EL ID DE LA LOCALIDAD SEA VALIDO

					printf("error id invalido, reingrese id comida\n");
					scanf("%d/%d/%d", &auxAlmuerzo.fecha.dia, &auxAlmuerzo.fecha.mes, &auxAlmuerzo.fecha.anio);
			    }

				auxAlmuerzo.isEmpty = 0; //SE ACTUALIZA PORQUE TYA NO ESTA VACIO

				almuerzos[indice] = auxAlmuerzo;
				excelente = 1;

			}

		}

		return excelente;
}
