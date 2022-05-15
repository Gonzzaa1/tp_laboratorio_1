#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "ArrayTypes.h"
#include "ArrayStatus.h"


//------------------------------------------------------------------------------------------------------------------------------------------
//                                                     **** TP FUNCTIONS ****
//------------------------------------------------------------------------------------------------------------------------------------------

int initPassengers(Passenger* list, int len)
{
	int isOk = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		isOk = 0;
	}
	return isOk;
}
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
	int isOk = -1;

	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flycode != NULL)
	{

		isOk = 0;
	}
	return isOk;
}
int findPassengerById(Passenger* list, int len,int id)
{
	int index = -1;

	if( list != NULL  && len > 0)
	{
		for(int i=0; i < len; i++)
		{
			if(!list[i].isEmpty && list[i].id == id)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
int removePassenger(Passenger* list, int len, int id)
{
	int isOk = -1;
	int index;
	char confirmar;

	if(list != NULL && len > 0)
	{
		index = findPassengerById(list, len, id);
		if(index == -1)
		{
			printf("\nNo existe un pasajero con ID: %d en el sistema\n", id);
		}
		else
		{
			printf("Confirma baja?: ");
			fflush(stdin);
			scanf("%c", &confirmar);
			if(confirmar == 's' || confirmar == 'S')
			{
				list[index].isEmpty = 1;
				printf("Baja exitosa!\n");
			}
			else
			{
				printf("Baja cancelada por el usuario\n");
			}
		}
	}
	return isOk;
}
int sortPassengersByName(Passenger* list, int len, int order)
{
	int isOk = -1;
	Passenger auxPassenger;

	if( list != NULL  && len > 0)
	{
		 for(int i=0; i < len - 1; i++)
		{
			for(int j= i+1; j < len; j++)
			{
				if(order == 1)
				{
					if((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName,list[j].lastName) > 0)
					   || (list[i].typePassenger != list[j].typePassenger && (list[i].typePassenger > list[j].typePassenger)))
					{
						auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
					}
				}
				else
				{
					if((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName,list[j].lastName) < 0)
					   || (list[i].typePassenger != list[j].typePassenger && (list[i].typePassenger < list[j].typePassenger)))
					{
						auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
					}
				}
			}
		}
		isOk = 0;
	}
	return isOk;
}
int printPassenger(Passenger* list, int length)
{
	int isOk = -1;

	if(list != NULL && length > 0)
	{
		printf("ID:                %d\n"
			   "Name:              %s\n"
			   "Surname:           %s\n"
			   "Price:             %.2f\n"
			   "Fly code:          %s\n"
			   /*"Type of passenger: %d\n"
			   "Status flight:     %d\n"*/,
			   list->id,
			   list->name,
			   list->lastName,
			   list->price,
			   list->flyCode/*,
			   list->typePassenger,
			   list->statusFlight*/);

		isOk = 0;
	}

	return isOk;
}
int sortPassengersByCode(Passenger* list, int len, int order)
{
	int isOk = -1;
	Passenger auxPassenger;

	if( list != NULL  && len > 0)
	{
		 for(int i=0; i < len - 1; i++)
		{
			for(int j= i+1; j < len; j++)
			{
				if(order == 1)
				{
					if((list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flyCode,list[j].flyCode) > 0)
					   || (list[i].statusFlight != list[j].statusFlight && (list[i].statusFlight > list[j].statusFlight)))
					{
						auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
					}
				}
				else
				{
					if((list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flyCode,list[j].flyCode) < 0)
					   || (list[i].statusFlight != list[j].statusFlight && (list[i].statusFlight < list[j].statusFlight)))
					{
						auxPassenger = list[i];
						list[i] = list[j];
						list[j] = auxPassenger;
					}
				}
			}
		}
		isOk = 0;
	}
	return isOk;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//                                                     **** MY FUNCTIONS ****
//------------------------------------------------------------------------------------------------------------------------------------------

