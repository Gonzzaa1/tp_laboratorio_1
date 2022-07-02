#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"
#include "MyFunction.h"
#include "Menus.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int isOk = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* file = fopen(path,"r");

		if(file == NULL)
		{
			printf("NO SE PUDO ABRIR EL ARCHIVO\n");

		}
		else
		{
			parser_PassengerFromText(file, pArrayListPassenger);
			printf("CARGA EXITOSA \n");
			isOk = 1;
		}

		fclose(file);
	}
    return isOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int isOk = 0;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* file = fopen(path,"rb");

		if(file == NULL)
		{
			printf("No se pudo abrir el archivo\n");
		}
		else
		{
			parser_PassengerFromBinary(file, pArrayListPassenger);
			isOk = 1;
		}

		fclose(file);
	}
	return isOk;
}
/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* nextID)
{
	int isOk = 0;
	char respuesta;

	Passenger* newPassenger = Passenger_new();

	if(newPassenger == NULL && nextID)
	{
		printf("No se pudo obtener memoria\n");
	}
	else
	{
		if( pArrayListPassenger != NULL)
		{
			system("cls");
			printf("\n-----------------------------------------"
				   "\n           ALTA DE PASAJERO              "
				   "\n-----------------------------------------\n");

			newPassenger->id = *nextID;

			printf("Id: %d\n", newPassenger->id);

			if(get_String(newPassenger->nombre, 50, "Ingrese nombre: ", "Dato incorrecto. \n"))
			{
				if(get_String(newPassenger->apellido, 50, "Ingrese apellido: ", "Dato incorrecto. \n"))
				{
					if(cargarPrecio(&newPassenger->precio))
					{
						if(cargarCodigoVuelo(newPassenger->codigoVuelo, 10))
						{
							if(cargarTipoPasajer(&newPassenger->tipoPasajero))
							{
								if(cargarEstadoVuelo(&newPassenger->estadoVuelo))
								{
									system("cls");
									printf("\n-----------------------------------------"
										   "\n             NUEVO  PASAJERO             "
										   "\n-----------------------------------------");

									mostrarPasajero(newPassenger);
									if(get_char(&respuesta, "Desea confirmar la carga (s - n): ", "Dato invalido"))
									{
										if(respuesta == 's')
										{
											ll_add(pArrayListPassenger, newPassenger);
											(*nextID)++;
											system("cls");
											printf("\n CARGA EXITOSA      ");
											isOk = 1;
										}
										else
										{
											system("cls");
											printf("\n CARGA CANCELADO     ");
										}
									}
								}
								else
								{
									system("cls");
									printf("\n ERROR EN LA CARGAR     ");
								}
							}
							else
							{
								system("cls");
								printf("\n ERROR EN LA CARGAR     ");
							}
						}
						else
						{
							system("cls");
							printf("\n ERROR EN LA CARGAR     ");
						}
					}
					else
					{
						system("cls");
						printf("\n ERROR EN LA CARGAR     ");
					}
				}
				else
				{
					system("cls");
					printf("\n ERROR EN LA CARGAR     ");
				}
			}
			else
			{
				system("cls");
				printf("\n ERROR EN LA CARGAR     ");
			}
		}
	}
    return isOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int isOk = 0;
	char salir = 'n';
	int id;
	int indice = 0;
	Passenger* passengerAux = NULL;
	char respuesta;
	char auxString[50];
	float precio;
	int tipoPasajero;
	char desc[50];
	char descNuevo[50];

	if(pArrayListPassenger != NULL)
	{
		system("cls");
		printf("\n-------------------------------------------"
			   "\n           MODIFICAR PASAJERO              "
			   "\n-------------------------------------------\n");

		if(controller_ListPassenger(pArrayListPassenger))
		{
			if(get_Int(&id, 1, 100000, "INGRESAR ID DEL PASAJERO: ", "ID INVALIDO") && buscarPasajeroID(pArrayListPassenger, &indice, id))
			{
				do
				{
					passengerAux = (Passenger*) ll_get(pArrayListPassenger, indice);
					if(passengerAux ==NULL)
					{
						printf("\nPASAJERO NO ENCONTRADO\n");
					}
					else
					{
						mostrarPasajero(passengerAux);
						switch(menuModificar())
						{
							case 1:
								system("cls");
								mostrarPasajero(passengerAux);
								printf("\n\n");
								if(get_String(auxString, 50, "INGRESE NUEVO NOMBRE: ","DATOS INVALIDOS." ))
								{
									printf("\n\n");
									printf("NOMBRE ANTERIOR: %s\n",passengerAux->nombre);
									printf("NOMBRE NUEVO: %s\n", auxString);
									get_char(&respuesta, "DESEA CONFIRMAR CAMBIO? ", "DATO INVALIDO.");
									if(respuesta == 's')
									{
										strcpy(passengerAux->nombre,auxString);
										printf("\nMODIFICACION EXITOSA\n");
									}
									else
									{
										printf("\nMODIFICACION CANCELADA\n");
									}
								}
								salir = 's';
								system("cls");
								break;
							case 2:
								system("cls");
								mostrarPasajero(passengerAux);
								printf("\n\n");
								if(get_String(auxString, 50, "INGRESE NUEVO APELLIDO: ","DATOS INVALIDOS." ))
								{
									printf("\n\n");
									printf("APELLIDO ANTERIOR: %s\n",passengerAux->apellido);
									printf("APELLIDO NUEVO: %s\n", auxString);
									get_char(&respuesta, "DESEA CONFIRMAR CAMBIO? ", "DATO INVALIDO.");
									if(respuesta == 's')
									{
										strcpy(passengerAux->apellido,auxString);
										printf("\nMODIFICACION EXITOSA\n");
									}
									else
									{
										printf("\nMODIFICACION CANCELADA\n");
									}
								}
								salir = 's';
								system("cls");
								break;
							case 3:
								system("cls");
								mostrarPasajero(passengerAux);
								printf("\n\n");
								if(get_Float(&precio, 0, 9999999, "INGRESE NUEVO PRECIO: $", "DATOS INVALIDOS."))
								{
									printf("\n\n");
									printf("PRECIO ANTERIOR: $%.2f\n",passengerAux->precio);
									printf("PRECIO NUEVO: $%.2f\n", precio);
									get_char(&respuesta, "DESEA CONFIRMAR CAMBIO? ", "DATO INVALIDO.");
									if(respuesta == 's')
									{
										passengerAux->precio = precio;
										printf("\nMODIFICACION EXITOSA\n");
									}
									else
									{
										printf("\nMODIFICACION CANCELADA\n");
									}
								}
								salir = 's';
								system("cls");
								break;
							case 4:
								system("cls");
								mostrarPasajero(passengerAux);
								printf("\n\n");
								if(get_Codigo(auxString, 8, "INGRESE NUEVO CODIGO DE VUELO: ","DATOS INVALIDOS." ))
								{
									printf("\n\n");
									printf("CODIGO DE VUELO ANTERIOR: %s\n",passengerAux->codigoVuelo);
									printf("CODIGO DE VUELO NUEVO: %s\n", auxString);
									get_char(&respuesta, "DESEA CONFIRMAR CAMBIO? ", "DATO INVALIDO.");
									if(respuesta == 's')
									{
										strcpy(passengerAux->codigoVuelo,auxString);
										printf("\nMODIFICACION EXITOSA\n");
									}
									else
									{
										printf("\nMODIFICACION CANCELADA\n");
									}
								}
								salir = 's';
								system("cls");
								break;
							case 5:
								system("cls");
								mostrarPasajero(passengerAux);
								printf("\n\n");
								if(cargarTipoPasajer(&tipoPasajero))
								{
									printf("\n\n");
									cargar_descripcion("tipoPasajero", desc, passengerAux->tipoPasajero);
									cargar_descripcion("tipoPasajero", descNuevo, tipoPasajero);
									printf("TIPO ANTERIOR: %s\n",desc);
									printf("TIPO NUEVO: %s\n", descNuevo);
									get_char(&respuesta, "DESEA CONFIRMAR CAMBIO? ", "DATO INVALIDO.");
									if(respuesta == 's')
									{
										passengerAux->tipoPasajero = tipoPasajero;
										printf("\nMODIFICACION EXITOSA\n");
									}
									else
									{
										printf("\nMODIFICACION CANCELADA\n");
									}
								}
								salir = 's';
								system("cls");
								break;
							case 6:
								system("cls");
								salir = 's';
								break;
						}
					}
				}while(salir != 's');
			}
		}
}
    return isOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int isOk;
	char respuesta;
	int indice;
	int id;
	Passenger* passengerAux = NULL;

	if(pArrayListPassenger != NULL)
	{
		bajaEncabezado();
		if(controller_ListPassenger(pArrayListPassenger))
		{
			if(get_Int(&id, 1, 100000, "INGRESAR ID DEL PASAJERO: ", "ID INVALIDO") && buscarPasajeroID(pArrayListPassenger, &indice, id))
			{
				passengerAux = (Passenger*) ll_get(pArrayListPassenger, indice);
				if(passengerAux ==NULL)
				{
					printf("\nPASAJERO NO ENCONTRADO\n");
				}
				else
				{
					bajaEncabezado();
					mostrarPasajero(passengerAux);
					get_char(&respuesta, "DESDES CONFIRMAR LA BAJA? (s/n) : ", "DATO INVALIDO.");
					system("cls");
					if(respuesta == 's')
					{
						ll_remove(pArrayListPassenger, indice);
						printf("\n BAJA EXISTOSA\n");
						isOk = 1;
					}
					else
					{
						printf("\n BAJA CANCELADA\n");
					}

				}
			}
		}
	}
    return isOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int isOk = 0;
	int tam;
	Passenger* pasajero;

	if(pArrayListPassenger != NULL)
	{
		if(!ll_isEmpty(pArrayListPassenger))
		{
			listaEncabezado();
			tam = ll_len(pArrayListPassenger);
			for(int i=0; i < tam; i++)
			{
				pasajero = (Passenger*)ll_get(pArrayListPassenger, i);;
				mostrarPasajeroFila(pasajero);
				isOk = 1;
			}
		}
		else
		{
			system("cls");
			printf("\nNo hay pasajeros en el sistema\n");
		}
	}
	return isOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int isOk = 0;
	int formato;

	if(pArrayListPassenger != NULL)
	{
		if(!ll_isEmpty(pArrayListPassenger))
		{
			switch(menuOrdenar())
			{
			case 1:
				if(get_Int(&formato, 0, 1, "INGRESE FORMATO (ASCENDENTE = 1 / DESCENDENTE = 0) : ", "DATO INVALIDO."))
				{
					ll_sort(pArrayListPassenger, Passenger_SortById, formato);
				}
				break;
			case 2:
				if(get_Int(&formato, 0, 1, "INGRESE FORMATO (ASCENDENTE = 1 / DESCENDENTE = 0) : ", "DATO INVALIDO."))
				{
					ll_sort(pArrayListPassenger, Passenger_SortByApellido, formato);
				}
				break;
			case 3:
				if(get_Int(&formato, 0, 1, "INGRESE FORMATO (ASCENDENTE = 1 / DESCENDENTE = 0) : ", "DATO INVALIDO."))
				{
					ll_sort(pArrayListPassenger, Passenger_SortByTipo, formato);
					ll_sort(pArrayListPassenger, Passenger_SortByCodigo, formato);
				}
				break;
			case 4:
				if(get_Int(&formato, 0, 1, "INGRESE FORMATO (ASCENDENTE = 1 / DESCENDENTE = 0) : ", "DATO INVALIDO."))
				{
					ll_sort(pArrayListPassenger, Passenger_SortByCodigo, formato);
					ll_sort(pArrayListPassenger, Passenger_SortById, formato);
				}
				break;
			case 5:
				break;
			}
			isOk = 1;
		}
	}

    return isOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int isOk = 0;
	int tam;
	Passenger* aux = NULL;
	char descripcionTipo[20];
	char descrpicionEstado[20];

	if( path != NULL && pArrayListPassenger != NULL)
	{
		FILE* file = fopen(path, "w");

		if(file == NULL)
		{
			printf("No se pudo conseguir memoria\n");
		}
		else
		{
			tam = ll_len(pArrayListPassenger);

			fprintf(file, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");

			for(int i=0; i<tam; i++)
			{
				aux = (Passenger*) ll_get(pArrayListPassenger, i);
				cargar_descripcion("tipoPasajero", descripcionTipo, aux->tipoPasajero);
				cargar_descripcion("estadoVuelo", descrpicionEstado, aux->estadoVuelo);
				fprintf(file, "%d,%s,%s,%.2f,%s,%s,%s\n", aux->id,aux->nombre,aux->apellido,aux->precio,aux->codigoVuelo,descripcionTipo,descrpicionEstado);
			}
			isOk = 1;
			printf("Guardado exitosamente.");

		}

		fclose(file);
	}
	return isOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int isOk = 0;
	int tam;
	Passenger* aux = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		FILE* file = fopen(path, "wb");

		if(file == NULL)
		{
			printf("No se pudo conseguir memoria\n");
		}
		else
		{
			tam = ll_len(pArrayListPassenger);

			for(int i = 0; i < tam; i++)
			{
				aux = (Passenger*) ll_get(pArrayListPassenger, i);
				fwrite(aux, sizeof(Passenger), 1, file);
			}
			isOk = 1;
			printf("Guardado exitosamente.");
		}

		fclose(file);
	}
	return isOk;
}
int controller_loadNextID(char* path, int* pNextId)
{
	int isOk = 0;

	FILE* file = fopen(path, "rb");

	if(file != NULL)
	{
		fread(pNextId, sizeof(int), 1, file);
		isOk = 1;
	}

	fclose(file);

    return isOk;
}
int controller_saveId(char* path, int* pNextId)
{
	int isOk = 0;

	if(path != NULL && pNextId != NULL)
	{
		FILE* file = fopen(path, "wb");
		if(file != NULL)
		{
			fwrite(pNextId, sizeof(int), 1, file);
			printf("IDs actualizados\n");
			isOk = 1;
		}
		fclose(file);

	}
	return isOk;
}
int controller_loadIdFromBinary(char* path , int* nextId)
{
	int isOk = 0;

	if(path != NULL && nextId != NULL)
	{

		FILE* file = fopen(path, "rb");

		if(file == NULL)
		{
			printf("Error al leer el archivo de IDs\n");
		}
		else
		{
			fread(nextId, sizeof(int), 1, file);
			isOk = 1;
		}
	}
	return isOk;


}
