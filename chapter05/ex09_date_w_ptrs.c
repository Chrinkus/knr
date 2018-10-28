/*
 * Exercise 5-9
 *
 * Rewrite the routines day_of_year and month_day with pointers instead of
 * indexing.
 *
 * day_of_year was satisfying. I feel like I cheated a little by still indexing
 * daytab in month_day. Oh well.
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    char *pc;

    if (month < 1 || 12 < month)                /* test for valid month */
        return -1;

    pc = daytab[year%4 == 0 && year%100 != 0 || year%400 == 0];

    if (day < 1 || pc[month] < day)             /* test for valid day */
        return -1;

    while (month--)
        day += *pc++;

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    char *pc, *p;
    pc = p = daytab[year%4 == 0 && year%100 != 0 || year%400 == 0];

    if (yearday > (p[2] == 29 ? 366 : 365)) {
        *pmonth = *pday = -1;
        return;
    }

    while (yearday > *pc)
        yearday -= *pc++;

    *pmonth = pc - p;
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
