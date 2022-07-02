#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "MyFunction.h"


int cargar_descripcion(char* tipo, char* descripcion, int index)
{
	int isOk = 0;
	if(descripcion != NULL)
	{
		if(!strcmp("tipoPasajero", tipo))
		{
			switch(index)
			{
				case 1:
					strcpy(descripcion,"EconomyClass");
					break;
				case 2:
					strcpy(descripcion,"ExecutiveClass");
					break;
				case 3:
					strcpy(descripcion,"FirstClass");
					break;
			}
		}
		else if(!strcmp("estadoVuelo", tipo))
		{
			switch(index)
			{
				case 1:
					strcpy(descripcion,"Aterrizado");
					break;
				case 2:
					strcpy(descripcion,"Demorado");
					break;
				case 3:
					strcpy(descripcion,"En Horario");
					break;
				case 4:
					strcpy(descripcion,"En Vuelo");
					break;
			}
		}
		isOk = 1;
	}
	return isOk;
}
int mostrarPasajero(Passenger* pasajero)
{
	int isOk = 0;
	Passenger buffer;
	char descripcionTipo[50];
	char descripcionEstado[50];

	if(pasajero != NULL)
	{
		Passenger_getId(pasajero, &buffer.id);
		Passenger_getNombre(pasajero, buffer.nombre);
		Passenger_getApellido(pasajero, buffer.apellido);
		Passenger_getPrecio(pasajero, &buffer.precio);
		Passenger_getCodigoVuelo(pasajero, buffer.codigoVuelo);
		Passenger_getEstadoVuelo(pasajero, &buffer.estadoVuelo);
		Passenger_getTipoPasajero(pasajero, &buffer.tipoPasajero);

		if(cargar_descripcion("tipoPasajero", descripcionTipo, buffer.tipoPasajero) &&
		   cargar_descripcion("estadoVuelo", descripcionEstado, buffer.estadoVuelo))
		{
			printf("\nID: %d\n", buffer.id);
			printf("NOMBRE: %s\n", buffer.nombre);
			printf("APELLIDO: %s\n", buffer.apellido);
			printf("PRECIO: $%.2f\n", buffer.precio);
			printf("CODIGO VUELO: %s\n", buffer.codigoVuelo);
			printf("TIPO PASAJERO: %s\n", descripcionTipo);
			printf("ESTADO VUELO: %s\n", descripcionEstado);

		}
		isOk = 1;
	}

	return isOk;
}
int mostrarPasajeroFila(Passenger* pasajero)
{
	int isOk = 0;
	Passenger buffer;
	char descripcionTipo[50];
	char descripcionEstado[50];

	if(pasajero != NULL)
	{
		Passenger_getId(pasajero, &buffer.id);
		Passenger_getNombre(pasajero, buffer.nombre);
		Passenger_getApellido(pasajero, buffer.apellido);
		Passenger_getPrecio(pasajero, &buffer.precio);
		Passenger_getCodigoVuelo(pasajero, buffer.codigoVuelo);
		Passenger_getEstadoVuelo(pasajero, &buffer.estadoVuelo);
		Passenger_getTipoPasajero(pasajero, &buffer.tipoPasajero);

		if(cargar_descripcion("tipoPasajero", descripcionTipo, buffer.tipoPasajero) &&
		   cargar_descripcion("estadoVuelo", descripcionEstado, buffer.estadoVuelo))
		{
			printf(" %4d  %-20s %-15s  $%7.2f      %7s     %-14s    %-10s \n",buffer.id, buffer.nombre,
					buffer.apellido, buffer.precio, buffer.codigoVuelo,descripcionTipo,descripcionEstado);

		}
	}
	return isOk;
}

