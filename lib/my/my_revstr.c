/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** task3 day5
*/

char my_swapbis(char *a, char *b)
{
    char astock;

    astock = *a;
    *a = *b;
    *b = astock;
}

int my_strlenbis(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return i;
}

char *my_revstr(char *str)
{
    int i;
    int l;

    i = 0;
    l = my_strlenbis(str) -1;
    while (i < l) {
        my_swapbis(&str[i], &str[l]);
        i++;
        l--;
    }
    return str;
}
