#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Address.h"
#include "Airport.h"
#include "utils.h"


//must:

void initAirportAddres(char* pAdd)
{
	Address address = { (char*)malloc(MAX_NAME * sizeof(char)) ,(char*)malloc(MAX_NAME * sizeof(char)) ,(char*)malloc(MAX_NAME * sizeof(char)) ,0 };
	address.country = (char*)malloc(MAX_NAME * sizeof(char));
	address.town = (char*)malloc(MAX_NAME * sizeof(char));
	address.street = (char*)malloc(MAX_NAME * sizeof(char));
	printf("Please enter the Airport's country\n");
	myGets(address.country, MAX_NAME);
	validateInput(address.country);
	printf("Please enter the Airport's town\n");
	myGets(address.town, MAX_NAME);
	validateInput(address.town);
	printf("Please enter the Airport's street\n");
	myGets(address.street, MAX_NAME);
	validateInput(address.street);
	printf("Please enter the house number\n");
	scanf("%d", &(address.numberOfHome));
	strcpy(pAdd, addressToString(&address));
	freeAddress(&address);
}

void validateInput(char* str) {
	checkSpacesFirst(str);//4
	checkSpacesLast(str);//4
	addedCharBetweenTwoWords(str);//2
	capitalLetters(str);//3
	bigSmallLetters(str);//5
}

void printAddress(const Address* address)
{
	printf("The address is: %s\n", addressToString(address));
}

char* addressToString(const Address* address)
{
	char numberOfHomeAsString[8];
	snprintf(numberOfHomeAsString, 8, "%d", address->numberOfHome);
	char* newAdressAsString = (char*)malloc((strlen(address->country) + strlen(address->town) + strlen(address->street) + strlen(numberOfHomeAsString) + 4) * sizeof(char));
	strcpy(newAdressAsString, address->country);
	strcat(newAdressAsString, "@");
	strcat(newAdressAsString, address->town);
	strcat(newAdressAsString, "@");
	strcat(newAdressAsString, address->street);
	strcat(newAdressAsString, "@");
	strcat(newAdressAsString, numberOfHomeAsString);
	newAdressAsString[strlen(newAdressAsString)] = '\0';
	return newAdressAsString;
}

void freeAddress(Address * address)
{
	free(address->country);
	free(address->street);
	free(address->town);
}
