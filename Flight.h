#ifndef FLIGHT_H
#define FLIGHT_H

#include "Airport.h"
#include "AirportManager.h"
#include "Plane.h"
#include "Date.h"


typedef struct
{
	char* SourceName;
	char* DestName;
	Plane plane;
	Date date;
}Flight;


//must:
int initFlight(Flight* flight, AirportManager* airportManager);
void initFlightAirports(Flight* flight, AirportManager* airportManager);
void initName(char* SourceName, char* DestName, AirportManager* airportManager);//check not the same name
void printFlight(const Flight* flight);
void freeFlight(Flight* flight);

//extra:
int isFlightFromSourceName(Flight* flight, char SourceName[MAX_NAME]);
int isFlightToDestName(Flight* flight, char DestName[MAX_NAME]);
int isPlaneCodeInFlight(Flight* flight, char code[PLANE_CODE_LENGTH]);
int isPlaneTypeInFlight(Flight* flight, Type theType);
#endif // !FLIGHT_H