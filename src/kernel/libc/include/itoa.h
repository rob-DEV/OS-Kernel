//
// Created by dev on 23/03/18.
//

#ifndef OS_ITOA_H
#define OS_ITOA_H

#include "types.h"
#include "../../arch/i386/include/string.h"

int atoi(const char *str)
{
    int res =  0;
    int sign = 1; //positive default
    int i = 0;

    if(str[0] == '-') {
        sign = -1;
        i++;
    }

    for(; str[i] != '\0'; i++)
        res = res*10 + str[i] - '0';

    return sign*res;
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

#endif //OS_STDIO_H
