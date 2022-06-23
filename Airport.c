#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Airport.h"
#include "utils.h"
#include "Address.h"


int initAirport(Airport* airport)
{
	airport->name = (char*)malloc(MAX_NAME * sizeof(char));
	airport->adress = (char*)malloc(MAX_NAME * sizeof(char));
	printf("Please enter the Airport's name\n");
	getchar();
	myGets(airport->name, MAX_NAME);
	initAirportAddres(airport->adress);

	if (airport->name != NULL && airport->adress != NULL)
	{
		return 1;
	}
	return 0;
}

void printAirport(const Airport* airport)
{
	printf("Airport: %s \n ", airport->name);
	printf("Airport address is: %s\n", airport->adress);
}
void freeAirport(Airport* airport)
{
	free(airport->name);
	free(airport->adress);
}

int isSameAirport(const Airport* airport1, const Airport* airport2)
{
	int same;
	same = strcmp(airport1-> name ,airport2-> name);
	if(same == 0)
	{
		return 1;
	}
	return 0;
}
int isAirportName(const Airport* airport, char name[MAX_NAME])
{
	int same;
	same = strcmp(airport->name, name);
	if (same == 0)
	{
		return 1;
	}
	return 0;
}
