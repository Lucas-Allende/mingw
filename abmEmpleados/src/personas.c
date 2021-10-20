/*
 * persona.c
 *
 *  Created on: 6 oct. 2021
 *      Author: MAIA
 */
#include <stdio.h>
#include <stdlib.h>
#include "personas.h"
#include <string.h>
#include <ctype.h>

int menu(){

	int opcion;

	system("cls");

	printf("                  ABM PERSONA      \n");
	printf("---------------------------------------------------\n");

	printf(" 1. alta\n");
	printf(" 2. baja\n");
	printf(" 3. modificar\n");
	printf(" 4. ordenar\n");
	printf(" 5. listar\n");
	printf(" 6. listar mujeres\n");
	printf(" 7. listar localidades\n");
	printf(" 8. Personas de una localidad\n");
	printf(" 9. Mostrar personas de cada localidad\n");
	printf(" 10. promedio edad de varones\n");
	printf(" 11. Informe persona alta de una localidad\n");
	printf(" 12. Informe mujer mas joven de una localidad\n");
	printf(" 13. Cantidad de personas de cada localidad\n");
	printf(" 14. Localidad mas habitada\n");
	printf(" 15. Mostrar comidas\n");
	printf(" 16.  mostrar almuerzos\n");
	printf(" 17.  alta almuerzo\n");
    printf(" 20. salir\n");

	printf("ingrese opcion ");
	scanf("%d", &opcion);


	return opcion;
}

int inicializarPersona(ePersona lista[], int tam) //INICIALIZA EL CAMPO ISEMPTY EN 1 DE TODAS LAS PESONA
{
	int excelente = 0;

	if(lista != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			lista[i].isEmpty = 1;
		}
		excelente = 1;
	}


	return excelente;
}


int buscarLibre(ePersona lista[], int tam){
	//int excelente = 0;
	int indice;


	if(lista != NULL && tam > 0){
		for(int i = 0; i < tam; i++){

		   if(lista[i].isEmpty == 1){
			   indice = i;

				break;
			}
		}
		//excelente = 1;
	}
	return indice;
}

int altaPersona(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades, int* pId){

	int excelente = 0;
	int indice;
	ePersona auxPersona;

	if(lista != NULL && tam > 0 && pId != NULL){


		system("cls");

		printf("--------------------------------------ALTA PERSONA--------------------------------------\n");

		indice = buscarLibre(lista, tam);

		if(indice == -1) //no hay lugar
		{
			printf("no hay lugar\n");
		}
		else  //hay lugar
		{
			auxPersona.id = *pId;  //se cargar en auxpersona
			(*pId)++; //SE ACTUALIZA EL ID DEL MAIN AOLO, SE VA INCREMENTANDO
			//MEDIANTE PUNTERO SE INCREMETNA VARIAVBLE GETSIS EN EL MAIN

			//------------------------------ Se piden datos:
			printf("ingrese nombre");
			fflush(stdin);
			//gets(lista[indice].nombre);
			gets(auxPersona.nombre); //VALIDACON CONVIENE HACER EN BUFFER, LUGAR EXTERIOR A FUNCION QUE ESTAMOS USANDO = OSEA UNA NUEVA FUNCION


			printf("ingrese sexo\n");
			fflush(stdin);
			scanf("%c", &auxPersona.sexo);

			printf("ingrese edad\n");
			scanf("%d", &auxPersona.edad);

			printf("ingrese altura\n");
			scanf("%f", &auxPersona.altura);


			mostrarLocalidades(localidades, tamLocalidades);
			printf("Ingrese id localidad\n");
			scanf("%d", &auxPersona.idLocalidad);

			while(!validarIdLocalidad(localidades, tamLocalidades, auxPersona.idLocalidad)){ //VALIDA QUE  EL ID DE LA LOCALIDAD SEA VALIDO
				                                                      //LA LOCALIDAD CON ESE ID SI EXISTE
				mostrarLocalidades(localidades, tamLocalidades);
				printf("Ingrese id localidad\n");
				scanf("%d", &auxPersona.idLocalidad);
		}

			auxPersona.isEmpty = 0; //SE ACTUALIZA PORQUE TYA NO ESTA VACIO

			lista[indice] = auxPersona;
			excelente = 1;

		}

	}

	return excelente;
}

