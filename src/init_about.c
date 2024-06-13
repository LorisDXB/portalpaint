/*
** EPITECH PROJECT, 2024
** my paint
** File description:
** help_window.c
*/

#include "../include/mypaint.h"

void init_help(shortcut_t *shortcut)
{
    shortcut->about.help = create_image(HELP_WINDOW, (sfVector2f){2, 2},
        (sfVector2f){0, 0});
    shortcut->about.close_help = init_button((sfVector2f){1800, 20},
        (sfVector2f){100, 100});
    shortcut->about.close_help->img = create_image(BUTTON_CLOSE,
        (sfVector2f){0.3, 0.3}, (sfVector2f){1800, 20});
}

void init_info(shortcut_t *shortcut)
{
    shortcut->about.info = create_image(INFO_WINDOW, (sfVector2f){2, 2},
        (sfVector2f){0, 0});
    shortcut->about.close_info = init_button((sfVector2f){1800, 20},
        (sfVector2f){100, 100});
    shortcut->about.close_info->img = create_image(BUTTON_CLOSE,
        (sfVector2f){0.3, 0.3}, (sfVector2f){1800, 20});
}
