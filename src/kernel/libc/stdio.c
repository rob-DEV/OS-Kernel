//
// Created by dev on 23/03/18.
//



#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>

#include "include/string.h"
#include "include/itoa.h"
#include "include/stdio.h"


bool print(const char* data, size_t length) {
    const unsigned char* bytes = (const unsigned char*) data;
    for (size_t i = 0; i < length; i++)
        if (putch(bytes[i]) == EOF)
            return false;
    return true;
}

#define is_digit(c) ((c) >= '0' && (c) <= '9')

static int skip_atoi(const char **s)
{
    int i = 0;

    while (is_digit(**s))
        i = i * 10 + *((*s)++) - '0';
    return i;
}

#define ZEROPAD 1       /* pad with zero */
#define SIGN    2       /* unsigned/signed long */
#define PLUS    4       /* show plus */
#define SPACE   8       /* space if plus */
#define LEFT    16      /* left justified */
#define SPECIAL 32      /* 0x */
#define SMALL   64      /* use 'abcdef' instead of 'ABCDEF' */

#define do_div(n,base) ({ \
int __res; \
__asm__("divl %4":"=a" (n),"=d" (__res):"0" (n),"1" (0),"r" (base)); \
__res; })

static char* number(char* str, int num, int base, int size, int precision, int type) {
    char c, sign, tmp[36];
    const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;

    if (type & SMALL)
    {
        digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    }

    if (type & LEFT)
    {
        type &= ~ZEROPAD;
    }

    if (base < 2 || base > 36)
    {
        return 0;
    }

    c = (type & ZEROPAD) ? '0' : ' ';

    if (type & SIGN && num < 0)
    {
        sign = '-';
        num = -num;
    }
    else
    {
        sign = (type&PLUS) ? '+' : ((type&SPACE) ? ' ' : 0);
    }

    if (sign)
    {
        size--;
    }

    if (type&SPECIAL)
    {
        if (base == 16)
        {
            size -= 2;
        }
        else if (base == 8)
        {
            size--;
        }
    }

    i = 0;

    if (num == 0)
    {
        tmp[i++] = '0';
    }
    else
    {
        while (num != 0)
        {
            tmp[i++] = digits[do_div(num, base)];
        }
    }

    if (i > precision)
    {
        precision = i;
    }

    size -= precision;

    if (!(type&(ZEROPAD + LEFT)))
    {
        while (size-- > 0)
        {
            *str++ = ' ';
        }
    }

    if (sign)
    {
        *str++ = sign;
    }

    if (type&SPECIAL)
    {
        if (base == 8)
        {
            *str++ = '0';
        }
        else if (base == 16)
        {
            *str++ = '0';
            *str++ = digits[33];
        }
    }

    if (!(type&LEFT))
    {
        while (size-- > 0)
        {
            *str++ = c;
        }
    }

    while (i < precision--)
    {
        *str++ = '0';
    }

    while (i-- > 0)
    {
        *str++ = tmp[i];
    }

    while (size-- > 0)
    {
        *str++ = ' ';
    }
    return str;
}

int printf(const char* __restrict format, ...){
    va_list parameters;
    va_start(parameters, format);


    int written = 0;
    char buffer[512];

    while (*format != '\0') {
        size_t maxrem = INT_MAX - written;

        if (format[0] != '%' || format[1] == '%') {
            if (format[0] == '%')
                format++;
            size_t amount = 1;
            while (format[amount] && format[amount] != '%')
                amount++;
            if (maxrem < amount) {
            // TODO: Set errno to EOVERFLOW.
                return -1;
            }
            if (!print(format, amount))
                return -1;
            format += amount;
            written += amount;
            continue;
        }

        const char* format_begun_at = format++;

        if (*format == 'c') {
            format++;
            char c = (char) va_arg(parameters, int /* char promotes to int */);
            if (!maxrem) {
                // TODO: Set errno to EOVERFLOW.
                return -1;
            }
            if (!print(&c, sizeof(c)))
                return -1;
            written++;
        }
        else if (*format == 's') {
            format++;
            const char* str = va_arg(parameters, const char*);
            size_t len = strlen(str);
            if (maxrem < len) {
                // TODO: Set errno to EOVERFLOW.
                return -1;
            }
            if (!print(str, len))
                return -1;
            written += len;
        }
        else if (*format == 'd') {
            format++;
            int input = va_arg(parameters, int /* char promotes to int */);

            itoa(input, buffer);
            if (!maxrem) {
                // TODO: Set errno to EOVERFLOW.
                return -1;
            }
            if (!print(buffer, strlen(buffer)))
                return -1;
            written++;
        } else if (*format == 'x') {
            format++;
            int input = va_arg(parameters, int /* char promotes to int */);
            itoa(input, buffer);
            if (!maxrem) {
                // TODO: Set errno to EOVERFLOW.
                return -1;
            }
            if (!print(buffer, strlen(buffer)))
                return -1;
            written++;
        } else {
            format = format_begun_at;
            size_t len = strlen(format);
            if (maxrem < len) {
                // TODO: Set errno to EOVERFLOW.
                return -1;
            }
            if (!print(format, len))
                return -1;
            written += len;
            format += len;
        }
    }

    va_end(parameters);
    return written;
}