int mostrarPersonas(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades){

	int excelente = 0;
	int flag = 1;

	if(lista != NULL && tam > 0){
		printf("-----------------   LISTADO DE PERSONAS    --------------------------------------------------------\n");
		printf("  ID              NOMBRE               SEXO               EDAD              ALTURA       LOCALIDAD\n");
		printf("----------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i < tam; i++){

			if(lista[i].isEmpty == 0){
				mostrarPersona(lista[i], localidades, tamLocalidades); //RECORRO ARRAY, PREGUNTA SI ESTRUCUTURA ESTA VACIA, DE VECTOR LISTA LO PASA A FUNCION MOSTAR PERSONA
			    flag = 0;
			}
		}

		if(flag == 1){
			printf("no hay personas para mostrar\n");
		}

		excelente = 1;
	}

	return excelente;
}





void mostrarPersona(ePersona unaPersona, eLocalidad localidades[], int tamLocalidades){

	char descLocalidad[20];

	cargarDescripcionLocalidad(localidades, tamLocalidades, unaPersona.idLocalidad, descLocalidad);

	printf("%d        %10s        %c       %d      %.2f       %s\n\n",
			unaPersona.id,
			unaPersona.nombre,
			unaPersona.sexo,
			unaPersona.edad,
			unaPersona.altura,
			descLocalidad
			);
}



int buscarPersonaId(ePersona lista[], int tam, int id){

	// SE NECESITA VARIABLE PARA VER SI SE ENCONTRO ID -> SI NO SE ENCONTRO DEVUELVE -1  -- SI SE ENCONTRO DEVUELVE EL INDICE

	int idEncontrada = -1;

	for(int i; i < tam; i++){
		if(lista[i].isEmpty == 0 && lista[i].id == id){
			idEncontrada = i;   // I  = VARIABLE DE CONTROL DE POSICIONES
		}
	}
	return idEncontrada;
}

int bajaPersona(ePersona lista[], int tam,  eLocalidad localidades[], int tamLocalidades){

	int excelente = 0;
	int id;
	int indice;
	char confirma;

	if(lista != NULL && tam > 0){

		printf("    +       ------ -BAJA PERSONA----");

		mostrarPersonas(lista, tam, localidades, tamLocalidades);
		printf("ingrese id\n");
		scanf("%d", &id);

		indice = buscarPersonaId(lista, tam, id);

		if(indice == -1){

			printf("no existe uan persona con id %d", id);

		}
		else
		{
			mostrarPersona(lista[indice], localidades, tamLocalidades);

			printf("confirma baja?");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's'){
				lista[indice].isEmpty = 1;
				excelente = 1;
			}
			else{
				printf("se ha cancelado la baja\n");
			}
		}

	}


	return excelente;
}


int modificarPersona(ePersona lista[], int tam,  eLocalidad localidades[], int tamLocalidades){

	int excelente = 0;
		int id;
		int indice;
		char confirma;
		char auxNombre[20];
		int auxEdad;
		float auxAltura;
		char auxSexo;


		if(lista != NULL && tam > 0){

			printf("    +       ------ -MODIFICAR PERSONA----");
			printf("ingrese id\n");
			scanf("%d", &id);

			indice = buscarPersonaId(lista, tam, id);

			if(indice == -1){

				printf("no existe una persona con id %d", id);

			}
			else
			{
				mostrarPersona(lista[indice], localidades, tamLocalidades);

				printf("confirma modificacion?");
				fflush(stdin);
				scanf("%c", &confirma);

				if(confirma == 's'){

					switch(menuModificacion()){

					     case 1:
					    	 printf("ingrese nuevo nombre");
					    	 fflush(stdin);
					    	 gets(auxNombre);
					    	 strcpy(lista[indice].nombre, auxNombre); //SE ACTUALIZA NUUEVO NOMBRE
					    	 break;

					     case 2:
					    	 printf("ingrese nuevo sexo");
					    	 fflush(stdin);
					    	 scanf("%c", &auxSexo);
					    	 lista[indice].sexo =  auxSexo;
					    	 break;

					     case 3:
					    	 printf("ingrese nueva edad: ");
					    	 scanf("%d", &auxEdad);
					    	 lista[indice].edad = auxEdad;
					    	 break;

					     case 4:
					    	 printf("ingrese nueva altura: ");
					    	 scanf("%f", &auxAltura);
					    	 lista[indice].altura = auxAltura;
					    	 break;

					     default:
					    	 printf("opcion invalida\n");
					    	 break;
					}

					excelente = 1;
				}
				else{
					printf("se ha cancelado la modificacion\n");
				}
			}

		}


		return excelente;
	}

