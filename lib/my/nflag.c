/*
** EPITECH PROJECT, 2023
** flag %n
** File description:
** flagn
*/

int nfunc(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '%' && str[i + 1] == 'n') {
            return i;
        }
        i++;
    }
    return 0;
}
