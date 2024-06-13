/*
** EPITECH PROJECT, 2023
** my_nbrlen
** File description:
** sdfkljgsdgjsg yes
*/

int my_nbrlen(int nb)
{
    int div = 10;
    int ncount = 0;

    while (nb != 0) {
        nb = nb / div;
        ncount++;
    }
    return ncount;
}
