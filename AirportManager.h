#ifndef AIRPORTMANAGER_H
#define AIRPORTMANAGER_H

#include "Airport.h"

typedef struct
{
	Airport* allAirports;
	int numOfAirports;

}AirportManager;

//must:
int initAirportManager(AirportManager* airportManager);//�� ���� ���� �� ���� �����
int initAllAirports(AirportManager* airportManager);
void printAirportManager(const AirportManager* airportManager);
void freeAirportManager(AirportManager* airportManager);

//extra:
int addAirport(Airport * airport, AirportManager* airportManager);//���� ��� ����� ������ ���� ����� ���� ������
Airport* findAirportByName(char* name, AirportManager* airportManager);

#endif // !AIRPORTMANAGER_H
