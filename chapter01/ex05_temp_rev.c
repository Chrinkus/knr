/*
 * Exercise 1-5
 *
 * Modify the temperature conversion program to print the table in reverse
 * order.
 *
 * Using symbolic constants just because.
 */

#include <stdio.h>

#define LOWER 0             /* lower limit of table */
#define UPPER 300           /* upper limit */
#define STEP 20             /* step size */

int main()
{
    int fahr;

    printf("Fahrenheit to Celsius: Descending\n");
    printf("%3s %6s\n", "F", "C");

    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));
}
