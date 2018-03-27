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

static char hex [] = { '0', '1', '2', '3', '4', '5', '6', '7',
                       '8', '9' ,'A', 'B', 'C', 'D', 'E', 'F' };

int uintToHexStr(unsigned int num,char* buff)
{
    int len=0,k=0;
    do//for every 4 bits
    {
        //get the equivalent hex digit
        buff[len] = hex[num&0xF];
        len++;
        num>>=4;
    }while(num!=0);
    //since we get the digits in the wrong order reverse the digits in the buffer
    for(;k<len/2;k++)
    {//xor swapping
        buff[k]^=buff[len-k-1];
        buff[len-k-1]^=buff[k];
        buff[k]^=buff[len-k-1];
    }
    //null terminate the buffer and return the length in digits
    buff[len]='\0';
    return len;
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
            char c = (char) va_arg(parameters, int);
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

            char buff[16];//enough for 64 bits integer
            int length;
            //convert
            length = uintToHexStr(input,buff);

            if (!maxrem) {
                // TODO: Set errno to EOVERFLOW.
                return -1;
            }
            if (!print(buff, strlen(buff)))
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




