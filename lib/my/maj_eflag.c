/*
** EPITECH PROJECT, 2023
** majeflag
** File description:
** majeflag
*/

#include "mylib.h"

int maj_efflag(double flt, int counter)
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
        zer_add(tten, counter);
        counter = my_put_nbr(tten, counter);
    }
    return counter;
}

int majone_nbr(int nb)
{
    if (nb > 0 && nb < 10) {
        return 1;
    }
    return 0;
}

int maj_eflag(double flt, int counter)
{
    long double fltstock = flt;
    long unsigned int expo = 0;

    if (fltstock < 0) {
        my_putchar('-');
        counter++;
        fltstock = fltstock * -1;
    }
    while (majone_nbr(fltstock) != 1) {
        expo++;
        fltstock = fltstock / 10;
    }
    counter = maj_efflag(fltstock, counter) + 2;
    my_putchar('E');
    my_putchar('+');
    if (expo < 10) {
        my_putchar('0');
    }
    counter = my_put_nbr(expo, counter) + 1;
    return counter;
}
