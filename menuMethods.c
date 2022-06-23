#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "menuMethods.h"
#include "Airport.h"
#include "AirportManager.h"
#include "Airline.h"
#include "utils.h"
#include "Plane.h"

int addFlightToAirline(Airline* airline, AirportManager* airportManager)
{
	Flight* flight;
	flight = (Flight*)malloc(1 * sizeof(Flight));
	getchar();
	int okflight = initFlight(flight, airportManager);
	if(okflight)
	{
		int ok = addFlight(flight, airline);
		if (!ok)
			free(flight);
		return ok;
	}
	return 0;
}

int addAirportToAirportManager(AirportManager* airportManager, Airline* airline)
{
	Airport* airport;
	airport = (Airport*)malloc(1 * sizeof(Airport));
	int okairport = initAirport(airport);
	if (okairport)
	{
		for (int i = 0; i < airportManager->numOfAirports; i++)
		{
			if (isSameAirport(airport, &(airportManager->allAirports[i])) == 1)
			{
				return 0;
			}
		}
		int ok = addAirport(airport, airportManager);
		if (!ok)
		{
			free(airport);
			return ok;
		}
	}
		return -1;
}
void printAirlineDetalis(Airline* airline)
{
	printAirline(airline);
}
void printAirportManagerDetails(AirportManager* airportManager)
{
	printAirportManager(airportManager);
}
void PrintTheNumberOfFlightsFromSpecificDestination(Airline* airline, AirportManager* airportManager)
{
	int num;
	char* SourceName;
	SourceName = (char*)malloc(MAX_NAME * sizeof(char));
	printf("please enter the name of source airport\n");
	getchar();
	myGets(SourceName, MAX_NAME);

	for (int i = 0; i < airportManager->numOfAirports; i++)
	{
		if (checkNameSame(SourceName, airportManager->allAirports[i].name) == 1)
		{
			num = doCountFlightsFromName(SourceName, airline);
			printf("The number of flights from this destination is:%d\n", num);
			free(SourceName);
			return;
		}
	}
	printf("this Source Name not exists\n");
	free(SourceName);
}

void PrintAllExistingFlightsWithAspecificPlaneCode(Airline * airline)
{
	int ok;
	char* code;

	do{
	code = (char*)malloc(PLANE_CODE_LENGTH * sizeof(char));
	printf("Please enter the Plane's CODE: ");
	printf("Make sure it is ONLY 4 letters and UPPER CASE \n");
	scanf("%s", code);
	ok = checkCODE(code);
	if (!ok)
	{
		printf("Wrong input, try again\n");
	}
	} while (!ok);
	for (int i = 0; i < airline->numOfFlights; i++)
	{
		if (checkNameSame(code, airline->allFlights[i].plane.code) == 1)
		{
			doPrintFlightsWithPlaneCode(code, airline);
			return;
		}
	}
	printf("this code not exists\n");
}
void PrintAllExistingFlightsWithAspecificPlaneType(Airline * airline)
{
	Type type;
	int i, temp;
	printf("Enter plane type\n");
	do {
		for (i = 0; i < eNofTypes; i++)
		{
			printf("Enter %d for %s\n", i, typeTilte[i]);
		}
		scanf("%d", &temp);
		if (temp < 0 || temp >= eNofTypes)
		{
			printf("ERROR: plane type value for %d does not exist\n", temp);
		}
	} while (temp < 0 || temp >= eNofTypes);
	type = (Type)temp;
	doPrintFlightsWithPlaneType(type, airline);

}
void freeAllMemory(AirportManager* airportManager, Airline* airline)
{
	freeAirline(airline);
	freeAirportManager(airportManager);
}
