/*
** EPITECH PROJECT, 2023
** HexDecimal conv MAJ VER
** File description:
** base my_putnbr
*/

#include "mylib.h"

void sss_switchcase(long int modulo)
{
    switch (modulo) {
    case 14:
        my_putchar('E');
        break;
    case 15:
        my_putchar('F');
        break;
    default:
        my_putchar(modulo + 48);
        break;
    }
}

void fff_switchcase(long int modulo)
{
    switch (modulo) {
    case 10:
        my_putchar('A');
        break;
    case 11:
        my_putchar('B');
        break;
    case 12:
        my_putchar('C');
        break;
    case 13:
        my_putchar('D');
        break;
    default:
        sss_switchcase(modulo);
        break;
    }
}

int majhexconv(unsigned int nb, int counter)
{
    unsigned int modulo = 0;

    if (nb > 0) {
        counter++;
        counter = majhexconv(nb / 16, counter);
        modulo = (nb % 16);
        fff_switchcase(modulo);
    }
    return counter;
}
