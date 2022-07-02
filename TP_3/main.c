#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "Menus.h"
#include "MyFunction.h"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    setbuf(stdout,NULL);


    char salirOk = 'n';
    int flagText = 0;
    int flagBin = 0;
    int flagChange = 0;
    int ID=1001;

    LinkedList* listaPasajeros = ll_newLinkedList();


    if(listaPasajeros == NULL)
	{
		printf("No se pudo conseguir memoria.\n");
		exit(1);
	}
    if(!controller_loadNextID("IDs.bin", &ID))
	{
    	exit(1);
	}


    do{
    	system("cls");

        switch(menuOpciones())
        {
        	case 11:
        		printf("%d",ll_len(listaPasajeros));
        	break;
            case 1:
            	if(!flagText)
            	{
            		if(!controller_loadFromText("data.csv", listaPasajeros))
            		{
            			printf("NO SE PUDO LEER EL ARCHIVO\n");
            		}
            		else
            		{
            			flagText = 1;
            			flagChange = 1;
            		}
            	}
            	else
            	{
            		printf("ARCHIVO YA CARGADO\n");
            	}
            	system("pause");
                break;
            case 2:
            	if(!flagBin)
				{
					if(!controller_loadFromBinary("data.bin", listaPasajeros))
					{
						printf("NO SE PUDO LEER EL ARCHIVO\n");
					}
					else
					{
						flagBin = 1;
						flagChange = 1;
					}
				}
				else
				{
					printf("ARCHIVO YA CARGADO\n");
				}
            	system("pause");
            	break;
            case 3:
            	flagChange = 1;
            	controller_addPassenger(listaPasajeros, &ID);
            	system("pause");
            	break;
            case 4:
            	flagChange = 1;
            	controller_editPassenger(listaPasajeros);
            	system("pause");
            	break;
            case 5:
            	flagChange = 1;
            	controller_removePassenger(listaPasajeros);
				system("pause");
            	break;
            case 6:
            	controller_ListPassenger(listaPasajeros);
            	system("pause");
            	break;
            case 7:
            	controller_sortPassenger(listaPasajeros);
				system("pause");
            	break;
            case 8:
            	flagChange = 0;
            	controller_saveAsText("data.csv", listaPasajeros);
            	break;
            case 9:
            	flagChange = 0;
            	controller_saveAsBinary("data.bin", listaPasajeros);
            	break;
            case 10:
				if(flagChange)
				{
					system("cls");
					printf("Debe guardar los cambios efectuados en un archivo antes de salir.\n");
				}
				else
				{
					salir(&salirOk);

					if(salirOk == 's')
					{
						controller_saveId("IDs.bin", &ID);
						ll_deleteLinkedList(listaPasajeros);
					}
				}
				break;
        }
    }while(salirOk != 's');

    system("pause");
    return 0;
}

