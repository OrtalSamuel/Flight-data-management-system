#ifndef AIRPORT_H
#define AIRPORT_H
#define MAX_NAME 255
#include "Address.h"

typedef struct
{
	char* name;
	char* adress;

} Airport;

//musts:

int initAirport(Airport* airport);
void printAirport(const Airport* airport);
void freeAirport(Airport* airport);

//extra:
int isSameAirport(const Airport* airport1, const Airport* airport2);
int isAirportName(const Airport* airport, char name[MAX_NAME]);

#endif // !AIRPORT_H

