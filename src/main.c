/*
** EPITECH PROJECT, 2023
** my_hunter
** File description:
** my_hunter
*/

#include "../include/mypaint.h"

void window_loop(shortcut_t *shortcut)
{
    sfTexture *texture = sfTexture_createFromFile(BUTTON_BRUSH, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, 1);
    sfSprite_setScale(sprite, (sfVector2f){1, 1});
    while (sfRenderWindow_isOpen(shortcut->set.win)) {
        while (sfRenderWindow_pollEvent(shortcut->set.win,
            &shortcut->set.evt))
            handle_events(shortcut);
        sfRenderWindow_clear(shortcut->set.win, sfWhite);
        draw_sprites(shortcut);
        sfRenderWindow_display(shortcut->set.win);
    }
    destroy_everything(shortcut);
}

int main(int argc, char **argv)
{
    shortcut_t shortcut;

    init_shortcut(&shortcut);
    my_printf("%X\n", "12345678912345634567189324875661748935871643758123455");
    window_loop(&shortcut);
    return 0;
}
