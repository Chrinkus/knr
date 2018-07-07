/*
 * Exercise 1-15
 *
 * Rewrite the temperature conversion program to use a function for conversion.
 */

#include <stdio.h>

#define LOWER   0
#define UPPER   300
#define STEP    20

float ftoc(int f);

int main()
{
    int fahr;

    printf("Fahrenheit to Celsius\n");
    printf("%3s %6s\n", "F", "C");

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, ftoc(fahr));
}

float ftoc(int f)
{
    return (5.0/9.0) * (f - 32);
}

