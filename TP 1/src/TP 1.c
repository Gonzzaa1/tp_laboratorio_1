#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "calculos.h"
#include "menu.h"

int main(void) {

	setbuf(stdout,NULL);

	int kilometros;

	    float precioLatam = 0;
	    float precioAerolineas = 0;

	    float aeroTD;
	    float aeroTC;
	    float aeroBTC;
	    float aeroUni;

	    float latamTD;
	    float latamTC;
	    float latamBTC;
	    float latamUni;

	    float difAeroLatam;

	    int flagKm = 0;
	    int flagAero = 0;
	    int flagCalculos = 0;
	    int flagLatam = 0;

	    char salir = 'n';

	    system("color f0");

	    do
	    {
	        switch(menu(kilometros, flagKm, precioAerolineas, precioLatam, flagAero, flagLatam))
	        {
	            case 1:
	                opcion1(&kilometros, &flagKm);
	                break;
	            case 2:
	                opcion2(&precioAerolineas, &precioLatam, &flagAero, &flagLatam);
	                break;
	            case 3:
	                opcion3(&flagCalculos, flagKm, flagLatam, flagAero, kilometros, precioAerolineas, precioLatam, &aeroTD, &aeroTC, &aeroBTC, &aeroUni, &latamTD, &latamTC, &latamBTC, &latamUni, &difAeroLatam);
	                break;
	            case 4:
	                opcion4(flagCalculos, kilometros, precioAerolineas, precioLatam, aeroTD, aeroTC, aeroBTC, aeroUni, latamTD, latamTC, latamBTC, latamUni, difAeroLatam);
	                if(flagCalculos == 1)
	                {
	                    reset(&kilometros, &precioAerolineas, &precioLatam, &flagKm, &flagLatam, &flagAero, &flagCalculos);
	                }
	                break;
	            case 5:
	                opcion5();
	                reset(&kilometros, &precioAerolineas, &precioLatam, &flagKm, &flagLatam, &flagAero, &flagCalculos);
	                break;
	            case 6:
	                salir = 's';
	                break;
	            case 7:
	                system("cls");
	                fflush(stdin);
	                printf("La opcion ingresada no es un numero.\n\n\n");
	                getch();
	                break;
	            default:
	                system("cls");
	                printf("La opcion ingresada es incorrecta.\n\n\n");
	                getch();

	        }
	    }while(salir != 's');

	    system("cls");
	    printf("\n\n\t\tGracias por elegirnos!"
	           "\n\t\t     Vuelva pronto!\n\n\n\n");
	    getch();

	return EXIT_SUCCESS;
}
