#ifndef AIRLINE_H
#define AIRLINE_H

#include "Flight.h"
#include "Plane.h"

typedef struct
{
	char* name;
	int numOfFlights;
	Flight* allFlights;
}Airline;


//must:
void initAirline(Airline* airline);
void printAirline(const Airline* airline);
void freeAirline(Airline* airline);

//extra:
int addFlight(Flight* flight, Airline* airline);
void doPrintFlightsWithPlaneCode(char code[PLANE_CODE_LENGTH], Airline* airline);
void doPrintFlightsWithPlaneType(Type theType, Airline* airline);
int	 doCountFlightsFromName(char* airportName, Airline* airline);
#endif // !AIRLINE_H