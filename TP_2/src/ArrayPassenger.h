#include "ArrayTypes.h"
#include "ArrayStatus.h"

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flyCode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;

}typedef Passenger;

#endif /* ARRAYPASSENGER_H_ */

//------------------------------------------------------------------------------------
//                             **** TP PROTOTYPES ****
//------------------------------------------------------------------------------------

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);
/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[],
				float price, int typePassenger, char flycode[]);
/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByName(Passenger* list, int len, int order);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);

//------------------------------------------------------------------------------------
//                            **** MY PROTOTYPES ****
//------------------------------------------------------------------------------------

/** \brief menu principal
*
* \return int retorna la opcion deseada
*
*/
int menu();
/** \brief funcion para validar cadenas
*
* \param char puntero a una cadena de texto
*
* \return int -1 si la cadena contiene numeros y 1 si la cadena contiene letras
*
*/
int validarCadenas(char* texto);
/** \brief Menu para elegir aerolinea
*
* \return int retorna la opcion deseada
*
*/
int empresa();
/** \brief recorre el array de pasajeros y se fija si hay espacio
*
* \param passenger puntero al array de pasajeros
* \param len int tamaño de array
* \param len pIndex puntero a la variable que contiene indice de array
* \return int
*
*/
int buscarLugar(Passenger* passenger, int len, int* pIndex);
/** \brief da el alta a un pasajero
*
* \param passenger Passenger* puntero al array de pasajeros
* \param len int tamaño del array
* \param pNextId int* puntero a la variable donde guardo ids
* \param types TypePassenger* puntero al array de tipos de pasajeros
* \param status StatusFlight* puntero al array de estado de vuelos
* \param lenTS int tamano para los arrays de tipos de pasajeros y estados de vuelo
*
* \return int
*
*/
int altaPasajero(Passenger* passenger, int len, int* pNextId,TypePassenger* types, StatusFlight* status,int lenTS);
/** \brief muestra un pasajero en formato fila o columna
*
* \param passenger Passenger array de pasajeros
* \param types TypePassenger* puntero al array de tipos de pasajeros
* \param status StatusFlight* puntero al array de estado de vuelos
* \param lenTS int tamano para los arrays de tipos de pasajeros y estados de vuelo
* \param format int mostrar en formato columna o fila
*
* \return int
*
*/
int showPassenger(Passenger passenger, TypePassenger* types, StatusFlight* status,int lenTS, int format);
/** \brief muestra el listado de pasajeros
*
* \param passenger Passenger* puntero al array de pasajeros
* \param len int tamaño del array
* \param types TypePassenger* puntero al array de tipos de pasajeros
* \param status StatusFlight* puntero al array de estado de vuelos
* \param lenTS int tamano para los arrays de tipos de pasajeros y estados de vuelo
* \param format int mostrar en formato columna o fila
* \param flag int valor de la bandera
*
* \return int
*
*/
int listarPasajeros(Passenger* passenger, int len, TypePassenger* types, StatusFlight* status,int lenTS, int format,int flag);
/** \brief carga forzada de pasajeros
*
* \param passenger Passenger* puntero al array de pasajeros
* \param len int tamaño del array
* \param cant int limite de la carga forzada
* \param pNextId int* puntero a la variable donde guardo ids
* \param flag int* puntero a la variable de la bandera
*
* \return int
*
*/
int cargaForzada(Passenger passenger[], int len, int cant, int* pNextId,int* flag);
/** \brief funcion que para modificar datos de los pasajeros por ID
*
* \param passenger Passenger* puntero al array de pasajeros
* \param len int tamaño del array
* \param types TypePassenger* puntero al array de tipos de pasajeros
* \param status StatusFlight* puntero al array de estado de vuelos
* \param lenTS int tamano para los arrays de tipos de pasajeros y estados de vuelo
*
* \return int
*
*/
int modPassenger(Passenger* passenger, int len, TypePassenger* types, StatusFlight* status,int lenTS);
/** \brief menu de modificar datos de pasajeros
*
* \return int retorna la opcion deseada
*
*/
int menuMod();
/** \brief funcion donde calculo promedio de precio, precio total de pasajes y cantidad de pasajes mayores al promedio
*
* \param passenger Passenger* puntero al array de pasajeros
* \param len int tamaño del array
*
* \return int
*
*/
int informe(Passenger* passenger, int len);
/** \brief menu de informes
*
* \return int retorna la opcion deseada
*
*/
int menuInforme();


















