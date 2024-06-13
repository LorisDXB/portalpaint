/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** task1 day4
*/

void my_swap(int *a, int *b)
{
    int astock;

    astock = *a;
    *a = *b;
    *b = astock;
}
