#ifndef DATE_H
#define DATE_H

#define MAX_DATE 12
#define MAX_DAY 2
#define MAX_MONTH 2
#define MAX_YEAR 4

typedef struct
{
	int day;
	int month;
	int year;

}Date;

//must:

void initDate(Date* date);
void printDate(const Date* date);

//extra:
int checkDateFormat(char* date);
int checkDateNumbers(char* dateStr, int* day, int* month, int* year);
int checkDayMonth(int* day, int* month);

#endif
