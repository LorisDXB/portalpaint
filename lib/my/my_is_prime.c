/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** task6 day5
*/

int my_is_prime(int nb)
{
    int i = nb / 2;

    if (nb <= 1) {
        return 0;
    }
    if (nb == 2 || nb == 3) {
        return 1;
    }
    while (i > 1) {
        if (nb % i == 0) {
            return 0;
        }
        i--;
    }
    return 1;
}
