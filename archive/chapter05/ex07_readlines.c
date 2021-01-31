/*
 * Exercise 5-7
 *
 * Rewrite readlines to store lines in an array supplie by main, rather than
 * calling alloc to maintain storage. How much faster is the program?
 *
 * My understanding of the purpose of this exercise is to compare the speed
 * of working with static/global memory and auto/local memory. To achieve a
 * meaningful result I will need to work with larger input data than my usual
 * handful of typed lines.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES    5000                /* max lines to be sorted */
#define STACKSIZE   10000               /* max size of artificial stack */

char *lineptr[MAXLINES];                /* pointers to text lines */

int  readlines(char *lineptr[], int nlines, char *stack, char *stackp);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    char stackbuf[STACKSIZE];
    char *stackp = stackbuf;

    int nlines;                         /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES, stackbuf, stackp)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN  1000                    /* max length of any input line */
int my_getline(char *, int);
char *stackalloc(char *stack, char *stackp, int n);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines, char *stack, char *stackp)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = my_getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = stackalloc(stack, stackp, len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';         /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            stackp += len;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* my_getline: get a line from input */
int my_getline(char *s, int lim)
{
    char *p = s;
    int c;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - p;
}

/* stackalloc: return pointer to n characters in stack */
char *stackalloc(char *stack, char *stackp, int n)
{
    if (stack + STACKSIZE - stackp >= n) {
        return stackp;
    } else
        return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)                  /* do nothing if array contains */
        return;                         /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
