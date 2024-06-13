/*
** EPITECH PROJECT, 2024
** my paint
** File description:
** get_color.c
*/

#include "../include/mypaint.h"

sfBool clicked_on(button_t *button, sfMouseButtonEvent *event, sfSound *sound)
{
    sfFloatRect button_zone = sfRectangleShape_getGlobalBounds(button->rect);

    if (event->type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&button_zone, event->x, event->y)) {
            sfSound_play(sound);
            return sfTrue;
        } else {
            return sfFalse;
        }
    }
}

sfColor get_color(shortcut_t *shortcut)
{
    sfVector2i mouse_coords =
        sfMouse_getPositionRenderWindow(shortcut->set.win);

    return sfImage_getPixel(sfTexture_copyToImage(shortcut->params.menu.text),
        mouse_coords.x + 60, mouse_coords.y + 30);
}

void change_brush_size(shortcut_t *shortcut)
{
    if (clicked_on(shortcut->params.plus,
        &shortcut->set.evt.mouseButton,
        shortcut->toolbox->sound.sound) == sfTrue) {
        if (shortcut->toolbox->paintbrush->size < 100)
            shortcut->toolbox->paintbrush->size += 1;
    }
    if (clicked_on(shortcut->params.minus,
        &shortcut->set.evt.mouseButton,
        shortcut->toolbox->sound.sound) == sfTrue) {
        if (shortcut->toolbox->paintbrush->size > 1)
            shortcut->toolbox->paintbrush->size -= 1;
    }
    if (clicked_on(shortcut->drop_menus[1].options[2],
        &shortcut->set.evt.mouseButton,
        shortcut->toolbox->sound.sound) == sfTrue)
        save_from_pixels(shortcut);
}

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}
