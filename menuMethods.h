#ifndef MENUMETHODS_H_
#define MENUMETHODS_H_

#include "AirportManager.h"
#include "Airline.h"

int addFlightToAirline(Airline* airlineCompany, AirportManager* manager);
int addAirportToAirportManager(AirportManager* airportManager, Airline* airline);
void printAirlineDetalis(Airline* airline);
void printAirportManagerDetails(AirportManager* airportManager);
void PrintTheNumberOfFlightsFromSpecificDestination(Airline* airline,AirportManager* airportManager);
void PrintAllExistingFlightsWithAspecificPlaneCode(Airline* airline);
void PrintAllExistingFlightsWithAspecificPlaneType(Airline * airline);
void freeAllMemory(AirportManager* airportManager, Airline* airline);

#endif