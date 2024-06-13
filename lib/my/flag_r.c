/*
** EPITECH PROJECT, 2023
** flag_r
** File description:
** flag_r
*/

#include <dirent.h>

int size_of_array(char **tab)
{
    int counter = 0;

    for (int i = 0; tab[i] != 0; i++) {
            counter++;
    }
    return counter;
}

char **my_rev_array(char **tab)
{
    int size = size_of_array(tab);
    int end = size_of_array(tab) - 1;
    int start = 0;
    char *lock;

    while (start <= end) {
        lock = tab[start];
        tab[start] = tab[end];
        tab[end] = lock;
        start++;
        end--;
    }
    return tab;
}

int dir_counter(char *path)
{
    struct dirent* usrlen;
    int nb = 0;
    DIR* ff = opendir(path);

    usrlen = readdir(ff);
    while (usrlen != 0) {
        nb++;
        usrlen = readdir(ff);
    }
    return nb;
}

int flag_r(char *path)
{
    struct dirent* entitynone;
    DIR* dir;
    char **tab;

    dir = opendir(path);
    tab = malloc(sizeof(char *) * (dir_counter(path) + 1));
    tab = my_rev_array(mallocer_l(tab, path));
    for (int i = 0; tab[i] != 0; i++) {
        my_printf("%s ", tab[i]);
    }
    free(tab);
}
