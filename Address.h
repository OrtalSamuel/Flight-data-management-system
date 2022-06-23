#ifndef ADDRESS_H
#define ADDRESS_H

typedef struct
{
	char* country;
	char* town;
	char* street;
	int numberOfHome;
}Address;

//must:
void initAirportAddres(char* address);
void printAddress(const Address* address);
void freeAddress(Address* address);

//extra:
void validateInput(char* str);
char* addressToString(const Address* address);

#endif // !ADDRESS_H