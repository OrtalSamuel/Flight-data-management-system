#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AirportManager.h"
#include "Airport.h"

int initAllAirports(AirportManager* airportManager)
{
	int ok = 0;
	airportManager->allAirports = (Airport*)malloc(airportManager->numOfAirports * sizeof(Airport));
	if (airportManager->allAirports != NULL)
	{
		for (int i = 0; i < airportManager->numOfAirports; i++)
		{
			printf("Airport %d\n", i + 1);
			ok = initAirport(&(airportManager->allAirports[i]));
			if (!ok)
			{
				return 0;
			}
		}
	}
	return 1;
}

int initAirportManager(AirportManager* airportManager)
{
	int ok;
	do {
		printf("Please enter the number of airports \n");
		scanf("%d", &(airportManager->numOfAirports));
		if (airportManager->numOfAirports < 0)
		{
			printf("wrong input try again \n");
		}
	} while (airportManager->numOfAirports < 0);
	ok = initAllAirports(airportManager);
	return ok;
}

void printAirportManager(const AirportManager* airportManager)
{
	printf("Number of airports in managment= %d\n", airportManager->numOfAirports);
	if (airportManager->numOfAirports != 0)
	{
		for (int i = 0; i < airportManager->numOfAirports; i++)
		{
			printAirport(&(airportManager->allAirports[i]));
		}
		printf("\n");
	}
}
void freeAirportManager(AirportManager* airportManager)
{
	for (int i = 0; i < airportManager->numOfAirports; i++)
	{
		freeAirport(&(airportManager->allAirports[i]));
	}
	free(airportManager->allAirports);

}
int addAirport(Airport* airport, AirportManager* airportManager)
{
	airportManager->allAirports = (Airport*)realloc(airportManager->allAirports, (airportManager->numOfAirports + 1) * sizeof(Airport));
	if (airportManager->allAirports != NULL)
	{
		airportManager->numOfAirports++;
		airportManager->allAirports[(airportManager->numOfAirports)-1] = *airport;
		return 1;
	}
	return 0;
}
Airport* findAirportByName(char* name, AirportManager* airportManager)
{
	int compare = 0;
	if (airportManager->allAirports != NULL)
	{
		for (int i = 0; i < airportManager->numOfAirports; i++)
		{
			compare = strcmp(airportManager->allAirports[i].name, name);
				if (compare == 0)
				{
					return &(airportManager->allAirports[i]);
				}
		}		
	}
	return NULL;
}