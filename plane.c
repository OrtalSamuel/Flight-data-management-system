#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Plane.h"
#include "Airport.h"
#include "utils.h"


const char* typeTilte[eNofTypes] = { "Passengers", "Charger", "military"};


void getplaneType(Plane* plane)
{
	int i,temp;
	printf("Enter plane type\n");
	do {
		for (i = 0; i < eNofTypes; i++)
		{
			printf("Enter %d for %s\n", i, typeTilte[i]);
		}
		scanf("%d", &temp);
		if (temp<0 || temp>eNofTypes)
		{
			printf("Wrong input try again\n");
		}
	} while (temp < 0 || temp >= eNofTypes);
	plane->theType= (Type)temp;
}
void printPlane(const Plane * plane)
{
	printf("Plane : %s ,Code: %s\n", typeTilte[plane->theType], plane->code);
}
void freePlane(Plane * plane)
{
	free(plane->code);
}

void initplaneCode(Plane* plane)
{
	int ok=0;
	do {
		printf("Please enter the Plane's CODE: ");
		printf("Make sure it is ONLY 4 letters and UPPER CASE \n");
		scanf("%s", plane->code);
		ok= checkCODE(plane->code);
		if (!ok)
		{
			printf("Wrong input, try again\n");
		}
	} while (!ok);
}
int initPlane(Plane* plane)
{

	plane->code = (char*)malloc(PLANE_CODE_LENGTH * sizeof(char));

	if (plane->code != NULL)
	{
		initplaneCode(plane);
		getplaneType(plane);
		return 1;
	}
	return 0;
}
