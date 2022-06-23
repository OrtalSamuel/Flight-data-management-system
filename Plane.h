#ifndef PLANE_H
#define PLANE_H

#define PLANE_CODE_LENGTH 4

typedef enum { ePassengers, eCharger, eMilitary, eNofTypes } Type;
/*
Type t = ePassengers;
print t
0
t.name()
*/
const char* typeTilte[eNofTypes];

typedef struct
{
	char* code;
	Type theType;

}Plane;

//must:
int initPlane(Plane* plane);
void initplaneCode(Plane* plane);
void getplaneType(Plane* plane);
void printPlane(const Plane* plane);
void freePlane(Plane* plane);

#endif // !PLANE_H
