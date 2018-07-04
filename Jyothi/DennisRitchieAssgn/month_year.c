#include <stdio.h>
#include <stdlib.h>
#define MAX 32
static char daytab[2][31] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
 
int readinput()
{
	char *str = NULL;
	int val;
	
	if(NULL == (str = (char *) malloc(sizeof(char) * MAX)))
	{
		perror("malloc failed:");
		exit(EXIT_FAILURE);
	}
	if(NULL == (fgets(str, MAX,stdin)))
	{
		perror("fgets failed: ");
		exit(EXIT_FAILURE);
	}
	
	val = atoi(str);
	free(str);
	
	return val;
}

int day_of_year(int year, int month, int day)
{
	int index, leap;
	
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	
	if(day > daytab[leap][month])
	{
		perror("Invalid day input: ");
		exit(EXIT_FAILURE);
	}
	
	for(index = 1; index < month; index++)
		day += daytab[leap][index];
	
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int index, leap;
	
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	if(leap == 0)
	{
		if(yearday > 365)
		{
			perror("It's not a leap year: ");
			exit(EXIT_FAILURE);
		}
	}
	
	for(index = 1; yearday > daytab[leap][index]; index++)
		yearday -= daytab[leap][index];
	
	*pmonth = index;
	*pday = yearday;
}

int main(void)
{
	int day;
	int mnth;
	int yr;
	int yearday;
	int no_of_days;
	
	printf("Enter the day (in numbers) b/w 1-31 = ");
	day = readinput();
	
	if((day < 1) || (day > 31))
	{
		perror("Invalid day input: ");
		exit(EXIT_FAILURE);
	}
	
	printf("Enter the month (in numbers) b/w 1-12 = ");
	mnth = readinput();
	
	if(mnth < 1 || mnth > 12)
	{
		perror("Invalid input month: ");
		exit(EXIT_FAILURE);
	}
	
	printf("Enter the year (in numbers) b/w 1-2017 = ");
	yr = readinput();
	
	if(yr < 1 || yr > 2017)
	{
		perror("Invalid year input: ");
		exit(EXIT_FAILURE);
	}

	printf("Enter the total days (in numbers) b/w 1-366 = ");
	yearday = readinput();

	if(yearday < 1 || yearday > 366)
	{
		perror("Invalid yearday: ");
		exit(EXIT_FAILURE);
	}	
/*	if((day < 1 &&	day > 31) || (mnth < 1 && mnth > 12) || (yr < 1 && yr > 2017) || (yearday < 1 && yearday > 366))
	{
		perror("Invalid input: ");
		exit(EXIT_FAILURE);
	}
*/	
	no_of_days = day_of_year(yr, mnth, day);
	month_day(yr, yearday, &mnth, &day);
	
	printf("Year = %d\n", yr);
	printf("Month = %d\n", mnth);
	printf("Day = %d\n", day);
	printf("Yeardays = %d\n", yearday);
	
	return 0;
}
