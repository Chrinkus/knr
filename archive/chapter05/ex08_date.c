/*
 * Exercise 5-8
 *
 * There is no error checking in day_of_year or month_day. Remedy this defect.
 *
 * day_of_year must assure that it is working on acceptable values. Month must
 * be 1-12 and days cannot exceed the number of days in the indicated month.
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (month < 1 || 12 < month)                /* test for valid month */
        return -1;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if (day < 1 || daytab[leap][month] < day)   /* test for valid day */
        return -1;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 ||  year%400 == 0;

    if (yearday > (leap ? 366 : 365)) {
        *pmonth = *pday = -1;
        return;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int month, day;

    printf("My birthday was the %d day of 2018\n", day_of_year(2018, 2, 27));

    month_day(2018, 58, &month, &day);
    printf("The 58th day of the year is in month %d, on day %d\n",
            month, day);

    month_day(2020, 100, &month, &day);
    printf("The 100th day of a leap year is in month %d on day %d\n",
            month, day);

    month_day(1997, 100, &month, &day);
    printf("The 100th day of a regular year is in month %d on day %d\n",
            month, day);

    month_day(2011, 400, &month, &day);
    printf("The 400th day of a regular year is in month %d on day %d\n",
            month, day);

    printf("An invalid date is the %d of a year\n", day_of_year(2014, 13, 2));
}
