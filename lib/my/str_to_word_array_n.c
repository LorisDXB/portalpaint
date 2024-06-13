/*
** EPITECH PROJECT, 2023
** str_to_array
** File description:
** turns a string into an array ('\n' are separators)
*/

#include "./mylib.h"
#include <stdlib.h>
#include <string.h>

char *n_my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int n_count_cells_str(char const *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n' || str[i] == '\0')
            count++;
        i++;
    }
    return count;
}

int n_len_str(char const *str)
{
    int count = 0;

    while (str[count] != '\0')
        count++;
    return count;
}

static void n_sub_str_to_array(int *j, int *cell)
{
    *j = 0;
    *cell += 1;
}

char **n_str_to_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (n_count_cells_str(str) + 2));
    char *word = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;
    int j = 0;
    int cell = 0;

    for (int i = 0; i < n_len_str(str); i++) {
        while (str[i] != '\n' && str[i] != '\0') {
            word[j] = str[i];
            i++;
            j++;
        }
        word[j] = '\0';
        array[cell] = malloc(sizeof(char) * j + 1);
        n_my_strcpy(array[cell], word);
        n_sub_str_to_array(&j, &cell);
    }
    array[cell] = NULL;
    return array;
}