int menuModificacion(){

	int opcion;


	system("cls");

	printf("                Menu modificacion    \n");
	printf("---------------------------------------------------\n");

	printf("   1. nombre\n");
	printf("   2. sexo\n");
	printf("   3. edad\n");
	printf("   4. altura\n");
	printf("   5. listar mujeres\n");
	printf("   5. salir\n");

	printf("ingrese opcion");
	scanf("%d", &opcion);


	return opcion;
}


int ordenarPersonas(ePersona lista[], int tam){

	//ORDENAMIENTO - POR QIUE LO QUEREMOS ORDENAR -  ORDENAR POR CATEGORIA - ELEGIR CUAL

	int excelente = 0;
	ePersona auxPersona;

	if(lista != NULL && tam > 0){
		for(int i = 0; i < tam - 1; i++){
			for(int j = i + 1; j < tam; j++){

				if( ( lista[i].sexo > lista[j].sexo) || (lista[i].sexo == lista[j].sexo &&
						strcmp(lista[i].nombre, lista[j].nombre) > 0 ) )
				{ //se ordena personas mujeres alfabeticametne

					auxPersona = lista[i];
					lista[i] = lista[j];
					lista[j] = auxPersona;
				}
			}
		}


		excelente = 1;
	}


	return excelente;
}
//-------------------------------

int mostrarMujeres(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades){

	int excelente = 0;
	int flag = 1;

	if(lista != NULL && tam > 0){
		printf("-------------------   LISTADO DE MUJERES    --------------\n");
		printf("  ID              NOMBRE               SEXO               EDAD               ALTURA          LOCALIDAD\n");
		printf("-------------------------------------------------------------\n");
		for(int i = 0; i < tam; i++){

			if(!lista[i].isEmpty && lista[i].sexo == 'f'){

				mostrarPersona(lista[i], localidades, tamLocalidades); //RECORRO ARRAY, PREGUNTA SI ESTRUCUTURA ESTA VACIA, DE VECTOR LISTA LO PASA A FUNCION MOSTAR PERSONA
			    flag = 0;
			}
		}

		if(flag == 1){
			printf("no hay mujeres para mostrar\n");
		}

		excelente = 1;
	}

	return excelente;
}


int informePersonasLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades){
	int excelente = 0;
	int idLocalidad;

	//limpiar pantalla
	//poner titulo
	//mostrar localidades
	//pedir y validar id localidad
	//listar personas que vivan en esa localidad

	if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades > 0)
	{
		system("cls");

		printf("--------------------------------------------\n");
		printf("        INFORME PERSONAS UNA LOCALIDAD");
		printf("---------------------------------------------\n");

		mostrarLocalidades(localidades, tamLocalidades);

		printf("ingrese id de localidad: ");
		scanf("%d",&idLocalidad);

		while(!validarIdLocalidad(localidades, tamLocalidades, idLocalidad))
		{
			mostrarLocalidades(localidades, tamLocalidades);
			printf("error...Reingrese id de localidad: ");
			scanf("%d",&idLocalidad);
		}



		excelente = 1;
	}

	return excelente;
}


int mostrarPersonasIdLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades, int idLocalidad){
	int excelente = 0;
	int flag = 0;

	if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades > 0 )
	{
		printf("----------------------------------------------------------------------------------------------------\n");
		printf("  ID              NOMBRE               SEXO               EDAD              ALTURA       LOCALIDAD\n");
		printf("----------------------------------------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idLocalidad == idLocalidad)
			{
				mostrarPersona(lista[i], localidades, tamLocalidades); //muestra la persona en el indice I
				flag = 0;
			}

		}

		if(flag == 1)
		{
			printf("no hay personas en esa localidad..\n");
		}

		mostrarPersonasIdLocalidad(lista, tam, localidades, tamLocalidades, idLocalidad);


		excelente = 1;
	}

	//TERMINAR FUNCION


	return excelente;
}


