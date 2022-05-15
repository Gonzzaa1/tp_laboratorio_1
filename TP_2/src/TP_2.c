#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "ArrayStatus.h"
#include "ArrayTypes.h"

#define LEN 4
#define LEN_PASSENGER 2000

#define FORMAT_COLUMN 1
#define FORMAT_ROW 2

#define ASCENDENTE 1
#define DESCENDENTE 2

int main(void)
{

	setbuf(stdout, NULL);

	char exit = 'n';
	int id = 1000;
	int flag = 1;
	int flagCF = 0;

	Passenger passenger[LEN_PASSENGER];

	TypePassenger types[LEN] =
	{
		{5000, "First Class"},
		{5001, "Business Class"},
		{5002, "Premium Class"},
		{5003, "Economy Class"}
	};
	StatusFlight status[LEN] =
	{
		{3000, "On time"},
		{3001, "Arrival"},
		{3002, "Delayed"},
		{3003, "Cancelled"}
	};

	initPassengers(passenger, LEN_PASSENGER);


	do
	{
		system("cls");
		printf("By Lopez Gonzalo Javier - Div G\n\n");

		switch(menu())
		{
			case 1:
				altaPasajero(passenger, LEN_PASSENGER, &id,types,status,LEN);
				flag = 0;
				break;
			case 2:
				if(flag)
				{
					printf("\n\nNo se puede borrar pasajeros si no hay ninguno cargado en sistema\n");
				}
				else
				{
					system("cls");
					listarPasajeros(passenger, LEN_PASSENGER, types, status, LEN, FORMAT_ROW,flag);
					printf("\nIngrese id: ");
					scanf("%d", &id);
					removePassenger(passenger, LEN_PASSENGER, id);
				}
				system("pause");
				break;
			case 3:
				if(flag)
				{
					printf("\n\nNo se puede modificar pasajeros si no hay ninguno cargado en sistema\n");
				}
				else
				{
					system("cls");
					listarPasajeros(passenger, LEN_PASSENGER, types, status, LEN, FORMAT_ROW,flag);
					modPassenger(passenger, LEN_PASSENGER, types, status, LEN);
				}
				system("pause");
				break;
			case 4:
				system("cls");
				if(flag)
				{
					printf("\n\nNo se puede informar pasajeros si no hay ninguno cargado en sistama\n");
				}
				else
				{
					switch(menuInforme())
					{
						case 1:
							sortPassengersByName(passenger, LEN_PASSENGER, ASCENDENTE);
							break;
						case 2:
							sortPassengersByName(passenger, LEN_PASSENGER, DESCENDENTE);
							break;
						case 3:
							informe(passenger, LEN_PASSENGER);
							printf("\n\n");
							break;
						case 4:
							sortPassengersByCode(passenger, LEN_PASSENGER, ASCENDENTE);
							break;
						case 5:
							sortPassengersByCode(passenger, LEN_PASSENGER, DESCENDENTE);
							break;
					}
					listarPasajeros(passenger, LEN_PASSENGER, types, status, LEN, FORMAT_ROW,flag);
				}
				system("pause");
				break;
			case 5:
				if(flagCF)
				{
					printf("\n\nYa se realizo una carga forzada de pasajero\n");
				}
				else
				{
					cargaForzada(passenger, LEN_PASSENGER, 5, &id, &flag);
					printf("\n\nSe acaba de realizar una carga forzada de pasajero\n");
					flagCF = 1;
				}
				system("pause");
				break;
			case 6:
				exit = 's';
				break;
		}

	}while(exit != 's');

	return EXIT_SUCCESS;
}
