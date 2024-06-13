/*
** EPITECH PROJECT, 2023
** shortd
** File description:
** antony
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

short int my_put_nbr(short int nb, short int counter)
{
    short int nombre;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        counter ++;
    }
    if (nb >= 10) {
        nombre = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb, counter);
        my_putchar(nombre + 48);
        counter ++;
    } else {
        my_putchar(nb + 48);
        counter ++;
    }
    return counter;
}
