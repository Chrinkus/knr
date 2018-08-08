/*
 * Exercise 5-3
 *
 * Write a pointer version of the function strcat that we showed in Chapter 2:
 * strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>
#include <ctype.h>

#define BUFMAX  1000

void strcat_ptr(char *s, char *t);
int my_getline(char s[], int lim);
void trim(char *s);

int main()
{
    char buf[BUFMAX];
    char *tag = " with fire!";
    int len;

    while ((len = my_getline(buf, BUFMAX)) > 0) {
        trim(buf);
        strcat_ptr(buf, tag);
        printf("%s\n", buf);
    }
}

void strcat_ptr(char *s, char *t)
{
    while (*s != '\0')
        ++s;
    while ((*s++ = *t++) != '\0')
        ;
}

void strcat_arr(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')                /* find end of s */
        ++i;
    while ((s[i++] = t[j++]) != '\0')   /* copy t */
        ;
}

int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

void trim(char *s)
{
    char *p = s;

    while (isspace(*p))
        ++p;
    while (*p != '\0')
        *s++ = *p++;
    while (isspace(*--s))
        ;
    *++s = '\0';
}
