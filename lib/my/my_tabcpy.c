/*
** EPITECH PROJECT, 2024
** tabcpy.c
** File description:
** tabcpy
*/

#include "mylib.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char **my_tabcpy(char ***tab2, int tablen)
{
    char **tab1 = malloc(sizeof(char *) * (tablen + 2));
    int s = 0;

    tab1[tablen + 1] = NULL;
    for (int i = 0; (*tab2)[i] != NULL; i++) {
        tab1[i] = malloc(sizeof(char) * (my_strlen((*tab2)[i] + 1)));
        s++;
    }
    tab1[s] = malloc(sizeof(char) * (100));
    for (int i = 0; (*tab2)[i] != NULL; i++) {
        my_strcpy(tab1[i], (*tab2)[i]);
    }
    return tab1;
}
