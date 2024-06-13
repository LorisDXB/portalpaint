/*
** EPITECH PROJECT, 2023
** shortuflag
** File description:
** antony
*/

int substractor(unsigned long int nb)
{
    unsigned long int max = 4294967296;
    unsigned long int g = max - nb;

    return g;
}

int uconv(unsigned long int nb, int counter)
{
    unsigned long int nombre;
    unsigned long int g;

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
