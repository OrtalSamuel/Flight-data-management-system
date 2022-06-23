#include <stdio.h>
#include <stdlib.h>
#include "Airline.h"
#include "Flight.h"
#include "utils.h"
#include "Plane.h"


void initAirline(Airline* airline)
{
	airline->name = (char*)malloc(MAX_NAME * sizeof(char));
	if (airline->name != NULL)
	{
		printf("please enter the name of Airline\n");
		getchar();
		myGets(airline->name, MAX_NAME);
	}
	airline->numOfFlights = 0;
}
void printAirline(const Airline* airline)
{
	printf("Airline: name= %s , number of flights= %d \n", airline->name, airline->numOfFlights);
	if (airline->numOfFlights != 0)
	{
		printf("The flights in this airline are:\n");
		for (int i = 0; i < airline->numOfFlights; i++)
			printFlight(&(airline->allFlights[i]));

	}
	printf("\n");
}
void freeAirline(Airline* airline)
{
	if (airline->numOfFlights > 0)
	{
		free(airline->allFlights);
	}
	free(airline->name);
}

int addFlight(Flight* flight, Airline* airline)
{
	if (airline->numOfFlights == 0)
	{
		airline->allFlights = (Flight*)malloc(MAX_NAME * sizeof(Flight));
	}
	else
	{
		airline->allFlights = (Flight*)realloc(airline->allFlights, (airline->numOfFlights + 1)* sizeof(Flight));
	}
	if (airline->allFlights != NULL)
	{
		airline->numOfFlights++;
		airline->allFlights[airline->numOfFlights - 1] = *flight;
		return 1;
	}
	return 0;
}

void doPrintFlightsWithPlaneCode(char code[PLANE_CODE_LENGTH], Airline* airline)
{
	int i;
	if (airline->numOfFlights == 0)
	{
		printf("No flights \n");
	}
	for (i = 0; i < airline->numOfFlights; i++)
	{
		if (checkNameSame(airline->allFlights[i].plane.code, code))
		{
			printFlight(&(airline->allFlights[i]));
		}
	}
}

void doPrintFlightsWithPlaneType(Type theType, Airline* airline)
{
	int counter = 0;
	int i;
	if (airline->numOfFlights == 0)
	{
		printf("No flights in airline %s\n", airline->name);
	}
	for ( i = 0; i < airline->numOfFlights; i++)
	{
		if (airline->allFlights->plane.theType == theType)
		{
			printFlight(&(airline->allFlights[i]));
			counter++;
		}
	}
	if (counter == 0)
	{
		printf("No flights with type %s found\n", typeTilte[theType]);
	}
}



int doCountFlightsFromName(char* airportName, Airline * airline)
{
	int counter = 0;
	int i;
	if (airline->numOfFlights == 0)
	{
		printf("No flights \n");
	}
	for (i = 0; i < airline->numOfFlights; i++)
	{
		if (checkNameSame(airportName, airline->allFlights->SourceName))
		{
			counter++;
		}
	}
	return counter;
}
