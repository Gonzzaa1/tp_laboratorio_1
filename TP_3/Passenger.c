/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Passenger.h"
#include "MyFunction.h"


Passenger* Passenger_new()
{
	Passenger* new_passenger = NULL;

	new_passenger = (Passenger*) malloc(sizeof(Passenger));

	if(new_passenger != NULL)
	{
		new_passenger->id = 0;
		strcpy(new_passenger->nombre,"nn");
		strcpy(new_passenger->apellido,"nn");
		new_passenger->precio = 0;
		new_passenger->tipoPasajero = 0;
		strcpy(new_passenger->codigoVuelo,"nn");
	}
	return new_passenger;
}
Passenger* Passenger_newParametros(char* idStr,char* nombre,char* apellido,char* precioStr, char* codigoVuelo, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* passenger = Passenger_new();

	int id;
	float precio;

	id = atoi(idStr);
	precio = atof(precioStr);

	if(!(Passenger_setId(passenger, id)
			&& Passenger_setNombre(passenger, nombre)
			&& Passenger_setApellido(passenger, apellido)
			&& Passenger_setPrecio(passenger, precio)
			&& Passenger_setCodigoVuelo(passenger, codigoVuelo)
			&& Passenger_setTipoPasajero(passenger, tipoPasajeroStr)
			&& Passenger_setEstadoVuelo(passenger, estadoVueloStr)))
	{
		Passenger_delete(passenger);
		passenger = NULL;
	}

	return passenger;
}
void Passenger_delete(Passenger* this)
{
	free(this);
}

int Passenger_setId(Passenger* this,int id)
{
	int isOk  = 0;

	if(this!= NULL && id > 0)
	{
		this->id = id;
		isOk = 1;
	}
	return isOk;
}
int Passenger_getId(Passenger* this,int* id)
{
	int isOk  = 0;

	if(this!= NULL && id != NULL)
	{
		*id = this->id;
		isOk = 1;
	}
	return isOk;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int isOk  = 0;

	if(this!= NULL && strlen(nombre) < 50 && strlen(nombre) > 0)
	{
		strlwr(nombre);
		nombre[0] = toupper(nombre[0]);
		strcpy(this->nombre,nombre);
		isOk = 1;
	}
	return isOk;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int isOk  = 0;

	if(this!= NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		isOk = 1;
	}
	return isOk;
}
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int isOk  = 0;

	if(this!= NULL && strlen(apellido) < 50 && strlen(apellido) > 0)
	{
		strlwr(apellido);
		apellido[0] = toupper(apellido[0]);
		strcpy(this->apellido,apellido);
		isOk = 1;
	}
	return isOk;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int isOk  = 0;

	if(this!= NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		isOk = 1;
	}
	return isOk;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int isOk  = 0;

	if(this!= NULL && strlen(codigoVuelo) < 9 && strlen(codigoVuelo) > 0)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		isOk = 1;
	}
	return isOk;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int isOk  = 0;

		if(this!= NULL && codigoVuelo != NULL)
		{
			strcpy(codigoVuelo,this->codigoVuelo);
			isOk = 1;
		}
		return isOk;
}
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int isOk  = 0;

	if(this != NULL && tipoPasajero != NULL)
	{

		if (!strcmp(tipoPasajero, "EconomyClass"))
		{
			this->tipoPasajero = 1;
			isOk = 1;
		}
		else if (!strcmp(tipoPasajero, "ExecutiveClass"))
		{
			this->tipoPasajero = 2;
			isOk = 1;
		}
		else if (!strcmp(tipoPasajero, "FirstClass"))
		{
			this->tipoPasajero = 3;
			isOk = 1;
		}

	}
	return isOk;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int isOk  = 0;

	if(this!= NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		isOk = 1;
	}
	return isOk;
}
int Passenger_setPrecio(Passenger* this,float precio)
{
	int isOk  = 0;

	if(this!= NULL && precio > 0)
	{
		this->precio = precio;
		isOk = 1;
	}
	return isOk;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int isOk  = 0;

	if(this!= NULL && precio != NULL)
	{
		*precio = this->precio;
		isOk = 1;
	}
	return isOk;
}
int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	int isOk = 0;

	if(this != NULL && estadoVuelo != NULL)
	{
		if(!strcmp("Aterrizado;;;;;;", estadoVuelo))
		{
			this->estadoVuelo  = 1;
			isOk = 1;
		}
		else if(!strcmp("Demorado;;;;;;", estadoVuelo))
		{
			this->estadoVuelo  = 2;
			isOk = 1;
		}
		else if(!strcmp("En Horario;;;;;;", estadoVuelo))
		{
			this->estadoVuelo  = 3;
			isOk = 1;
		}
		else if(!strcmp("En Vuelo;;;;;;", estadoVuelo))
		{
			this->estadoVuelo  = 4;
			isOk = 1;
		}
	}
	return isOk;
}
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int isOk = 0;

	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		isOk = 1;
	}
	return isOk;
}
int Passenger_SortById(void* a, void* b)
{
	int isOk;

	if(a != NULL && b != NULL)
	{
		Passenger* aux1 = (Passenger*)a;
		Passenger* aux2 = (Passenger*)b;

		if(aux1->id == aux2->id)
		{
			isOk = 0;
		}
		else if(aux1->id > aux2->id)
		{
			isOk = 1;
		}
		else
		{
			isOk = -1;
		}
	}
	return isOk;
}
int Passenger_SortByApellido(void* a, void* b)
{
	int isOk;

	if(a != NULL && b != NULL)
	{
		Passenger* aux1 = (Passenger*)a;
		Passenger* aux2 = (Passenger*)b;

		if(strcmp(aux1->apellido, aux2->apellido) == 0)
		{
			isOk = 0;
		}
		else if(strcmp(aux1->apellido, aux2->apellido) > 0)
		{
			isOk = 1;
		}
		else
		{
			isOk = -1;
		}

	}
	return isOk;
}
int Passenger_SortByCodigo(void* a, void* b)
{
	int isOk;

	if(a != NULL && b != NULL)
	{
		Passenger* aux1 = (Passenger*)a;
		Passenger* aux2 = (Passenger*)b;

		if(strcmp(aux1->codigoVuelo, aux2->codigoVuelo) == 0)
		{
			isOk = 0;
		}
		else if(strcmp(aux1->codigoVuelo, aux2->codigoVuelo) > 0)
		{
			isOk = 1;
		}
		else
		{
			isOk = -1;
		}

	}
	return isOk;
}
int Passenger_SortByTipo(void* a, void* b)
{
	int isOk;

	if(a != NULL && b != NULL)
	{
		Passenger* aux1 = (Passenger*)a;
		Passenger* aux2 = (Passenger*)b;

		if(aux1->tipoPasajero == aux2->tipoPasajero)
		{
			isOk = 0;
		}
		else if(aux1->tipoPasajero > aux2->tipoPasajero)
		{
			isOk = 1;
		}
		else
		{
			isOk = -1;
		}
	}
	return isOk;
}
