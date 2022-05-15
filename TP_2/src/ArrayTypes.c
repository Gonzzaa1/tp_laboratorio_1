#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayTypes.h"


int searchType(TypePassenger* type, int len, int id, int* pIndex)
{
    int isOk = 0;

    if(type  != NULL && len > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i = 0; i < len; i++)
        {
            if(type[i].id == id)
            {
                *pIndex = 1;
                break;
            }
        }
        isOk = 1;
    }
    return isOk;
}

int printType(TypePassenger* type, int len)
{
    int isOk = 0;

    if(type  != NULL && len > 0)
    {
        printf("\n*** List of passenger types ***\n");
        printf("-----------------------------------\n");
        printf("  id        description\n");
        printf("-----------------------------------\n");

        for(int i = 0; i < len; i++)
        {
            printf(" %4d      %10s\n", type[i].id, type[i].description);
        }
        isOk = 1;
    }
    return isOk;
}

int loadTypeDescription(TypePassenger* type, int len, int id, char description[])
{
    int isOk = 0;

    if(type  != NULL && len > 0 && description != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            if(type[i].id == id)
            {
                strcpy(description, type[i].description);
                isOk = 1;
                break;
            }
        }
    }
    return isOk;
}

int valideType(TypePassenger* type, int len, int id)
{
    int isOk = 0;
    int index;

    if(searchType(type, len, id, &index))
    {
        if(index != -1)
        {
            isOk = 1;
        }
    }
    return isOk;
}
int chooseType(int* id)
{
	int index;
	int typeID;
	int isOk = -1;

	if(id != NULL)
	{
		TypePassenger types[4] =
			{
				{5000, "First Class"},
				{5001, "Business Class"},
				{5002, "Premium Class"},
				{5003, "Economy Class"}
			};
		printType(types, 4);

		printf("\nIngrese id: \n");
		scanf("%d", &typeID);

		searchType(types, 4, typeID, &index);

		if(index == -1)
		{
			printf("\nNo existe un pasajero con ID: %d en el sistema\n", typeID);
		}
		else
		{
			*id = typeID;
		}
		isOk = 0;
	}
	return isOk;
}
