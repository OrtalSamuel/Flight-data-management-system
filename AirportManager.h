#ifndef AIRPORTMANAGER_H
#define AIRPORTMANAGER_H

#include "Airport.h"

typedef struct
{
	Airport* allAirports;
	int numOfAirports;

}AirportManager;

//must:
int initAirportManager(AirportManager* airportManager);//לא מקבל מערך של שדות תעופה
int initAllAirports(AirportManager* airportManager);
void printAirportManager(const AirportManager* airportManager);
void freeAirportManager(AirportManager* airportManager);

//extra:
int addAirport(Airport * airport, AirportManager* airportManager);//נקבל שדה תעופה ונוסיף אותו למערך שדות התעופה
Airport* findAirportByName(char* name, AirportManager* airportManager);

#endif // !AIRPORTMANAGER_H
