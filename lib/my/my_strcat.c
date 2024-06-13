/*
** EPITECH PROJECT, 2023
** dfhjknjf*
** File description:
** gfhdgf
*/
#include <stdio.h>

void my_strcat(char *dest, const char *src)
{
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
