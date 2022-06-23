#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Flight.h"
#include "Airport.h"
#include "utils.h"
#include "AirportManager.h"
#include "Date.h"
#include "Plane.h"


void initName(char* SourceName, char* DestName, AirportManager* airportManager)
{
	Airport* temp;
	int same;
	do {
		do {
			printf("please enter the name of origin airport\n");
			myGets(SourceName, MAX_NAME); 
			temp = findAirportByName(SourceName, airportManager);
			if (temp == NULL) {
				printf("ERROR: Airport %s does not exist\n", SourceName);
			}
		} while (temp == NULL);
		do {
			printf("please enter the name of destination airport\nMake sure it is not the same airport as origin\n");
			myGets(DestName, MAX_NAME);
			temp = findAirportByName(DestName, airportManager);
			if (temp == NULL) {
				printf("ERROR: Airport %s does not exist\n", DestName);
			}
		} while (temp == NULL);
		same = checkNameSame(SourceName, DestName);
		if (same)
		{
			printf("Same airports, try again\n");
		}
	} while (same);
}
void initFlightAirports(Flight* flight, AirportManager* airportManager)
{
	initName(flight->SourceName, flight->DestName, airportManager);
}

int initFlight(Flight* flight, AirportManager* airportManager)
{
	flight->SourceName = (char*)malloc(MAX_NAME * sizeof(char));
	flight->DestName = (char*)malloc(MAX_NAME * sizeof(char));

	if (flight->SourceName != NULL && flight->DestName != NULL)
	{
		initFlightAirports(flight, airportManager);//added the Source Name Airport and the Dest Name Airport
		initPlane(&(flight->plane));
		initDate(&(flight->date));
		return 1;
	}
	return 0;
}


void printFlight(const Flight* flight)
{
	printf("Flight taking off from %s ",flight->SourceName);
	printf("to %s \n", flight->DestName);
	printPlane(&(flight->plane));
	printDate(&(flight->date));
	printf("\n");

}
void freeFlight(Flight* flight)
{
	free(flight->DestName);
	free(flight->SourceName);
}


int isFlightFromSourceName(Flight * flight, char SourceName[MAX_NAME])
{
	return checkNameSame(flight->SourceName, SourceName);
}

int isFlightToDestName(Flight * flight, char DestName[MAX_NAME])
{
	return checkNameSame(flight->DestName, DestName);
}

int isPlaneCodeInFlight(Flight * flight, char code[PLANE_CODE_LENGTH])
{
	//if the strings are equal
	return checkNameSame(flight->plane.code, code);
}

int isPlaneTypeInFlight(Flight * flight, Type theType)
{
	if (flight->plane.theType == theType)
	{
		theType = eNofTypes;
		return 1;
	}
	return 0;
}
