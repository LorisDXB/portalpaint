/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** task3 day4
*/

unsigned long my_strlen(char const *str)
{
    unsigned long counter;
    unsigned long i;

    i = 0;
    counter = 0;
    while (str[i] != '\0') {
        i += 1;
        counter += 1;
    }
    return counter;
}
