/*
** EPITECH PROJECT, 2023
** luflag
** File description:
** antony
*/

long int substractor(long unsigned int nb)
{
    long unsigned int max = 4294967296;
    long unsigned int g = max - nb;

    return g;
}

long int uconv(long unsigned int nb, int counter)
{
    long unsigned int nombre;
    long unsigned int g;

    if (nb < 0) {
        g = substractor(nb * -1);
        uconv(g, counter);
    }
    if (nb >= 10) {
        nombre = nb % 10;
        nb = nb / 10;
        uconv(nb, counter);
        my_putchar(nombre + 48);
        counter++;
    } else {
        my_putchar(nb + 48);
        counter++;
    }
    return counter;
}
