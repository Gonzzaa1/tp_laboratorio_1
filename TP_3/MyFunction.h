#include "LinkedList.h"

#ifndef MYFUNCTION_H_
#define MYFUNCTION_H_



#endif /* MYFUNCTION_H_ */

int cargar_descripcion(char* tipo, char* descripcion, int index);
int mostrarPasajero(Passenger* pasajero);
int mostrarPasajeroFila(Passenger* pasajero);

int delete_Enter(char* string, int tam);
int get_String(char* string, int len, char* mensaje, char* error);
int esEntero(char* string);
int get_Int(int* numero, int minimo, int maximo, char* mensaje, char* error);
int esFloat(char* string);
int get_Float(float* numero, int minimo, int maximo, char* mensaje, char* error);
int get_Codigo(char* codigo, int tam, char* mensaje, char* error);
int get_char(char* caracter, char* mensaje, char* error);
int set_MayusStrig(char* string);

void listarTipos();
void listarEstados();

int cargarPrecio(float* precio);
int cargarCodigoVuelo(char* codigo, int tam);
int cargarTipoPasajer(int* tipo);
int cargarEstadoVuelo(int* estado);

int cargarID(LinkedList* listaPasajeros);
int validarID(LinkedList* pArrayListPassenger, int id);
int buscarID(LinkedList* pArrayListPassenger, int* id);
int buscarPasajeroID(LinkedList* listadoPasajeros, int* posId, int id);
