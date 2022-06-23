#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Date.h"
#include "utils.h"

int checkDateFormat(char* date)
{
	for (int i = 0; i < MAX_DATE; ++i)
	{
		if ((i == 2 && *date != '$') || (i == 3 && *date != '$') || (i == 6 && *date != '$') || (i == 7 && *date != '$'))
		{
			return 0;
		}
		else if (!(isdigit(*date)) && i != 2 && i != 3 && i != 6 && i != 7)
		{
			return 0;
		}
		date++;
	}
	return 1;
}
int checkDateNumbers(char* dateStr, int* day, int* month, int* year)
{
	//dd$$mm$$yyyy
	//11$$05$$1996

	char* dayStr;
	dayStr = (char*)malloc((MAX_DAY + 1)* sizeof(char));
	strcpy(dayStr, strtok(dateStr, "$$"));
	char* monthStr;
	monthStr = (char*)malloc((MAX_MONTH + 1)* sizeof(char));
	strcpy(monthStr, strtok(dateStr + 4, "$$"));
	char* yearStr;
	yearStr = (char*)malloc((MAX_YEAR + 1)* sizeof(char));
	strcpy(yearStr, strtok(dateStr + 8, "$$"));
	*day = atoi(dayStr);
	*month = atoi(monthStr);
	*year = atoi(yearStr);
	free(dayStr);
	free(monthStr);
	free(yearStr);
	return (checkDayMonth(day, month) == 1 && *year >= 2022);
}

int checkDayMonth(int* day, int* month)
{
	if (*month == 2 && *day > 0 && *day < 29)
	{
		return 1;
	}
	if ((*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10 || *month == 12) && (*day > 0 && *day < 32))
	{
		return 1;
	}
	if ((*month == 4 || *month == 6 || *month == 9 || *month == 11) && (*day > 0 && *day < 31))
	{
		return 1;
	}
	return 0;
}

void initDate(Date * date)
{
	char tempDate[MAX_DATE + 1];
	int day;
	int month;
	int year;

	int okStracture = 0;
	int okNumbers = 0;
	int okdayToMonth = 0;
	getchar();

	do {
		printf("enter flight date in format dd$$mm$$yyyy\n");
		myGets(tempDate, MAX_DATE + 1);
		if (strlen(tempDate) == MAX_DATE)
		{
			okStracture = checkDateFormat(tempDate);
			getchar();
			if (okStracture)
			{
				okNumbers = checkDateNumbers(tempDate, &day, &month, &year);
				if (okNumbers)
				{
					okdayToMonth = checkDayMonth(&day, &month);
				}
			}
		}
		if (!okStracture || !okNumbers || !okdayToMonth)
		{
			printf("Wrong input try again\n");
		}
	} while (!okStracture || !okNumbers || !okdayToMonth);

	date->day = day;
	date->month = month;
	date->year = year;
}

void printDate(const Date* date)
{
	printf("Date: %02d$$%02d$$%d \n", date->day, date->month, date->year);
}

