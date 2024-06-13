/*
** EPITECH PROJECT, 2023
** dfshsdfh
** File description:
** fshsfdh
*/

#include <stdlib.h>
#include "mylib.h"

void my_charcat(char *dest, const char src)
{
    while (*dest != '\0') {
        dest++;
    }
    *dest = src;
    dest++;
    *dest = '\0';
}

int for_integrator(long unsigned int h, char *pattern)
{
    if (h == my_strlen(pattern))
        h = 0;
    return h;
}

char **my_square_gen(int size, char *pattern)
{
    char **tab = malloc(sizeof(char *) * (size + 3));
    int h = 0;

    for (int j = 0; j != size + 2; j++)
        tab[j] = malloc(sizeof(char) * (size + 1));
    my_strcat(tab[0], "1\n");
    for (int i = 1; i != size + 1; i++) {
        for (int b = 0; b != size; b++) {
            h = for_integrator(h, pattern);
            tab[i][b] = pattern[h];
            h++;
        }
        tab[i][size] = '\n';
    }
    my_charcat(tab[size - 1], '\0');
    return tab;
}