int delete_Enter(char* string, int len)
{
	int isOk = 0;
	char aux[len];

	strncpy(aux,string,len);

	if(string != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(aux[i] == '\n')
			{
				aux[i] = '\0';
				strncpy(string, aux, len);
				isOk = 1;
				break;
			}
		}
	}
	return isOk;
}
int get_String(char* string, int len, char* mensaje, char* error)
{
	int isOk = 0;
	int flag = 0;
	int intentos = 2;
	char aux[len];

	if(string != NULL && mensaje != NULL && error != NULL && len > 0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			fgets(aux, len, stdin);

			if(delete_Enter(aux, len))
			{

				for(int i = 0;*(aux +i)!= '\0'; i++)
				{
					if(i != 0 && *(aux + i) == ' ')
					{
						continue;
					}
					if(!isalpha(*(aux + i)))
					{

						flag = 1;
						intentos --;
						printf("%s", error);
						break;
					}
				}
				if(flag == 0)
				{
					isOk = 1;
					strcpy(string, aux);
					set_MayusStrig(string);
					break;
				}

			}


		}while(intentos > 0);
	}
	if(intentos == 0)
	{
		printf("No se pudo cargar el dato.");
	}

	return isOk;
}
int esEntero(char* string)
{
	int isOk;
	int i = 0;

	if(string != NULL && strlen(string) > 0)
	{
		isOk = 1;

		while(string[i] != '\0')
		{
			if(string[i] < '0' || string[i] > '9')
			{
				isOk = 0;
				break;
			}
			i++;
		}
	}
	return isOk;
}
int get_Int(int* numero, int minimo, int maximo, char* mensaje, char* error)
{
	int isOk = 0;
	int intentos = 2;
	char auxCad[10];
	int num;

	if(numero != NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			fgets(auxCad, 10, stdin);

			for(int i = 0; i < 10; i++)
			{
				if(auxCad[i] == '\n')
				{
					auxCad[i] = '\0';
					break;
				}
			}
			if(esEntero(auxCad))
			{
				num = atoi(auxCad);
				if(num >= minimo && num <= maximo)
				{
					*numero = num;
					isOk = 1;
					break;
				}
				else
				{
					printf("%s", error);
					intentos--;
				}
			}
			else
			{
			printf("%s", error);
			intentos--;
			}
		}while(intentos > 0);
	}
	return isOk;
}
int esFloat(char* string)
{
	int isOk = 1;
	int flag = 0;

	if(string != NULL && strlen(string) > 0)
	{
		for(int i = 0; string[i] != '\0'; i ++)
		{

			if( i==0 && (string[i] == '+' || string[i] == '-'))
			{
				continue;
			}
			if(string[i] == '.')
			{
				flag = 1;
				continue;
			}
			if((string[i] > '9' || string[i] < '0')&&(flag == 1 && string[i] == '.'))
			{
				isOk = 0;
				break;
			}
		}
	}
	return isOk;
}
int get_Float(float* numero, int minimo, int maximo, char* mensaje, char* error)
{
	int isOk = 0;
	int intentos = 3;
	char auxCad[100];
	float fnum;

	if(numero != NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			fgets(auxCad, 100, stdin);

			if(delete_Enter(auxCad, 100) && esFloat(auxCad))
			{
				fnum = atof(auxCad);
				if(fnum > minimo && fnum < maximo)
				{
					*numero = fnum;
					isOk = 1;
					break;
				}
				else
				{
					printf("%s", error);
					intentos--;
				}
			}
			else
			{
			printf("%s", error);
			intentos--;
			}
		}while(intentos > 0);
	}
	return isOk;
}
int get_Codigo(char* codigo, int tam, char* mensaje, char* error)
{
	int isOk = 0;
	int intentos = 2;
	char string[tam];

	if(codigo != NULL && tam > 0)
	{
		do{
			printf("%s", mensaje);
			fflush(stdin);
			fgets(string, tam, stdin);

			if(delete_Enter(string, tam))
			{
				for(int i = 0; string[i] != '\0'; i++)
				{
					if(isalpha(string[i]))
					{

						string[i] = toupper(string[i]);
					}
				}
				strncpy(codigo, string, tam);
				isOk = 1;
				break;
			}
			else
			{
				printf("%s", error);
				intentos--;
			}
		}while(intentos > 0);

		if(!intentos)
		{

			printf("\nNo se ha podido ingresar el dato.\n");
		}
	}
	return isOk;
}
int get_char(char* caracter, char* mensaje, char* error)
{
	int isOk = 0;
	char opcion;
	int intentos = 2;

	if(caracter != NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &opcion);

			opcion = tolower(opcion);

			if(isalpha(opcion))
			{
				*caracter = opcion;
				isOk = 1;
				break;
			}
			else
			{
				printf("%s", error);
				intentos--;
			}
		}while(intentos > 0);
	}

	return isOk;
}
int set_MayusStrig(char* string)
{
	int isOk = 0;
	if(string != NULL)
	{
		strlwr(string);
		string[0] = toupper(string[0]);
		for (int i = 0; *(string + i) != '\0'; i++)
		{
			if ((*(string + i)) == ' ')
			{
				*(string + (i + 1)) = toupper(*(string + (i + 1)));
			}
		}
		isOk = 1;
	}
	return isOk;
}

