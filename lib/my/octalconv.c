/*
** EPITECH PROJECT, 2023
** octal converter
** File description:
** my_putnbr arranged to print octal
*/

#include "mylib.h"

int octalconv(int nb, int counter)
{
    int modulo = 0;

    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
        counter++;
    }
    if (nb < 0) {
        my_putchar('-');
        counter++;
        counter = octalconv(nb * -1, counter);
    }
    if (nb > 7) {
        modulo = (nb % 8);
        counter++;
        counter = octalconv(nb / 8, counter);
        my_putchar(modulo + 48);
    }
    return counter;
}
