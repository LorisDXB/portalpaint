/*
** EPITECH PROJECT, 2023
** %f flag
** File description:
** flag
*/

#include "mylib.h"

int zer_add(long int tten, int counter)
{
    if (tten >= 0 && tten < 10) {
        counter = my_putstr("00000", counter);
    }
    if (tten >= 10 && tten < 100) {
        counter = my_putstr("0000", counter);
    }
    if (tten >= 100 && tten < 1000) {
        counter = my_putstr("000", counter);
    }
    if (tten >= 1000 && tten < 10000) {
        counter = my_putstr("00", counter);
    }
    if (tten >= 10000 && tten < 100000) {
        counter = my_putstr("0", counter);
    }
    return counter;
}

int fflag(double flt, int counter)
{
    long unsigned int nb = flt;
    long double stocked = flt - nb;
    long int tten = (stocked * 1000000) + 0.5;

    if (stocked >= 0.9999994) {
        counter = my_put_nbr(nb + 1, counter);
        my_putchar('.');
        counter++;
        counter = my_putstr("00000", counter);
        counter = my_put_nbr(tten - tten, counter);
    } else {
        counter = my_put_nbr(nb, counter);
        my_putchar('.');
        counter++;
        counter = zer_add(tten, counter);
        counter = my_put_nbr(tten, counter);
    }
    return counter;
}