void listarTipos()
{
	printf("\n Tipos de Pasajero  \n"
		   "----------------------\n"
		   " ID       CLASE        \n"
		   "----------------------\n"
		   "  1    EconomyClass \n"
		   "  2    ExecutiveClass \n"
		   "  3    FirstClass \n");
}
void listarEstados()
{
	printf("\n  Estados de Vuelo  \n"
		   "----------------------\n"
		   " ID     ESTADOS        \n"
		   "----------------------\n"
		   "  1    Aterrizado     \n"
		   "  2    Demorado       \n"
		   "  3    En Horario     \n"
		   "  4    En Vuelo       \n");
}

int cargarPrecio(float* precio)
{
	int isOk = 0;

	if(precio != NULL)
	{
		if(get_Float(precio, 0, 9999999, "Ingrese Precio de Vuelo: $", "Dato incorrecto. \n"))
		{
			isOk = 1;
		}
	}
	return isOk;
}
int cargarCodigoVuelo(char* codigo, int tam)
{
	int isOk = 0;

	if(codigo != NULL && tam > 0)
	{
		printf("\nEjemplo formato: 'AA0000A' \n");
		if(get_Codigo(codigo, tam, "Ingrese codigo de vuelo: ", "Dato incorrecto. \n"))
		{
			isOk = 1;
		}
	}
	return isOk;
}
int cargarTipoPasajer(int* tipo)
{
	int isOk = 0;
	int intentos = 2;

	if(tipo != NULL)
	{
		listarTipos();
		do
		{
			if(get_Int(tipo, 1, 3, "Ingrese ID:" , "ID Invalido"))
			{
				isOk = 1;
				break;
			}
			intentos--;
		}while(intentos > 0);
	}

	return isOk;
}
int cargarEstadoVuelo(int* estado)
{
	int isOk = 0;
	int intentos = 2;

	if(estado != NULL)
	{
		listarEstados();
		do
		{
			if(get_Int(estado, 1, 4, "Ingrese ID:" , "ID Invalido"))
			{
				isOk = 1;
				break;
			}
			intentos--;
		}while(intentos > 0);
	}

	return isOk;
}

int cargarID(LinkedList* listaPasajeros)
{
	int nextId = -1;
	int ultimo;

	if(listaPasajeros != NULL)
	{
		buscarID(listaPasajeros, &ultimo);

		nextId = ultimo + 1;
	}
	return nextId;
}
int validarID(LinkedList* pArrayListPassenger, int id)
{
	int isOk = 0;
	int auxID = 0;
	Passenger* passengerAux = NULL;

	if(pArrayListPassenger != NULL)
	{
		for(int i=0; i < ll_len(pArrayListPassenger); i++)
		{
			passengerAux = (Passenger*) ll_get(pArrayListPassenger, i);

			auxID = passengerAux->id;

			if(auxID == id)
			{
				isOk = 1;
			}
		}
	}
	return isOk;
}
int buscarID(LinkedList* pArrayListPassenger, int* id)
{
	int isOk = 0;
	int ultimo;
	Passenger* passengerAux = NULL;

	if(pArrayListPassenger != NULL && id != NULL)
	{

		if(ll_len(pArrayListPassenger))
		{

			for(int i=0; i < ll_len(pArrayListPassenger); i++)
			{
				passengerAux = (Passenger*) ll_get(pArrayListPassenger, i);

				if(i == 0 || passengerAux->id > ultimo)
				{
					ultimo = passengerAux->id;
				}
			}
			*id = ultimo + 1;
			isOk = 1;
		}
	}


	return isOk;
}

int buscarPasajeroID(LinkedList* listadoPasajeros, int* posId, int id)
{
	int isOk = 0;
	int auxID = 0;
	Passenger* passengerAux = NULL;

	if(listadoPasajeros != NULL && posId != NULL && *posId >= 0 && id >= 1)
	{
		for(int i = 0; i < ll_len(listadoPasajeros); i++)
		{
			passengerAux = ll_get(listadoPasajeros, i);

			if(passengerAux != NULL)
			{
				Passenger_getId(passengerAux, &auxID);

				if(id == auxID)
				{
					*posId = i;
					isOk = 1;
				}
			}
		}
	}
	return isOk;
}