int informePersonasAllLocalidades(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades)
{
	// RECORRER VECTOR LOCALIDADES PARA OBTENER ID
	// LLAMAR FUNCION QUE MUESTRA ID DE UNA LOCALIDAD

	int excelente = 0;

	if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades > 0)
	{

		printf("------------------------------------------------------\n");
		printf("        INFORME PERSONAS DE TODAS LAS LOCALIDAD\n");
		printf("-------------------------------------------------------\n\n");

		for(int i = 0; i < tamLocalidades; i++)
		{
			printf("Localidades: %s\n", localidades[i].descripcion);
			mostrarPersonasIdLocalidad(lista, tam, localidades, tamLocalidades, localidades[i].id); //obtiene id por localidad
			printf("\n\n");
		}
	}


	return excelente;
}

int promedioEdadVaronesLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades)
{
	int excelente = 0;
	int contadorEdad = 0;
	int acumuladorEdad = 0;
	int idLocalidad;
	float promedio = 0;
	char descLocalidades[20];

	//limpiar pantalla
	//poner titulo
	//mostrar localidades
	//pedir y validar id localidad
	//listar personas que vivan en esa localidad

	if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades > 0)
	{
		system("cls");

		printf("------------------------------------------------\n");
		printf("        INFORME VARONES DE UNA MISMA LOCALIDAD");
		printf("-------------------------------------------------\n");

		mostrarLocalidades(localidades, tamLocalidades);

		printf("ingrese id de localidad: ");
		scanf("%d",&idLocalidad);

		while(!validarIdLocalidad(localidades, tamLocalidades, idLocalidad))
		{
			mostrarLocalidades(localidades, tamLocalidades);
			printf("error...Reingrese id de localidad: ");
			scanf("%d",&idLocalidad);
		}

		for(int i = 0; i < tam; i++) //RECCORE ARRAY DE PERSONAS BUSCA PERSONAS ACTIVAS, QUE VIVAN EN ESA LOCALIDAD Y SEAN VARONES
			{
					if(lista[i].isEmpty == 0 && lista[i].idLocalidad == idLocalidad && lista[i].sexo == 'm')
					{
						contadorEdad++;
						acumuladorEdad += lista[i].edad;
					}

			}

		if(contadorEdad != 0)
		{
			promedio = (float) acumuladorEdad / contadorEdad;
		}

		cargarDescripcionLocalidad(localidades, tamLocalidades, idLocalidad, descLocalidades);
		printf("Promedio edad de varones de %s: %.2f", descLocalidades, promedio);

		excelente = 1;
	}

	return excelente;
}

int informePersonaMasAltaLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades)
{
	//MUESTRA LOCALIDADES
	//PIDE ID DE LOCALDIAD Y LO VALIDA
	// buscar personas activas que vivan en una deerminada localidad para obtener maxima altura
	//con maxima altura recorro array d eoersonas nuevmanete buscando a quienes viven en esa localidad y tienen esa misma
	//altura maxima
	int excelente = 0;
	int idLocalidad;
	float alturaMax;
	int flag = 0;

	if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades > 0)
	{
		printf("------------------------------------------------\n");
		printf("             INFORME PERSONA MAS ALTA");
		printf("-------------------------------------------------\n");

		mostrarLocalidades(localidades, tamLocalidades);

		printf("ingrese id de localidad: ");
		scanf("%d",&idLocalidad);

		while(!validarIdLocalidad(localidades, tamLocalidades, idLocalidad))
		{
			mostrarLocalidades(localidades, tamLocalidades);
			printf("error...Reingrese id de localidad: ");
			scanf("%d",&idLocalidad);
		}


		for(int i = 0; i < tamLocalidades; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idLocalidad == idLocalidad)
			{
				if(flag == 0 || alturaMax > lista[i].altura)
				{
					alturaMax = lista[i].altura;
					flag = 1;
				}


			}
		}

		if(flag == 0)
		{
			printf("No hay personas en esta localidad");

		}
		else
		{
			for(int i = 0; i < tamLocalidades; i++)
			{
				if(lista[i].isEmpty == 0 && lista[i].idLocalidad == idLocalidad && lista[i].altura == alturaMax)
				{
				  mostrarPersona(lista[i], localidades, tamLocalidades);
				}
			}
			printf("\n\n");
		}

	}

	return excelente;
}


