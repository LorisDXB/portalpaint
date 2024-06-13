/*
** EPITECH PROJECT, 2024
** strdup
** File description:
** strdup
*/

#include "mylib.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    while (i < my_strlen(src)) {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
