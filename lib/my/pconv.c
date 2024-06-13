/*
** EPITECH PROJECT, 2023
** pointer conv
** File description:
** base my_putnbr
*/
#include "mylib.h"

void ps_switchcase(unsigned long int modulo)
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

void pf_switchcase(unsigned long int modulo)
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
        ps_switchcase(modulo);
        break;
    }
}

int pconv(unsigned long int nb, int counter)
{
    unsigned long int modulo = 0;

    if (nb > 15) {
        modulo = (nb % 16);
        counter++;
        counter = pconv(nb / 16, counter);
        pf_switchcase(modulo);
    }
    return counter;
}
