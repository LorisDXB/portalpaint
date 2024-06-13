/*
** EPITECH PROJECT, 2023
** mixer_tab file
** File description:
** mixer
*/

int mixer_tab_two(char *mixer, char *dir)
{
    if (my_strcmp(mixer, "lar-") == 0) {
        if (flag_lar(dir, 0) == 84)
            return 84;
        return 0;
    }
    if (my_strcmp(mixer, "--r-") == 0) {
        if (flag_r(dir, 0) == 84)
            return 84;
        return 0;
    }
    if (my_strcmp(mixer, "----") == 0) {
        if (flag_none(dir) == 84)
            return 84;
        return 0;
    }
    if (my_strcmp(mixer, "l-r-") == 0) {
        if (flag_lr(dir, 0) == 84)
            return 84;
        return 0;
    }
}
