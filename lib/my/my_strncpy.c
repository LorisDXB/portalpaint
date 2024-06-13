/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** task 2 day6
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int n1 = n;

    while (src[i] != '\0' && n != 0) {
        dest[i] = src[i];
        i++;
        n--;
    }
    if (n1 > i) {
    dest[i] = '\0';
    }
    return dest;
}
