/* 
 * Exercise 5-0
 *
 * Testing pointer return values.
 */

#include <stdio.h>

#define BUFMAX  1000

void printp(char *s)
{
    printf("function ptr: %x\n", s);
}

int main()
{
    char *pc = "Have a nice day!";
    int i = 123;
    int *pi = &i;

    printf("char ptr: %x, %s\n", pc, pc);
    printf("int ptr: %x, %d\n", pi, *pi);
    printp(pc);
}
