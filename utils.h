#ifndef UTILS_H
#define UTILSH_H

#include "Airport.h"

//to get input
char* myGets(char* buf, size_t size);

//for airport
void addedCharBetweenTwoWords(char* str);//2
void capitalLetters(char* str);//3
void checkSpacesFirst(char* str);//4
void checkSpacesLast(char* str);//4
void bigSmallLetters(char* str);//5

//for getting name of airport
int checkNameSame(char* name1, char* name);

//for menu
void printMenu();

int checkCODE(char* code);

#endif // !UTILS_H

