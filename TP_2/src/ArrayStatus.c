#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayStatus.h"


int searchStatus(StatusFlight* status, int len, int id, int* pIndex)
{
	int isOk = 0;

	if(status  != NULL && len > 0 && pIndex != NULL)
	{
		*pIndex = -1;
		for(int i = 0; i < len; i++)
		{
			if(status[i].id == id)
			{
				*pIndex = 1;
				break;
			}
		}
		isOk = 1;
	}
	return isOk;
}
int printStatus(StatusFlight* status, int len)
{
	int isOk = 0;

	if(status  != NULL && len > 0)
	{
		printf("\n*** List of status flight ***\n");
		printf("---------------------------------\n");
		printf("  id        description\n");
		printf("---------------------------------\n");

		for(int i = 0; i < len; i++)
		{
			printf("  %4d      %10s\n", status[i].id, status[i].description);
		}
		isOk = 1;
	}
	return isOk;
}
int loadStatusDescription(StatusFlight* status, int len, int id, char description[])
{
	int isOk = 0;

	if(status  != NULL && len > 0 && description != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(status[i].id == id)
			{
				strcpy(description, status[i].description);
				isOk = 1;
				break;
			}
		}
	}
	return isOk;
}
int valideStatus(StatusFlight* status, int len, int id)
{
	int isOk = 0;
	int index;

	if(searchStatus(status, len, id, &index))
	{
		if(index != -1)
		{
			isOk = 1;
		}
	}
	return isOk;
}
