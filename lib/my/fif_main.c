/*
** EPITECH PROJECT, 2023
** fif main
** File description:
** fif main
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Rect.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct my_plane {
    int type;
    int *hp;
    sfTexture *texture;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f *my_pos;
    sfClock *clock;
    struct my_plane *next;
};

struct my_player {
    int *hp;
    int *score;
    int *ammo;
    int *round;
};

struct cnn {
    sfTexture *texture;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2f *my_pos;
    sfClock *clock;
    struct cnn *next;
};

void help(void)
{
    my_printf("||my_hunter||\n");
    my_printf("aim with the mouse\n");
    my_printf("shoot planes with mouse1,\n");
    my_printf("shoot boats with mouse1,\n");
    my_printf("get victory royale.\n");
}

int get_assets(void)
{
    if (sfTexture_createFromFile("./ct/p_1.png", NULL) == NULL)
        return 84;
    if (sfTexture_createFromFile("./ct/p_2.png", NULL) == NULL)
        return 84;
    if (sfTexture_createFromFile("./ct/p_3.png", NULL) == NULL)
        return 84;
    if (sfTexture_createFromFile("./ct/boat.png", NULL) == NULL)
        return 84;
    return 0;
}

void while_handler(sfRenderWindow *w, sfTexture *texture, sfSprite *sprite)
{
    my_put_tourelle(w);
    my_put_crosshair(w, texture, sprite);
    sfRenderWindow_display(w);
}

void clock_destroy(struct cnn *c_sht2, struct my_plane *boat)
{
    struct my_plane *elm = boat;
    struct cnn *tmp = c_sht2;

    while (elm != NULL) {
        sfClock_destroy(elm->clock);
        elm = elm->next;
    }
    while (tmp != NULL) {
        sfClock_destroy(tmp->clock);
        tmp = tmp->next;
    }
}
