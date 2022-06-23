#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "AirportManager.h"
#include "Airline.h"
#include "Flight.h"
#include "utils.h"
#include "menuMethods.h"

int programStart(AirportManager* manaeger, Airline* airlineCompany)
{
	printf("Hello and welcome to the flights program\n");
	printf("We start by entering Airport Manager and Airline.\n");
	printf("\n");


	int ok = initAirportManager(manaeger);
	initAirline(airlineCompany);
	if (ok)
	{
		printf("airport manager and airline added succesfully\n");
		printf("\n");
		return 1;
	}
	else
	{
		printf("problem starting program\n");
		return 0;
	}
}
int main()
{
	AirportManager* manager;
	Airline* airlineCompany;

	manager = (AirportManager*)malloc(1 * sizeof(AirportManager));
	airlineCompany = (Airline*)malloc(1 * sizeof(Airline));
	if (manager == NULL || airlineCompany == NULL) {
		printf("Could not allocate memory for manager or airline company.\nProgram will exit.");
		return 0;
	}
	int choise = 0;
	int ok1;
	int ok2;
	int start = programStart(manager, airlineCompany);

	if (start)
	{
		do {
			printMenu();
			scanf("%d", &choise);
			switch (choise) {
			case 1:
				if (manager->numOfAirports <= 0 || manager->numOfAirports == 1)
				{
					printf("There are not enough airport to set a flight Error adding flight \n");
					break;
				}

				ok1 = addFlightToAirline(airlineCompany, manager);
				if (!ok1)
					printf("Can't add this flight \n");
				else
					printf("flight added successfully\n");
				break;
			case 2:
				ok2 = addAirportToAirportManager(manager, airlineCompany);
				if (ok2 == 0)
				{
					printf("Can't add this airport since it already exists\n");
				}
				else if (ok2 == 1)
				{
					printf("Can't add this airport , out of memory\n");
				}
				else
					printf("Airport added successfully\n");
				break;
			case 3:
				printAirlineDetalis(airlineCompany);
				break;
			case 4:
				printAirportManager(manager);
				break;
			case 5:
				PrintTheNumberOfFlightsFromSpecificDestination(airlineCompany, manager);
				break;
			case 6:
				PrintAllExistingFlightsWithAspecificPlaneCode(airlineCompany);
				break;
			case 7:
				PrintAllExistingFlightsWithAspecificPlaneType(airlineCompany);
				break;
			case 8:
				freeAllMemory(manager, airlineCompany);
				printf("You chose to exit. Have a good day, bye! \n");
				break;
			default:
				printf("pressed a wrong key. Try again.\n");
				break;
			}

		} while (choise != 8);
	}
}