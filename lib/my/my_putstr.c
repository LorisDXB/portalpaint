/*
** EPITECH PROJECT, 2023
** myputstr
** File description:
** task2 day4
*/

#include "mylib.h"

int my_putstr(char const *str, int counter)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
