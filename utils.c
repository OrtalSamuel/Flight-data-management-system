#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include "Plane.h"


char* myGets(char* buf, size_t size)
{
	if (buf != NULL && size > 0)
	{
		if (fgets(buf, size, stdin))
		{
			buf[strcspn(buf, "\n")] = '\0';
			return buf;
		}
		*buf = '\0';
	}
	return NULL;
}
void addedCharBetweenTwoWords(char* str)//2
{
	char* pLook = str;
	while (*pLook)
	{
		if (*pLook == ' ')
		{
			*pLook = '#';			
		}
		pLook++;
	}
}
void capitalLetters(char* str)//3
{
	char* pLook = str;
	int foundTable = 0;
	int i;
	//New#YoRk#cITY
	for (i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] == '#') {
			if (foundTable == 0) {
				foundTable = 1;
			}
			else {
				str[i + 1] = toupper(str[i + 1]);
			}
		}
	}    
	if (foundTable != 0)
	{
		str[0] = toupper(str[0]);
	}
}
void checkSpacesFirst(char* str)//4
{
	char* pLook = str;
	char* pWrite = str;

	if (*pLook == ' ')//if there is a space at the first of the word
	{
		do {
			pLook++;
		} while (*pLook == ' ');	
		while (*pLook)
		{
			*pWrite = *pLook;
			pLook++;
			pWrite++;
		}
	}
	*pWrite = *pLook;
}
void checkSpacesLast(char* str)//4
{
	int lastChar = strlen(str) - 1;
	while (str[lastChar] == ' ') {
		lastChar--;
	}
	*(str + lastChar + 1) = '\0';
	
}

void bigSmallLetters(char* str) //5
{
	int counter = 0;
	int foundTable = 0;
	int i;
	char* pLook = str;
	char* pWord;
	while (*pLook)
	{
		if (*pLook == '#')
		{
			foundTable = 1;
			break;
		}
		pLook++;
	}
	if (foundTable == 0)
	{
		return;
	}
	pLook = str;
	while (*pLook)
	{
		//New#York
		do {
			counter++;
			pLook++;
		} while (*pLook != '#' && *pLook);
		if (counter % 2 == 0) {
			pWord = pLook - 1;
			for (i = 0; i < counter; i++) {
				if (i % 2 == 0) {
					*pWord = tolower(*pWord);
				}
				else {
					*pWord = toupper(*pWord);
				}
				pWord--;
			}
		}
		counter = 0;
		pLook++;
	}
}

int checkCODE(char* code)
{
	if (strlen(code) != PLANE_CODE_LENGTH)
	{
		return 0;
	}
		
	for (int i = 0; i < PLANE_CODE_LENGTH; i++)
	{
		if (islower(*code))
		{
			return 0;
		}
		code++;
	}
	return 1;
}
int checkNameSame(char* name1, char* name2)
{
	int same = strcmp(name1, name2);
	if (same == 0)
		return 1;
	return 0;
}
void printMenu()
{
	printf("Please choose one of the following options:\n");
	printf("press 1 to add a flight to the airline \n");
	printf("press 2 to add an airport the the airport manager \n");
	printf("press 3 to print details of airline \n");
	printf("press 4 to print details of airport manager \n");
	printf("press 5 to Print the number of existing flights from a specific destination \n");
	printf("press 6 to  Print all existing flights with a specific plane code \n");
	printf("press 7 to  Print all existing flights with a specific plane type \n");
	printf("press 8 to exit the program \n");
}
