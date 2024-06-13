/*
** EPITECH PROJECT, 2023
** my_atoi.c
** File description:
** my_atoi.c
*/

#include <stdio.h>

int my_atoi(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] > '9' || str[i] < '0')
            return -1;
        res = res * 10 + str[i] - '0';
    }
    return res;
}
