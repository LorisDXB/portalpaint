/*
** EPITECH PROJECT, 2024
** my paint
** File description:
** button_click.c
*/

#include "../include/mypaint.h"

void button_click(shortcut_t *shortcut)
{
    if (clicked_on(shortcut->drop_menus[0].options[0],
        &shortcut->set.evt.mouseButton,
        shortcut->toolbox->sound.sound) == sfTrue) {
        shortcut->toolbox->paintbrush->inuse = true;
        shortcut->toolbox->paintbrush->color =
            sfRectangleShape_getFillColor(shortcut->params.color);
    }
    if (clicked_on(shortcut->drop_menus[0].options[1],
        &shortcut->set.evt.mouseButton,
        shortcut->toolbox->sound.sound) == sfTrue)
        shortcut->toolbox->paintbrush->color = sfTransparent;
    if (clicked_on(shortcut->drop_menus[1].options[0],
        &shortcut->set.evt.mouseButton,
        shortcut->toolbox->sound.sound) == sfTrue)
        new_filehandler(shortcut);
    clicked_on(shortcut->drop_menus[1].options[1],
        &shortcut->set.evt.mouseButton, shortcut->toolbox->error.sound);
}