int menu()
{
	int options;

	printf( "     *** ABM PASAJEROS ***\n\n"
			"1. Alta Pasajero\n"
			"2. Baja Pasajero\n"
			"3. Modificar Pasajero\n"
			"4. Informar\n"
			"5. Carga forzada\n"
			"6. Salir\n\n"
			"Ingrese opcion: ");

	fflush(stdin);
	scanf("%d", &options);

	return options;
}
int validarCadenas(char* texto)
{
    int isOk = 0;

    for(int i = 0; i < strlen(texto); i++)
    {
        char letra = texto[i];

        if(isdigit(letra))
        {
        	isOk = -1;
        }
        if(isalpha(letra))
        {
        	isOk = 1;
        }
    }
    return isOk;
}
int empresa()
{
	int options;

	printf("\n      *** Empresa *** \n"
		   "---------------------------\n"
		   " 1. Aerolineas Argentinas\n"
		   " 2. Latam\n"
		   " 3. FlyBondi\n"
		   " 4. Air Europa\n"
		   " 5. United Airlines\n\n"
		   "Ingrese opcion: ");
	    fflush(stdin);
	    scanf("%d", &options);

	return options;
}
int buscarLugar(Passenger* passenger, int len, int* pIndex)
{
	int isOk = -1;

	if( passenger != NULL && pIndex != NULL && len > 0)
	{
		*pIndex = -1;
		for(int i=0; i < len; i++)
		{
			if(passenger[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
		}
	}
	return isOk;
}
int altaPasajero(Passenger* passenger, int len, int* pNextId,TypePassenger* types, StatusFlight* status,int lenTS)
{
	int isOk = -1;
	char error;
	char auxcad[50];
	int index;

	Passenger newPassenger;

	if(passenger != NULL && pNextId != NULL && len > 0 && types != NULL && status != NULL && lenTS > 0)
	{
		system("cls");

		printf("    *** Alta Pasajero ***\n");
		printf("-------------------------------\n\n");
		buscarLugar(passenger, len, &index);

		if(index == -1)
		{
			printf("No hay lugar en el sistema\n");
			system("pause");
		}
		else
		{
			newPassenger.id = *pNextId;

			printf("Ingrese nombre: ");
			fflush(stdin);
			gets(newPassenger.name);
			while(validarCadenas(newPassenger.name) == -1 || strlen(newPassenger.name) > 51)
			{
				printf("Nombre mal cargado... Reingrese nombre: ");
				fflush(stdin);
				gets(newPassenger.name);
			}

			printf("Ingrese apellido: ");
			fflush(stdin);
			gets(newPassenger.lastName);
			while(validarCadenas(newPassenger.lastName) == -1 || strlen(newPassenger.name) > 51)
			{
				printf("Apellido mal cargado... Rengrese apellido: ");
				fflush(stdin);
				gets(newPassenger.lastName);
			}

			printf("Ingrese precio: ");
			scanf("%f", &newPassenger.price);
			while(newPassenger.price < 1 || newPassenger.price > 999999 || isdigit((int)newPassenger.price))
			{
				printf("Precio invalido...Reingrese precio: ");
				fflush(stdin);
				scanf("%f", &newPassenger.price);
			}

			do
			{
				error = 'n';
				switch(empresa())
				{
					case 1:
						strcpy(newPassenger.flyCode, "AA");
						break;
					case 2:
						strcpy(newPassenger.flyCode, "LT");
						break;
					case 3:
						strcpy(newPassenger.flyCode, "FB");
						break;
					case 4:
						strcpy(newPassenger.flyCode, "AE");
						break;
					case 5:
						strcpy(newPassenger.flyCode, "UA");
						break;
					default:
						error = 's';
						printf("\nOpcion ingresada incorrecta, vuelva ingresar opcion");
				}
			}while(error != 'n');
			printf("Ingrese codigo de vuelo (los 6 numeros): ");
			fflush(stdin);
			gets(auxcad);
			while(validarCadenas(auxcad) == 1 || strlen(auxcad) > 6 ||strlen(auxcad) < 6)
			{
				printf("Codigo invalido...Reingrese codigo de vuelo (los 6 numeros): ");
				fflush(stdin);
				gets(auxcad);
			}
			strcat(newPassenger.flyCode,auxcad);

			printType(types, lenTS);
			printf("\nIngrese tipo de pasajero: ");
			scanf("%d", &newPassenger.typePassenger);
			while(!valideType(types, lenTS, newPassenger.typePassenger))
			{
				printf("Id invalido. Reingrese tipo de pasajero: ");
				scanf("%d", &newPassenger.typePassenger);
			}

			printStatus(status, lenTS);
			printf("Ingrese estado del vuelo: ");
			scanf("%d", &newPassenger.statusFlight);
			while(!valideStatus(status, lenTS, newPassenger.statusFlight))
			{
				printf("Id invalido. Reingrese tipo de pasajero: ");
				scanf("%d", &newPassenger.statusFlight);
			}

			newPassenger.isEmpty = 0;

			passenger[index] = newPassenger;

			(*pNextId)++;

			system("cls");
			printf("    *** Alta Pasajero ***\n");
			printf("-------------------------------\n\n");
			printf("        Carga exitosa!!!\n\n");
			system("pause");
			isOk = 0;
		}
	}

	return isOk;
}
int showPassenger(Passenger passenger, TypePassenger* types, StatusFlight* status,int lenTS, int format)
{
	int isOk = -1;

	 char typePassenger[15];
	 char statusFlight[15];

	if(types != NULL && status != NULL && lenTS > 0)
	{
		loadTypeDescription(types, lenTS, passenger.typePassenger, typePassenger);
		loadStatusDescription(status, lenTS, passenger.statusFlight, statusFlight);

		if(format == 1)
		{

			printf("ID:                %d\n"
				   "Name:              %s\n"
				   "Surname:           %s\n"
				   "Price:             %.2f\n"
				   "Fly code:          %s\n"
				   "Type of passenger: %s\n"
			       "Status flight:     %s\n",
				   passenger.id,
				   passenger.name,
				   passenger.lastName,
				   passenger.price,
				   passenger.flyCode,
				   typePassenger,
				   statusFlight);
		}
		else
		{
			printf(" %4d  %15s   %15s     %5.2f    %10s  %15s  %15s\n",
					passenger.id,
					passenger.name,
					passenger.lastName,
					passenger.price,
					passenger.flyCode,
					typePassenger,
					statusFlight);
		}
	}

	return isOk;
}
int listarPasajeros(Passenger* passenger, int len, TypePassenger* types, StatusFlight* status,int lenTS, int format,int flag)
{
	int isOk = -1;

	if(passenger != NULL  && len > 0 && types != NULL && status != NULL  && lenTS > 0)
	{
		printf("                            *** List of Passengers ***\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("  Id        Name             Last Name         Price          Fly          type Passenger    Fly Status\n");
		printf("--------------------------------------------------------------------------------------------------------\n");

		if(flag)
		{
			printf("\n\n\n             *********  No hay pasajeros en el sistema  *********  \n\n");
		}
		else
		{
			for(int i=0; i < len; i++)
			{
				if(!passenger[i].isEmpty)
				{
					showPassenger(passenger[i], types, status, lenTS, format);
				}
			}
		}
		isOk = 0;
	}
	return isOk;
}
int cargaForzada(Passenger passenger[], int len, int cant, int* pNextId,int* flag)
{
    int isOk = 0;
    Passenger pasajeros[20] =
    {
      {0, "Gonzalo Javier", "Lopez Gonzalez", 250000, "AA120000", 5000, 3003, 0},
      {0, "Ramiro", "Ruiz", 250000, "LT220000", 5001, 3002, 0},
      {0, "Juan", "Gomez", 250000, "FB320000", 5002, 3001, 0},
      {0, "Andrea", "Gonzalez", 250000, "AE420000", 5003, 3000, 0},
      {0, "Ana", "Posca", 250000, "UA520000", 5001, 3003, 0},
      {0, "Javier", "Plantamura", 250000, "AA120000", 5002, 3002, 0},
      {0, "Alicia", "Torre", 250000, "LT220000", 5003, 3001, 0},
      {0, "Malena", "Martinez", 250000, "FB320000", 5000, 3000, 0},
      {0, "Julieta", "Paez", 250000, "AE420000", 5000, 3003, 0},
      {0, "Martin", "Moreno", 250000, "UA520000", 5001, 3002, 0},
      {0, "Gonzalo Javier", "Lopez Gonzalez", 250002, "AA120000", 5000, 3001, 0},
      {0, "Ramiro", "Ruiz", 250000, "LT220000", 5003, 3000, 0},
      {0, "Juan", "Gomez", 250000, "FB320000", 5000, 3003, 0},
      {0, "Andrea", "Gonzalez", 250000, "AE420000", 5001, 3002, 0},
      {0, "Ana", "Posca", 250000, "UA520000", 5002, 3001, 0},
      {0, "Javier", "Plantamura", 250000, "AA120000", 5003, 3000, 0},
      {0, "Alicia", "Torre", 250000, "LT220000", 5000, 3003, 0},
      {0, "Malena", "Martinez", 250000, "FB320000", 5001, 3002, 0},
      {0, "Julieta", "Paez", 250000, "AE420000", 5002, 3001, 0},
      {0, "Martin", "Moreno", 250000, "UA520000", 5003, 3000, 0}
    };

    if(passenger != NULL && pNextId != NULL && len > 0 && len <= 2000 && cant <= len)
    {
        for(int i=0; i < cant; i++)
        {
        	passenger[i] = pasajeros[i];
        	passenger[i].id = *pNextId;
			(*pNextId)++;

			if(passenger[i].isEmpty)
			{
				break;
			}
        }
        *flag = 0;
        isOk = 1;
    }
    return isOk;
}
int modPassenger(Passenger* passenger, int len, TypePassenger* types, StatusFlight* status,int lenTS)
{
	int isOk = 0;
	int index;
	int id;
	char auxCad[20];
	float price;
	int typePassenger;
	int statusFlight;
	char error;

	if(passenger != NULL && len > 0 && types != NULL && status != NULL && lenTS > 0)
	{
		printf("\nIngrese ID: ");
		scanf("%d", &id);
		index = findPassengerById(passenger, len, id);
		if(index == -1)
		{
			printf("\nNo existe un pasajero con ID: %d en el sistema\n", id);
			system("pause");
		}
		else
		{
			switch(menuMod())
			{
				case 1:
					printf("Ingrese nuevo nombre: ");
					fflush(stdin);
					gets(auxCad);
					while(validarCadenas(auxCad) == -1 || strlen(auxCad) > 51)
					{
						printf("Nombre mal cargado... Reingrese nombre: ");
						fflush(stdin);
						gets(auxCad);
					}
					strcpy(passenger[index].name, auxCad);
					printf("Nombre Modificado!\n");
					break;
				case 2:
					printf("Ingrese nuevo Apellido: ");
					fflush(stdin);
					gets(auxCad);
					while(validarCadenas(auxCad) == -1 || strlen(auxCad) > 51)
					{
						printf("Apellido mal cargado... Reingrese Apellido: ");
						fflush(stdin);
						gets(auxCad);
					}
					strcpy(passenger[index].lastName, auxCad);
					printf("Apellido Modificado!\n");
					break;
				case 3:
					printf("Ingrese nuevo precio: ");
					scanf("%f", &price);
					while(price < 1 || price > 999999 || isdigit((int)price))
					{
						printf("Precio invalido...Reingrese precio: ");
						fflush(stdin);
						scanf("%f", &price);
					}
					passenger[index].price = price;
					printf("Precio modificado!\n");
					break;
				case 4:
					do
					{
						error = 'n';
						switch(empresa())
						{
							case 1:
								strcpy(passenger[index].flyCode, "AA");
								break;
							case 2:
								strcpy(passenger[index].flyCode, "LT");
								break;
							case 3:
								strcpy(passenger[index].flyCode, "FB");
								break;
							case 4:
								strcpy(passenger[index].flyCode, "AE");
								break;
							case 5:
								strcpy(passenger[index].flyCode, "UA");
								break;
							default:
								error = 's';
								printf("\nOpcion ingresada incorrecta, vuelva ingresar opcion");
						}
					}while(error != 'n');
					printf("Ingrese nuevo codigo de vuelo (los 6 numeros): ");
					fflush(stdin);
					gets(auxCad);
					while(validarCadenas(auxCad) == 1 || strlen(auxCad) > 6||strlen(auxCad) < 6)
					{
						printf("Codigo invalido...Reingrese codigo de vuelo (los 6 numeros): ");
						fflush(stdin);
						gets(auxCad);
					}
					strcat(passenger[index].flyCode,auxCad);
					printf("Codigo de vuelo Modificado!\n");
					break;
				case 5:
					printType(types, lenTS);
					printf("\nIngrese nuevo tipo de pasajero: ");
					scanf("%d", &typePassenger);
					while(!valideType(types, lenTS, typePassenger))
					{
						printf("Id invalido. Reingrese tipo de pasajero: ");
						scanf("%d", &typePassenger);
					}
					passenger[index].typePassenger = typePassenger;
					printf("Tipo de pasajero Modificado!\n");
					break;
				case 6:
					printStatus(status, lenTS);
					printf("Ingrese nuevo estado del vuelo: ");
					scanf("%d", &statusFlight);
					while(!valideStatus(status, lenTS, statusFlight))
					{
						printf("Id invalido. Reingrese tipo de pasajero: ");
						scanf("%d", &statusFlight);
					}
					passenger[index].statusFlight = statusFlight;
					printf("Estado de vuelo Modificado!\n");
					break;
			}
		}
		isOk = 1;
	}

	return isOk;
}
int menuMod()
{
	int options;

	printf("    ****  Campo a modificar  ****\n"
		   "---------------------------------------\n"
		   "1. Nombre\n"
		   "2. Apellido\n"
		   "3. Precio\n"
		   "4. Codigo de vuelo\n"
		   "5. Tipo de pasajero\n"
		   "6. Estado de vuelo\n\n"
		   "Ingrese opcion: ");
		   fflush(stdin);
		   scanf("%d", &options);

	return options;
}
int informe(Passenger* passenger, int len)
{
	float priceTotal=0;
	float promedio = 0;
	int cont = 0;
	int canPassenger = 0;
	int isOk = 0;

	if(passenger != NULL  && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(!passenger[i].isEmpty)
			{
				priceTotal += passenger[i].price;
				cont++;
				/*if(passenger[i].price > promedio)
				{
					canPassenger++;
				}*/
			}
		}

		promedio = priceTotal / cont;

		for(int i = 0; i < len; i++)
		{
			if(!passenger[i].isEmpty)
			{
				if(passenger[i].price > promedio)
				{
					canPassenger++;
				}
			}
		}

		printf("El precio total de los pasajes es: $%.2f\nEl promedio de precio de los pasajes es: $%.2f\n",priceTotal,promedio);

		printf("La cantidad de pasajeros que superan el precio promedio es: %d pasajeros\n", canPassenger);
		isOk = 1;
	}
	return isOk;
}
int menuInforme()
{
	int options;

	printf("*** INFORMES ****\n");
	printf("--------------------\n");
	printf("1. Ordenar por Tipo de pasajeros y Apellidos de manera ascendente\n");
	printf("2. Ordenar por Tipo de pasajeros y Apellidos de manera descendente\n");
	printf("3. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
	printf("4. Ordenar por estado del vuelo y codigo de vuelo de manera ascendente\n");
	printf("5. Ordenar por estado del vuelo y codigo de vuelo de manera descendente\n");
	printf("\nIngrese opcion: ");
	fflush(stdin);
	scanf("%d",&options);

	system("cls");

	return options;
}
