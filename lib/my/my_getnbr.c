/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** task lib
*/

#include <stdlib.h>

char *is_zero(void)
{
    char *result = malloc(sizeof(char) * 2);

    result[0] = '0';
    result[1] = '\0';
    return result;
}

char *handle_nbr(int i, int *num, char *result)
{
    while ((*num) != 0) {
        result[i] = '0' + ((*num) % 10);
        i--;
        (*num) /= 10;
    }
    return result;
}

char *my_getnbr(int number)
{
    int num = number;
    int count = 0;
    char *result;
    int i;

    while (num != 0) {
        num /= 10;
        count++;
    }
    if (count == 0)
        return is_zero();
    result = malloc(sizeof(char) * (count + 1));
    num = number;
    i = count - 1;
    result = handle_nbr(i, &num, result);
    result[count] = '\0';
    return result;
}