int localidadMujerJoven(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades)
{
	int excelente;
	int mujerJoven;
	int flag = 0;
	char descLocalidad[20];

	if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades > 0){

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 0  && lista[i].sexo == 'f')
			{
				if(flag == 0 || mujerJoven < lista[i].edad)
				{
					mujerJoven = lista[i].edad;
					flag = 1;
				}


			}
		}

		if(flag == 0)
		{
			printf("No hay mujeres en esta localidad");

		}
		else
		{
			for(int i = 0; i < tam; i++)
			{
				if(lista[i].isEmpty == 0  && lista[i].sexo == 'f' && lista[i].edad < mujerJoven)
				{
					cargarDescripcionLocalidad(localidades, tamLocalidades, lista[i].idLocalidad, descLocalidad);
					puts(descLocalidad);
				}
			}
			printf("\n\n");
		}


				/*
				for(int i = 0; i < tam; i++){

					if(!lista[i].isEmpty && lista[i].sexo == 'f'){

						mostrarPersona(lista[i], localidades, tamLocalidades); //RECORRO ARRAY, PREGUNTA SI ESTRUCUTURA ESTA VACIA, DE VECTOR LISTA LO PASA A FUNCION MOSTAR PERSONA
						flag = 0;
					}
				}*/
		excelente = 1;
	}

	return excelente;
}

int cantidadPersonasLocalidad(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades)
{
	int excelente = 0;
	int contador;
	char unidad[20] = {"habitante"};

	if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades)
	{


			if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades > 0)
			{

				printf("------------------------------------------------------\n");
				printf("        CANTIDAD PERSONAS DE CADA LOCALIDAD\n");
				printf("-------------------------------------------------------\n\n");

				for(int i = 0; i < tamLocalidades; i++)
				{
					printf("Localidades: %s\n", localidades[i].descripcion);
					contador = 0;
					strcpy(unidad, "habitantes");
					for(int j = 0; j < tam; j++)
					{
						if(lista[j].isEmpty == 0 && lista[j].idLocalidad == localidades[i].id)
						{
							contador++;
						}
					}
				}

				if(contador == 1)
				{
					strcpy(unidad, "habitante");
				}
				if(contador == 0)
				{
					printf("no hay habitantes\n");
				}
				else
				{
					if(contador == 1)
					{
						strcpy(unidad, "habitante");
						printf("%d  %s\n", contador, unidad);
					}
					else
					{
						printf("%d  %s\n", contador, unidad);
					}
				}

			}



			excelente = 1;
	}



	return excelente;
}


int localidadMasHabitada(ePersona lista[], int tam, eLocalidad localidades[], int tamLocalidades){

	int excelente = 0;
	int contadores[5] = {0};
	int mayorCantidadHabitantes;



	if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades)
	{


			if(lista != NULL && tam > 0 && localidades != NULL && tamLocalidades > 0)
			{

				printf("------------------------------------------------------\n");
				printf("              LOCALIDAD MAS HABITADA\n");
				printf("-------------------------------------------------------\n\n");

				for(int i = 0; i < tamLocalidades; i++)
				{

					for(int j = 0; j < tam; j++)
					{
						if(lista[j].isEmpty == 0 && lista[j].idLocalidad == localidades[i].id)
						{
							contadores[i]++; 						}
					}
				}

				for(int i = 0; i < tamLocalidades; i++)
				{
					if(i == 0 || mayorCantidadHabitantes < contadores)
					{
						mayorCantidadHabitantes = contadores[i];
					}
				}

				for(int i = 0; i < tamLocalidades; i++)
				{
					if(contadores[i] == mayorCantidadHabitantes)
					{
						printf("%s\n", localidades[i].descripcion);
					}
				}
				printf("\n\n");

			}



			excelente = 1;
	}



	return excelente;

}



