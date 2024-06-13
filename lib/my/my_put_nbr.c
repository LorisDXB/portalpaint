/*
** EPITECH PROJECT, 2023
** ggg
** File description:
** ggg
*/

#include "mylib.h"

int my_put_nbr(int nb, int counter)
{
    int modulo = 0;

    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    }
    if (nb < 0) {
        my_putchar('-');
    }
    if (nb > 9) {
        modulo = (nb % 10);
        my_putchar(modulo + 48);
    }
    return 0;
}
