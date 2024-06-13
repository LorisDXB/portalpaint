/*
** EPITECH PROJECT, 2023
** ldflag
** File description:
** antony
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

long int my_put_nbr(long int nb, long int counter)
{
    long int nombre;

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
