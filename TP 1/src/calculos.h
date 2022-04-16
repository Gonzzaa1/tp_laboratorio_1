#ifndef CALCULOS_H_
#define CALCULOS_H_



#endif /* CALCULOS_H_ */

/** \brief funcion que me hace el calculo de las tarjetas de debito
 *
 * \param pResultado float* referencia a la direccion de memoria del resultado
 * \param precioVuelo float valor precio del vuelo
 * \return int si se corrio completamente sin error la funcion retorna 1 sino 0
 */

int debitCard(float* pResultado, float precioVuelo);
/** \brief Funcion que hace el calculo para las tarjetas de credito
 *
 * \param pResultado float* referencia a una direccion de memoria que guardara el resultado
 * \param precioVuelo float valor de precio de vuelo
 * \return int si se corrio completamente sin error la funcion retorna 1 sino 0
 *
 */
int creditCard(float* pResultado, float precioVuelo);

/** \brief Funcion que hace el calculo para pasar de pesos a bitcoins
 *
 * \param pResultado float* referencia a una direccion de memoria que guardara el resultado
 * \param precioVuelo float valor de precio de vuelo
 * \return int si se corrio completamente sin error la funcion retorna 1 sino 0
 *
 */
int calcularBtc(float* pResultado, float precioVuelo);

/** \brief  Funcion que me calcula precio por km
 *
 * \param pResultado float* referencia a una direccion de memoria que guardara el resultado
 * \param precioVuelo float valor de precio de vuelo
 * \param km float cantidad de km
 * \return int si se corrio completamente sin error la funcion retorna 1 sino 0
 *
 */
int precioUnitario(float* pResultado, float precioVuelo, float km);

/** \brief Funcion que hace el calculo de la diferencia de los precio de vuelo
 *
 * \param pResultado float* referencia a una direccion de memoria que guardara el resultado
 * \param num1 float valor de precio de uno de los vuelo
 * \param num2 float valor de precio de uno de los vuelo
 * \return int si se corrio completamente sin error la funcion retorna 1 sino 0
 *
 */
int diferenciaPrecio(float* pResultado, float num1, float num2);
