/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** task5 day6
*/


char iteratefind(char *str, char const *to_find, int i, int c)
{
    if (str[i] == to_find[c]) {
        i++;
        c++;
        if (c == my_strlen(to_find)) {
            return 0;
        } else {
            iteratefind(str, to_find, i, c);
        }
    }
}

char *my_strstr(char *str, char const *to_find)
{
    int i = my_strlen(str);
    int d = 0;
    int ifind = 0;
    int counter = 0;

    while (i != 0 || str[d] == to_find[0]) {
        if (str[i] == to_find[0] && (iteratefind(str, to_find, i, 0)) == 0) {
            return &str[i];
        }
        i--;
        d++;
    }
    return 0;
}
