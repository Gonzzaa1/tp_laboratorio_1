#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "MyFunction.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* passengerAux;
	int isOk = 0;
	int cantidad;
	char buffer[7][100];
	char header[100];

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		fscanf(pFile,"%s\n", header);
		ll_clear(pArrayListPassenger);

		do
		{
			cantidad = fscanf(pFile,"%[^,], %[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

			if(cantidad != 7)
			{
				printf("No se pudo parsear\n");
				exit(1);
			}
			else
			{
				passengerAux = Passenger_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
				//printf("%s\n",buffer[6]);
				if(passengerAux == NULL)
				{
					printf("No se consiguio espacio en memoria\n");
				}
				ll_add(pArrayListPassenger,(void*) passengerAux);
				isOk = 1;
			}
		}while(!feof(pFile));
		passengerAux=NULL;
	}
    return isOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int isOk = 0;
	int cant;
	Passenger* passengerAux;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		do{
			passengerAux = Passenger_new();
			cant = fread(passengerAux,sizeof(Passenger),1,pFile);
			if(cant==1)
			{

				ll_add(pArrayListPassenger, passengerAux);
			}
		}while(!feof(pFile));
		isOk=1;
	}
    return isOk;
}
