/*
** EPITECH PROJECT, 2023
** HexDecimal conv
** File description:
** base my_putnbr
*/
#include "mylib.h"

void ss_switchcase(long int modulo)
{
    switch (modulo) {
    case 14:
        my_putchar('e');
        break;
    case 15:
        my_putchar('f');
        break;
    default:
        my_putchar(modulo + 48);
        break;
    }
}

void ff_switchcase(long int modulo)
{
    switch (modulo) {
    case 10:
        my_putchar('a');
        break;
    case 11:
        my_putchar('b');
        break;
    case 12:
        my_putchar('c');
        break;
    case 13:
        my_putchar('d');
        break;
    default:
        ss_switchcase(modulo);
        break;
    }
}

int hexconv(unsigned int nb, int counter)
{
    unsigned int modulo = 0;

    if (nb > 0) {
        counter++;
        counter = hexconv(nb / 16, counter);
        modulo = (nb % 16);
        ff_switchcase(modulo);
    }
    return counter;
}
