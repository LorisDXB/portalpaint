/*
** EPITECH PROJECT, 2023
** str_to_array
** File description:
** turns a string into an array ('\n' are separators)
*/

#include "./mylib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int space_skipper(const char *str, int i, int tp)
{
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (tp == 0)
        return i - 1;
    if (tp == 1)
        return i;
}

int count_cells_str(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\0')
            count++;
        i++;
    }
    return count;
}

int len_str(char const *str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;
    return count;
}

static void sub_str_to_array(int *j, int *cell)
{
    *j = 0;
    *cell += 1;
}

char **str_to_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (count_cells_str(str) + 2));
    char *word = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;
    int b = space_skipper(str, 0, 1);
    int j = 0;
    int cell = 0;

    for (int i = b; i < len_str(str); i++) {
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0') {
            word[j] = str[i];
            i++;
            j++;
        }
        i = space_skipper(str, i, 0);
        word[j] = '\0';
        array[cell] = malloc(sizeof(char) * j + 1);
        my_strcpy(array[cell], word);
        sub_str_to_array(&j, &cell);
    }
    return array;
}
