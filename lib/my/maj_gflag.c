/*
** EPITECH PROJECT, 2023
** maj gflag
** File description:
** maj gflag
*/

#include "mylib.h"

static int maj_is_there_one(int nb)
{
    if (nb > 0 && nb < 10) {
        return 1;
    }
    return 0;
}

int maj_howmnum(int nb)
{
    int div = 10;
    int ncount = 0;

    while (nb != 0) {
        nb = nb / div;
        ncount++;
    }
    return ncount;
}

static int maj_zer_adds(long double stocked, int counter)
{
    if (stocked > 0.01 && stocked < 0.0999)
        counter = my_putstr("0", counter);
    if (stocked > 0.001 && stocked < 0.00999)
        counter = my_putstr("00", counter);
    if (stocked > 0.0001 && stocked < 0.000999)
        counter = my_putstr("000", counter);
    if (stocked > 0.00001 && stocked < 0.0000999)
        counter = my_putstr("0000", counter);
    if (stocked > 0.000001 && stocked < 0.00000999)
        counter = my_putstr("00000", counter);
    return counter;
}

static int maj_rounder(int nb, long double stocked)
{
    if ((maj_howmnum(nb) == 1) && stocked > 0.999995)
        return 1;
    if ((maj_howmnum(nb) == 2) && stocked > 0.99995)
        return 1;
    if ((maj_howmnum(nb) == 3) && stocked > 0.9995)
        return 1;
    if ((maj_howmnum(nb) == 4) && stocked > 0.995)
        return 1;
    if ((maj_howmnum(nb) == 5) && stocked > 0.95)
        return 1;
    if ((maj_howmnum(nb) == 6) && stocked > 0.5)
        return 1;
    return 0;
}

int maj_rounderhandle(int nb, double stocked, long mod, int counter)
{
    long int tten = (stocked * 100000) + 0.5;

    if (!(maj_rounder(nb, stocked) == 1)) {
        counter = my_put_nbr(nb, counter);
        my_putchar('.');
        counter = maj_zer_adds(stocked, counter + 1);
        counter = my_put_nbr(tten / mod, counter);
    } else {
        counter = my_put_nbr(nb + 1, counter);
    }
    return counter;
}

int maj_gfflag(double flt, int counter)
{
    long double stocked = flt - (int) flt;
    long int tten = (stocked * 100000) + 0.5;
    int modulo = 0;
    long unsigned int mod = 1;
    long int zer_count = -2;

    while (modulo == 0) {
        modulo = tten % mod;
        mod = mod * 10;
        zer_count++;
    }
    mod = 1;
    if (zer_count > 9)
        zer_count = 9;
    while (zer_count != 0) {
        mod = mod * 10;
        zer_count--;
    }
    counter = maj_rounderhandle((int) flt, stocked, mod, counter);
    return counter;
}

static int maj_one_nbr_check(double nb)
{
    long int nbw = nb;
    double nbb = nb - nbw;
    long nbcheck = nbb * 100000000;

    if (nbcheck == 0) {
        return 1;
    }
    return 0;
}

int maj_expo_print(long double fltstock, int expo, int counter, long stock)
{
    if (maj_one_nbr_check(fltstock) == 1)
    counter = my_put_nbr((int) fltstock, counter);
    if (maj_one_nbr_check(fltstock) == 0)
        counter = maj_gfflag(fltstock, counter);
    if ((stock > 999999 || (stock * -1) > 999999) && expo > 5) {
        counter = my_putstr("E+", counter);
        if (expo < 10) {
            my_putchar('0');
            counter++;
        }
        counter = my_put_nbr(expo, counter);
    }
    return counter;
}

int maj_gflag(double flt, int counter)
{
    long double fltstock = flt;
    long unsigned int stock = flt;
    long unsigned int expo = 0;

    if (fltstock < 0) {
        my_putchar('-');
        counter++;
        fltstock = fltstock * -1;
        stock = stock * -1;
    }
    if (stock > 999999) {
        while (maj_is_there_one(fltstock) != 1) {
            expo++;
            fltstock = fltstock / 10;
        }
    }
    counter = maj_expo_print(fltstock, expo, counter, stock);
    return counter;
}
