/*
 * Exercise 1-4
 *
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */

#include <stdio.h>

/* print Celsius-Fahrenheit table for cels = -40, -30, ..., 100;
 * floating-point version
 */

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -40;        /* lower limit of temperature table */
    upper = 100;        /* upper limit */
    step = 10;          /* step size */

    printf("Celsius to Fahrenheit Conversions\n");
    printf("%3s %6s\n", "C", "F");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f %6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
