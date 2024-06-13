/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** drop_menu.c
*/

#include "../include/mypaint.h"
#include <stdio.h>
#include <stdlib.h>

drop_menu_t *add_option_drop_menu(drop_menu_t *drop_menu, sfVector2f position,
    sfVector2f size, int nb_options)
{
    drop_menu->options = malloc(sizeof(button_t) * (nb_options + 1));
    for (int i = 0; i < nb_options; i++) {
        drop_menu->options[i] = init_button((sfVector2f)
            {position.x + size.x * (i + 1), position.y}, size);
    }
    drop_menu->options[nb_options] = NULL;
    return drop_menu;
}

sfBool is_hover_dm(shortcut_t *shortcut, int i)
{
    sfFloatRect dmbut_zone = sfRectangleShape_getGlobalBounds(shortcut->
        drop_menus[i].button->rect);
    sfColor color = sfSprite_getColor(shortcut->drop_menus[i].img.sprt);

    if (sfFloatRect_contains(&dmbut_zone, shortcut->set.evt.mouseMove.x,
        shortcut->set.evt.mouseMove.y)) {
        shortcut->drop_menus[i].hitbox->state = HOVER;
        color.a = 150;
        sfSprite_setColor(shortcut->drop_menus[i].img.sprt, color);
        shortcut->drop_menus[i].button->state = HOVER;
        return sfTrue;
    } else {
        color.a = 255;
        sfSprite_setColor(shortcut->drop_menus[i].img.sprt, color);
        shortcut->drop_menus[i].button->state = RELEASED;
        return sfFalse;
    }
}

dm_button_t *init_dm_button(sfVector2f pos, sfVector2f size)
{
    dm_button_t *dm_button = malloc(sizeof(dm_button_t));

    dm_button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(dm_button->rect, size);
    sfRectangleShape_setPosition(dm_button->rect, pos);
    dm_button->state = RELEASED;
    return dm_button;
}

drop_menu_t *create_drop_menu(sfVector2f position, sfVector2f size,
    int nb_options)
{
    drop_menu_t *drop_menu = malloc(sizeof(drop_menu_t));

    drop_menu->button = init_dm_button(position, size);
    drop_menu->options = NULL;
    drop_menu = add_option_drop_menu(drop_menu, position, size, nb_options);
    drop_menu->hitbox = init_button(position, (sfVector2f){size.x, size.y
        * (nb_options + 1)});
    drop_menu->hitbox->state = RELEASED;
    return drop_menu;
}
