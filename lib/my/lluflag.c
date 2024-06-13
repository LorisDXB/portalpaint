/*
** EPITECH PROJECT, 2023
** lluflag
** File description:
** antony
*/

long long int substractor(long long unsigned int nb)
{
    long long unsigned int max = 4294967296;
    long long unsigned int g = max - nb;

    return g;
}

long long int uconv(long long unsigned int nb, int counter)
{
    long long unsigned int nombre;
    long long unsigned int g;

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
