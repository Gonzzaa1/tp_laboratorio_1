#include <stdio.h>
#include "calculos.h"
#include "menu.h"

int debitCard(float *pResultado, float precioVuelo)
{
    int retorno = 0;
    int porcentaje = 10;
    float descuento;
    float resultado;

    if(pResultado != NULL)
    {
        descuento = precioVuelo * porcentaje / 100;
        resultado = precioVuelo - descuento;
        *pResultado = resultado;
        retorno = 1;
    }

    return retorno ;
}
int creditCard(float *pResultado, float precioVuelo)
{
    int retorno = 0;
    int porcentaje = 25;
    float interes;
    float resultado;

    if(pResultado != NULL)
    {
        interes = precioVuelo * porcentaje / 100;
        resultado = precioVuelo + interes;
        *pResultado = resultado;
        retorno = 1;
    }

    return retorno ;
}
int calcularBtc(float *pResultado, float precioVuelo)
{
    int retorno = 0;
    float btc = 4606954.55;
    float resultado;

    if(pResultado != NULL)
    {
        resultado = precioVuelo / btc;
        *pResultado = resultado;
        retorno = 1;
    }

    return retorno ;
}
int precioUnitario(float *pResultado, float precioVuelo, float km)
{
    int retorno = 0;
    float resultado;

    if(pResultado != NULL)
    {
        resultado = precioVuelo / km;
        *pResultado = resultado;
        retorno = 1;
    }

    return retorno ;
}
int diferenciaPrecio(float *pResultado, float num1, float num2)
{
    int retorno = 0;
    float resultado;

    if(pResultado != NULL)
    {
        if(num1 > num2)
        {
            resultado = num1 - num2;
        }
        else
        {
            resultado = num2 - num1;
        }
        *pResultado = resultado;
        retorno = 1;
    }

    return retorno ;
}
