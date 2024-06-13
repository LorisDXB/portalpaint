/*
** EPITECH PROJECT, 2023
** main de my_printf
** File description:
** Tu/24/Oc
*/

#include <stdarg.h>
#include <stdlib.h>
#include "mylib.h"

int fo_switchcase(char *s, va_list args, int spot, int counter)
{
    switch (s[spot + 1]) {
    case 'e':
        counter = eflag(va_arg(args, double), counter);
        break;
    case 'E':
        counter = maj_eflag(va_arg(args, double), counter);
        break;
    case 'g':
        counter = gflag(va_arg(args, double), counter);
        break;
    case 'G':
        counter = maj_gflag(va_arg(args, double), counter);
        break;
    }
    return 0;
}

int t_switchcase(char *s, va_list args, int spot, int counter)
{
    switch (s[spot + 1]) {
    case 'n':
        *va_arg(args, int *) = nfunc(s);
        break;
    case 'u':
        counter = uconv(va_arg(args, int), counter);
        break;
    case 'p':
        my_putstr("0x", counter);
        counter = pconv(va_arg(args, unsigned long int), counter);
        break;
    case 'f':
        counter = fflag(va_arg(args, double), counter);
        break;
    default:
        counter = fo_switchcase(s, args, spot, counter);
        break;
    }
    return counter;
}

int s_switchcase(char *s, va_list args, int spot, int counter)
{
    switch (s[spot + 1]) {
    case '%':
        my_putchar('%');
        counter++;
        break;
    case 'o':
        counter = octalconv(va_arg(args, int), counter);
        break;
    case 'X':
        counter = majhexconv(va_arg(args, int), counter);
        break;
    case 'x':
        counter = hexconv(va_arg(args, int), counter);
        break;
    default:
        counter = t_switchcase(s, args, spot, counter);
        break;
    }
    return counter;
}

void f_switchcase(char *s, va_list args, int spot, int *counter)
{
    switch (s[spot + 1]) {
    case 'i':
    case 'd':
        *counter = my_put_nbr(va_arg(args, int), *counter);
        break;
    case 'c':
        my_putchar(va_arg(args, int));
        (*counter)++;
        break;
    case 's':
        *counter = my_putstr(va_arg(args, char *), *counter);
        break;
    default:
        *counter = s_switchcase(s, args, spot, *counter);
        break;
    }
}

static int checkflags(int i, char *format)
{
    char *flags = "nugGpf%oXxeEidcs";

    for (unsigned long int b = 0; b != my_strlen(flags); b++) {
        if (flags[b] == format[i + 1]) {
            return 1;
        }
    }
    return 0;
}

int my_printf(char *format, ...)
{
    int i = 0;
    int counter = 0;
    va_list args;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%' && checkflags(i, format) == 1) {
            f_switchcase(format, args, i, &counter);
            i += 2;
        } else {
            my_putchar(format[i]);
            i++;
            counter++;
        }
    }
    return counter;
}
