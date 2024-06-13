/*
** EPITECH PROJECT, 2023
** yes
** File description:
** yes
*/

#include "mylib.h"

int my_strncmp(char const *s1, char const *s2)
{
    int size1 = my_strlen(s1);

    for (int i = 0; i < size1; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}
