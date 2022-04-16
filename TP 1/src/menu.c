#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menu.h"
#include "calculos.h"

int menu(int Km, int flagKm,float aero, float latam, int flagAero, int flagLatam)
{
    int opciones;
    int noNum;

    system("cls");

    printf("TP1 - Lopez Gonzalo Javier - DIV G\n\n"
           "-----------------------------------------------------------\n"
           "-----------------------------------------------------------"
           "\n    |||||     Bievenidos a Viaja y Ahorra      |||||\n"
           "-----------------------------------------------------------\n"
           "-----------------------------------------------------------\n\n\n"
           "Opciones:\n\n");

    if(flagKm == 0)
    {
        printf("1.Ingresar Kilometros: Km = x\n");
    }
    else
    {
        printf("1.Ingresar Kilometros: Km = %d\n", Km);
    }
    if(flagAero == 0 && flagLatam == 0)
    {
        printf("2.Ingresar Precio de vuelos: Aerolineas = y, Latam = z\n");
    }
    else
    {
        printf("2.Ingresar Precio de vuelos: Aerolineas = $%.2f, Latam = $%.2f\n", aero,latam);
    }
    printf("3.Calcular costos\n"
           "4.Informar Resultados\n"
           "5.Carga forzada de datos\n"
           "6.Salir\n\nElegir una opcion: ");

    noNum = scanf("%d", &opciones);

    if(noNum == 0)
    {
        opciones = 7;
    }

    return opciones;
}
//------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------//
int opcion1(int* pKm, int* pFlag)
{
    int kilometros;
    int respuesta;
    int retorno = -1;

    if(pKm != NULL && pFlag != NULL)
    {
        do
        {
            system("cls");
            printf("Ingrese los kilometros del viaje: ");
            scanf("%d", &kilometros);

            while(kilometros < 1)
            {
                printf("Datos invalidos....\nPor favor Reingrese los kilometros del viaje: ");
                scanf("%d", &kilometros);
            }

            respuesta = confimar();

        }
        while(respuesta != 's');

        system("cls");

        printf("Kilometros cargados\n"
               "\nSe ingresaron: %d Km", kilometros);

        *pKm = kilometros;
        *pFlag = 1;
        getch();
        retorno = 0;
    }
    return retorno;
}
int opcion2(float* pPrecioAero, float* pPrecioLatam, int* pFlag, int* pFlag2)
{
    char respuesta;
    float precioAerolineas;
    float precioLatam;
    char carga;
    int linea;
    int retorno = -1;

    empresa(&linea);
    if(pPrecioAero != NULL && pPrecioLatam != NULL && pFlag != NULL)
    {

        if(linea == 1)
        {
            do
            {
                system("cls");
                printf("Ingrese el valor del vuelo de Aerolineas: ");
                scanf("%f", &precioAerolineas);

                while(precioAerolineas < 1)
                {
                    printf("\nDato Invalido....\n\nPor favor reingrese el valor del vuelo de Aerolineas: ");
                    scanf("%f", &precioAerolineas);
                }

                respuesta = confimar();

            }
            while(respuesta != 's');

            if(*pFlag == 1)
            {
                system("cls");
                carga = sobrescribir();

                if(carga == 's')
                {
                    system("cls");
                    printf("el nuevo monto ingresado es: \n\n"
                           "- Precio Vuelo Aerolineas: $%.2f\n", precioAerolineas);
                    *pPrecioAero = precioAerolineas;
                    getch();

                }
            }
            else
            {
                system("cls");
                printf("Se ingreso el siguiente monto: \n\n"
                        "- Precio Vuelo Aerolineas: $%.2f\n", precioAerolineas);

                *pFlag = 1;
                *pPrecioAero = precioAerolineas;
                getch();
            }
        }
        else if(linea == 2)
        {
             do
            {
                system("cls");
                printf("Ingrese el valor del vuelo de Latam: ");
                scanf("%f", &precioLatam);

                while(precioLatam < 1)
                {
                    printf("\nDato Invalido....\n\nPor favor reingrese el valor del vuelo de Latam: ");
                    scanf("%f", &precioLatam);
                }

                respuesta = confimar();

            }
            while(respuesta != 's');

            if(*pFlag2 == 1)
            {
                system("cls");
                carga = sobrescribir();

                if(carga == 's')
                {
                    system("cls");
                    printf("el nuevo monto ingresado es: \n\n"
                           "- Precio Vuelo Latam: $%.2f\n", precioLatam);
                    *pPrecioLatam = precioLatam;
                    getch();

                }
            }
            else
            {
                system("cls");
                printf("Se ingreso el siguiente monto: \n\n"
                        "- Precio Vuelo Latam: $%.2f\n", precioLatam);

                *pFlag2 = 1;
                *pPrecioLatam = precioLatam;
                getch();
            }
        }
    }

    return retorno;
}
int opcion3(int *pFlag,int flagKm,int flagLatam, int flagAero,int km, float precioAero, float precioLatam,float* pAeroTD,float* pAeroTC,float* pAeroBTC,float* pAeroUni,float* pLatamTD,float* pLatamTC,float* pLatamBTC,float* pLatamUni,float* pDif)
{
    float precioAeroTD;
    float precioAeroTC;
    float precioAeroBTC;
    float precioAeroUni;

    float precioLatamTD;
    float precioLatamTC;
    float precioLatamBTC;
    float precioLatamUni;

    float difAeroLatam;

    int retorno;

    if(pFlag != NULL && pAeroTD != NULL && pAeroTC!= NULL && pAeroBTC!= NULL && pAeroUni!= NULL && pLatamTD!= NULL && pLatamTC!= NULL && pLatamBTC!= NULL && pLatamUni!= NULL && pDif!= NULL)
    {
        system("cls");
        printf("Calculando.....\n...\n...\n...\n");

        if(flagKm == 0 && flagAero == 0 && flagLatam ==0)
        {
            printf("Verificando....\n....\n...\n"
                   "Error....\n...\n...\n"
                   "No se puede realizar los calculos sin los kilometros y precio de los vuelos......\n\n\n");
        }
        else if(flagKm == 0)
        {
            printf("Verificando....\n....\n...\n"
                   "Error....\n...\n...\n"
                   "No se puede realizar el calculo sin los kilometros......\n\n\n");
        }
        else if(flagKm == 0 && flagAero == 0)
        {
            printf("Verificando....\n....\n...\n"
                   "Error....\n...\n...\n"
                   "No se puede realizar los calculos sin los kilometros y el precio de Aerolineas......\n\n\n");
        }
        else if(flagKm == 0 && flagLatam)
        {
            printf("Verificando....\n....\n...\n"
                   "Error....\n...\n...\n"
                   "No se puede realizar los calculos sin los kilometros y el precio de Latam......\n\n\n");
        }
        else if(flagAero == 0 && flagLatam ==0)
        {
            printf("Verificando....\n....\n...\n"
                   "Error....\n...\n...\n"
                   "No se puede realizar los calculos sin los precios de los Vuelos......\n\n\n");
        }
         else if(flagLatam == 0 )
        {
            printf("Verificando....\n....\n...\n"
                   "Error....\n...\n...\n"
                   "No se puede realizar los calculos sin el precio de Latam......\n\n\n");
        }
         else if(flagAero == 0)
        {
            printf("Verificando....\n....\n...\n"
                   "Error....\n...\n...\n"
                   "No se puede realizar los calculos sin el precio de Aerolineas......\n\n\n");
        }
        else
        {
            printf("Verificando Resultados......");

            debitCard(&precioAeroTD,precioAero);
            creditCard(&precioAeroTC, precioAero);
            calcularBtc(&precioAeroBTC, precioAero);
            precioUnitario(&precioAeroUni, precioAero, km);

            debitCard(&precioLatamTD, precioLatam);
            creditCard(&precioLatamTC, precioLatam);
            calcularBtc(&precioLatamBTC, precioLatam);
            precioUnitario(&precioLatamUni, precioLatam, km);

            diferenciaPrecio(&difAeroLatam, precioLatam, precioAero);

            *pAeroTD = precioAeroTD;
            *pAeroTC = precioAeroTC;
            *pAeroBTC = precioAeroBTC;
            *pAeroUni = precioAeroUni;

            *pLatamTD = precioLatamTD;
            *pLatamTC = precioLatamTC;
            *pLatamBTC = precioLatamBTC;
            *pLatamUni = precioLatamUni;

            *pDif = difAeroLatam;

            printf("\n...\n...\n...\nCalculos completados!\n");
            *pFlag = 1;
        }
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }

    getch();

    return retorno;
}
int opcion4(int flagCalculos,int km, float precioAero, float precioLatam,float aeroTD,float aeroTC,float aeroBTC,float aeroUni,float latamTD,float latamTC,float latamBTC,float latamUni,float dif)
{
    int retorno;

    if(flagCalculos != 0)
    {
        system("cls");

        printf("KMs Ingresados: %d km\n", km);

        printf("\nPrecio Aerolineas: $%.2f\n\n", precioAero);
        printf("a)Precio con tarjeta de debito: $ %.2f\n", aeroTD);
        printf("b)Precio con tarjeta de credito: $ %.2f\n", aeroTC);
        printf("c)Precio pagando con bitcoin: %f BTC\n", aeroBTC);
        printf("d)Precio unitario: $ %.2f\n", aeroUni);

        printf("\nLatam: $%.2f\n\n", precioLatam);
        printf("a)Precio con tarjeta de debito: $ %.2f\n", latamTD);
        printf("b)Precio con tarjeta de credito: $ %.2f\n", latamTC);
        printf("c)Precio pagando con bitcoin: %f BTC\n", latamBTC);
        printf("d)Precio unitario: $ %.2f\n", latamUni);

        printf("\n\nLa diferecia de precio es: $ %.2f\n\n\n", dif);
        getch();
        retorno = 1;
    }
    else
    {
        system("cls");
        printf("\nNo se realizaron los calculos todavia");
        retorno = 0;
        getch();
    }

    return retorno;
}
void opcion5()
{
    float aeroTD;
    float aeroTC;
    float aeroBTC;
    float aeroUni;

    float latamTD;
    float latamTC;
    float latamBTC;
    float latamUni;

    float difAeroLatam;

    system("cls");

    debitCard(&aeroTD, 162965);
    creditCard(&aeroTC, 162965);
    calcularBtc(&aeroBTC, 162965);
    precioUnitario(&aeroUni, 162965, 7090);

    debitCard(&latamTD, 159339);
    creditCard(&latamTC, 159339);
    calcularBtc(&latamBTC, 159339);
    precioUnitario(&latamUni, 159339, 7090);

    diferenciaPrecio(&difAeroLatam, 162965, 159339 );

    printf("KMs Ingresados: %d km\n", 7090);

    printf("\nPrecio Aerolineas: $%d\n", 162965);
    printf("a)Precio con tarjeta de debito: $ %.2f\n", aeroTD);
    printf("b)Precio con tarjeta de credito: $ %.2f\n", aeroTC);
    printf("c)Precio pagando con bitcoin: %f BTC\n", aeroBTC);
    printf("d)Precio unitario: $ %.2f\n", aeroUni);

    printf("\nPrecio Latam: $%d\n", 159339);
    printf("a)Precio con tarjeta de debito: $ %.2f\n", latamTD);
    printf("b)Precio con tarjeta de credito: $ %.2f\n", latamTC);
    printf("c)Precio pagando con bitcoin: %f BTC\n", latamBTC);
    printf("d)Precio unitario: $ %.2f\n", latamUni);

    printf("\nLa diferecia de precio es: $ %.2f\n\n\n", difAeroLatam);

    getch();
}
//------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------//
char confimar()
{
    char respuesta;

    system("cls");
    printf("Desea confirmar la cargar? s/n : ");
    fflush(stdin);
    scanf("%c", &respuesta);

    return respuesta;
}
int empresa(int* pEmpresa)
{
    int empresa;
    int retorno = 0;
    if(pEmpresa != NULL)
    {
        system("cls");
        printf("Que empreza desea cargar?:\n\n"
               "1) Aerolineas\n2) Latam\n"
               "Elegir una opcion: ");
        scanf("%d", &empresa);
    }
    retorno = 1;
    *pEmpresa = empresa;

    return retorno;
}
char sobrescribir()
{
    char respuesta;

    system("cls");
    printf("Ya hay un precio cargado\nDesea sobrescribirlo? s/n : ");
    fflush(stdin);
    scanf("%c", &respuesta);


    return respuesta;

}
void reset(int* pKm, float* pPreciaA, float* pPrecioL, int* pFlagKm,int* pFlagLatam, int* pFlagAero, int* pFlagCalculos)
{
    *pKm = 0;
    *pPreciaA = 0;
    *pPrecioL = 0;
    *pFlagKm = 0;
    *pFlagLatam = 0;
    *pFlagAero = 0;
    *pFlagCalculos = 0;
}
