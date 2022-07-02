#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Menus.h"





int menuOpciones()
{
	int opcion;

	printf("-----------------------------------------------------------------------------------\n"
		   "---------------------------- *** MENU PRINCIPAL *** -------------------------------\n"
		   "-----------------------------------------------------------------------------------\n\n"
		   "1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
		   "2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
		   "3. Alta de pasajero\n"
		   "4. Modificar datos de pasajero\n"
		   "5. Baja de pasajero\n"
	       "6. Listar pasajeros\n"
		   "7. Ordenar pasajeros\n"
	       "8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
		   "9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
		   "10. Salir\n\n"
			"Ingrese una opcion: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}
int salir(char* letra)
{
	int isOk = 0;
	char opcion;

	if(letra != NULL)
	{
		printf("Confirmar salida.\n"
				"Ingrese 's' para salir: ");
		fflush(stdin);
		scanf("%c", &opcion);
		system("cls");

		if(opcion == 's' || opcion == 'S')
		{
			*letra = tolower(opcion);
			isOk = 1;
		}
	}
	return isOk;
}
int menuModificar()
{
	int opcion;
	int cant = 0;
	int intentos = 2;

	do
	{
		printf("\n--------------------------------------------\n"
				"            MENU MODIFICAR PASAJERO      \n"
				"--------------------------------------------- \n\n"
				"1. NOMBRE\n"
				"2. APELLIDO\n"
				"3. PRECIO\n"
				"4. CODIGO DE VUELO\n"
				"5. TIPO DE PASAJERO\n"
				"6. SALIR\n"
				"\nQUE DESEA MODIFICAR?: ");

		fflush(stdin);
		cant = scanf("%d", &opcion);
		printf("\n\n");

		if(opcion < 1 || opcion > 6 || !cant)
		{

			printf("OPCIÓN INCORRECTA.\n\n");
			intentos--;

		}
		else
		{
			break;
		}

	}while(intentos > 0);

	return opcion;
}
int menuOrdenar()
{
	int opcion;
	int cant = 0;
	int intentos = 2;

	do
	{
		printf( "--------------------------------\n"
				"          MENU ORDENAR      \n"
				"-------------------------------- \n\n"
				"1. POR ID\n"
				"2. POR APELLIDO\n"
				"3. POR TIPO Y CODIGO DE VUELO\n"
				"4. POR CODIGO DE VUELO Y ID\n"
				"5. SALIR\n"
				"\n¿QUE DESEA ORDENAR?: ");

		fflush(stdin);
		cant = scanf("%d", &opcion);
		printf("\n\n");

		if(opcion < 1 || opcion > 5 || !cant)
		{
			printf("OPCIÓN INCORRECTA.\n\n");
			intentos--;
		}
		else
		{
			break;
		}

	}while(intentos > 0);

	return opcion;
}
void listaEncabezado()
{
	printf("--------------------------------------------------------------------------------------------------------------\n"
		   "                                     LISTADO DE PASAJEROS                                                     \n"
		   "--------------------------------------------------------------------------------------------------------------\n"
		   "  ID  Nombre             Apellido                 Precio         Código        Tipo             Estado        \n"
		   "--------------------------------------------------------------------------------------------------------------\n");
}
void bajaEncabezado()
{
	system("cls");
	printf("\n-------------------------------------------"
		   "\n              BAJA PASAJERO                "
		   "\n-------------------------------------------\n");
}
