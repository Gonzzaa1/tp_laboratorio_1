#ifndef MENU_H_
#define MENU_H_



#endif /* MENU_H_ */

/** \brief Funcion que me muestra mi menu principal
 *
 * \param Km int cantidad de kilometros
 * \param aero float precio del vuelo de aerolineas
 * \param latam float precio de vuelo de Latam
 * \return int retorna la opcion elegida
 *
 */
int menu(int Km, float aero, float latam);
//-----------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------//
/** \brief Funcion de la opcion 1 donde pedimos que ingrese los kilometros
 *
 * \param pKm int* referencia a la direccion de memoria donde guardaremos los kilometros ingresados
 * \param pflag int* referencia a la direccion de memoria de la bandera de kilometros
 * \return int si se corrio completamente sin error la funcion, retorna 1 sino 0
 *
 */
int opcion1(int* pKm, int* pFlag);
/** \brief Funcion de la opcion 2 donde pedimos que ingrese los precios de los vuelos
 *
 * \param pPrecioAero float* referencia a la direccion de memoria donde guardaremos el precio para Aerolineas
 * \param pPrecioLatam float* referencia a la direccion de memoria donde guardaremos el precio para Latam
 * \param pFlag int* referencia a la direccion de memoria de la bandera de Aerolineas
 * \param pFlag2 int* referencia a la direccion de memoria de la bandera de Latam
 * \return int si se corrio completamente sin error la funcion, retorna 1 sino 0
 *
 */
int opcion2(float* pPrecioAero, float* pPrecioLatam, int* pFlag, int* pFlag2);
/** \brief Funcion de la opcion 3 donde se realizan los calculos
 *
 * \param pFlag int* referencia a la direccion de memoria de la bandera de calculos
 * \param flagKm int valor de la bandera de kilometros
 * \param flagLatam int valor de la bandera de Latam
 * \param flagAero int valor de la bandera de Aerolineas
 * \param km int cantidad de kilometros ingresados
 * \param precioAero float precio del vuelo por Aerolineas
 * \param precioLatam float precio del vuelo por Latam
 * \param pAeroTD float* referencia a la direccion de memoria donde guardo el resultado de tarjeta de debito para Aerolineas
 * \param pAeroTC float* referencia a la direccion de memoria donde guardo el resultado de tarjeta de cretido para Aerolineas
 * \param pAeroBTC float* referencia a la direccion de memoria donde guardo el resultado de bitcoin para Aerolineas
 * \param pAeroUni float* referencia a la direccion de memoria donde guardo el resultado precio x kilometros para Aerolineas
 * \param pLatamTD float* referencia a la direccion de memoria donde guardo el resultado de tarjeta de debito para Latam
 * \param pLatamTC float* referencia a la direccion de memoria donde guardo el resultado de tarjeta de credito para Latam
 * \param pLatamBTC float* referencia a la direccion de memoria donde guardo el resultado de bitcoin para Latam
 * \param pLatamUni float* referencia a la direccion de memoria donde guardo el resultado precio x kilometros para Latam
 * \param pDif float* referencia a la direccion de memoria donde guardo el resultado de la diferencia de precio de Aerolinas y Latam
 * \return int si se corrio completamente sin error la funcion, retorna 1 sino 0
 *
 */
int opcion3(int *pFlag,int flagKm,int flagLatam, int flagAero,int km, float precioAero, float precioLatam,float* pAeroTD,float* pAeroTC,float* pAeroBTC,float* pAeroUni,float* pLatamTD,float* pLatamTC,float* pLatamBTC,float* pLatamUni,float* pDif);
/** \brief Funcion de la opcion 4 donde muestro los resultados en pantalla
 *
 * \param flagCalculos int valor de la bandera de calculos
 * \param km int cantidad de kilometros ingresados
 * \param precioAero float precio de vuelo por Aerlineas
 * \param precioLatam float precio de vuelo por Latam
 * \param aeroTD float precio final abonando con tarjeta de debito de Aerolineas
 * \param aeroTC float precio final abonando con tarjeta de credito de Aerolineas
 * \param aeroBTC float precio final abonando con bitcion de Aerolineas
 * \param aeroUni float precio x kilometros de Aerolineas
 * \param latamTD float precio final abonando con tarjeta de debito de Latam
 * \param latamTC float precio final abonando con tarjeta de credito de Latam
 * \param latamBTC float precio final abonando con bitcoin de Latam
 * \param latamUni float precio x kilometros de Latam
 * \param dif float diferencia de precio entre aerolineas y latam
 * \return int si se corrio completamente sin error la funcion, retorna 1 sino 0
 *
 */
int opcion4(int flagCalculos,int km, float precioAero, float precioLatam,float aeroTD,float aeroTC,float aeroBTC,float aeroUni,float latamTD,float latamTC,float latamBTC,float latamUni,float dif);
/** \brief Funcion de la opcion 5 donde se realiza una carga forzada
 *
 * \return void
 *
 */
void opcion5();
//-----------------------------------------------------------------------------------------------------------------------------//
//-----------------------------------------------------------------------------------------------------------------------------//
/** \brief Funcion que donde se pregunta si desea confirmar la carga
 *
 * \return char
 *
 */
char confimar();
/** \brief Funcion de submenu de carga de precio de vuelo
 *
 * \param empresa int* referencia a la direccion de memoria donde guardo la opcion de la empresa
 * \return int 1 si se elijio Aerolineas o 2 si se elijio Latam
 *
 */
int empresa(int* empresa);
/** \brief Funcion donde se pregunta si se desea sobrescribir un valor
 *
 * \return char rotarna la respuesta s/n
 *
 */
char sobrescribir();
/** \brief Funcion donde todas las banderas y precios vuelven a valor 0
 *
 * \param pKm int*
 * \param preciaA float*
 * \param precioL float*
 * \param flagKm int*
 * \param flagLatam int*
 * \param flagVuelos int*
 * \param flagCalculos int*
 * \return void
 *
 */
void reset(int* pKm, float* pPreciaA, float* pPrecioL, int* pFlagKm,int* pFlagLatam, int* pFlagAero, int* pFlagCalculos);
