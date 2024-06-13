/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** init_shortcut.c
*/

#include "../include/mypaint.h"
#include <stdlib.h>

img_t create_image(char *path, sfVector2f scale, sfVector2f position)
{
    img_t img;

    img.text = sfTexture_createFromFile(path, NULL);
    img.sprt = sfSprite_create();
    img.scale = scale;
    img.pos = position;
    sfSprite_setTexture(img.sprt, img.text, sfTrue);
    sfSprite_setScale(img.sprt, scale);
    sfSprite_setPosition(img.sprt, position);
    return img;
}

static void sub_init_drop_menus(shortcut_t *shortcut)
{
    shortcut->drop_menus[1].options[1]->img = create_image(BUTTON_OPEN,
        (sfVector2f){0.2, 0.2}, (sfVector2f){255, 345});
    shortcut->drop_menus[1].options[2]->img = create_image(BUTTON_SAVE,
        (sfVector2f){0.2, 0.2}, (sfVector2f){355, 345});
    shortcut->drop_menus[2] = *create_drop_menu((sfVector2f){55, 655},
        (sfVector2f){100, 100}, 2);
    shortcut->drop_menus[2].img = create_image(BUTTON_ABOUT,
        (sfVector2f){0.2, 0.2}, (sfVector2f){55, 655});
    shortcut->drop_menus[2].options[0]->img = create_image(BUTTON_HELP,
        (sfVector2f){0.2, 0.2}, (sfVector2f){155, 655});
    shortcut->drop_menus[2].options[1]->img = create_image(BUTTON_INFO,
        (sfVector2f){0.2, 0.2}, (sfVector2f){255, 655});
}

static void init_drop_menus(shortcut_t *shortcut)
{
    img_t img = {sfTexture_createFromFile(BUTTON_BRUSH, NULL),
        sfSprite_create(), (sfVector2f){1, 1}, (sfVector2f){500, 500}};

    shortcut->drop_menus = malloc(sizeof(drop_menu_t) * 4);
    shortcut->drop_menus[0] = *create_drop_menu((sfVector2f){55, 195},
        (sfVector2f){100, 100}, 2);
    shortcut->drop_menus[0].img = create_image(BUTTON_TRAIL,
        (sfVector2f){0.2, 0.2}, (sfVector2f){55, 195});
    shortcut->drop_menus[0].options[0]->img = create_image(BUTTON_BRUSH,
        (sfVector2f){0.2, 0.2}, (sfVector2f){155, 195});
    shortcut->drop_menus[0].options[1]->img = create_image(BUTTON_ERASER,
        (sfVector2f){0.2, 0.2}, (sfVector2f){255, 195});
    shortcut->drop_menus[1] = *create_drop_menu((sfVector2f){55, 345},
        (sfVector2f){100, 100}, 3);
    shortcut->drop_menus[1].img = create_image(BUTTON_FILE,
        (sfVector2f){0.2, 0.2}, (sfVector2f){55, 345});
    shortcut->drop_menus[1].options[0]->img = create_image(BUTTON_NEW,
        (sfVector2f){0.2, 0.2}, (sfVector2f){155, 345});
    sub_init_drop_menus(shortcut);
}

static void init_dec(shortcut_t *shortcut)
{
    sound_t song = {sfSoundBuffer_createFromFile(SOUND_MUSIC),
        sfSound_create()};

    shortcut->turret = create_image(PORTAL_TURRET, (sfVector2f){1, 1},
        (sfVector2f){50, 827});
    shortcut->radio = create_image(PORTAL_RADIO, (sfVector2f){0.9, 0.9},
        (sfVector2f){62, 141});
    shortcut->music = song;
    sfSound_setVolume(shortcut->music.sound, 50);
    sfSound_setBuffer(shortcut->music.sound, shortcut->music.buffer);
    sfSound_play(shortcut->music.sound);
    sfSound_setLoop(shortcut->music.sound, 1);
}

static void init_window(shortcut_t *shortcut)
{
    shortcut->set.mode.width = 1920;
    shortcut->set.mode.height = 1080;
    shortcut->set.mode.bitsPerPixel = 32;
    shortcut->set.win = sfRenderWindow_create(shortcut->set.mode, "My Paint",
        sfResize | sfClose, NULL);
}

static void sub_init_params(shortcut_t *shortcut)
{
    shortcut->params.plus = init_button((sfVector2f){1708, 140},
        (sfVector2f){150, 150});
    shortcut->params.plus->img = create_image(BUTTON_PLUS,
        (sfVector2f){0.3, 0.3}, (sfVector2f){1708, 140});
    sfRectangleShape_setOutlineColor(shortcut->params.plus->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(shortcut->params.plus->rect, 1.5);
    shortcut->params.minus = init_button((sfVector2f){1508, 140},
        (sfVector2f){150, 150});
    shortcut->params.minus->img = create_image(BUTTON_MINUS,
        (sfVector2f){0.3, 0.3}, (sfVector2f){1508, 140});
    sfRectangleShape_setOutlineColor(shortcut->params.minus->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(shortcut->params.minus->rect, 1.5);
}

static void init_params(shortcut_t *shortcut)
{
    shortcut->params.button = init_button((sfVector2f){55, 500},
        (sfVector2f){100, 100});
    shortcut->params.button->img = create_image(BUTTON_PARAMS,
        (sfVector2f){0.2, 0.2},
        (sfVector2f){55, 500});
    sfRectangleShape_setOutlineColor(shortcut->params.button->rect, sfBlack);
    shortcut->params.menu = create_image(PARAMS_MENU, (sfVector2f){0.95, 0.95},
        (sfVector2f){1445, 0});
    shortcut->params.gradient = init_button((sfVector2f){1493, 560},
        (sfVector2f){380, 380});
    shortcut->params.color = sfRectangleShape_create();
    sfRectangleShape_setSize(shortcut->params.color, (sfVector2f){350, 140});
    sfRectangleShape_setPosition(shortcut->params.color,
        (sfVector2f){1508, 350});
    sfRectangleShape_setOutlineColor(shortcut->params.color, sfBlack);
    sfRectangleShape_setOutlineThickness(shortcut->params.color, 1.5);
    sfRectangleShape_setFillColor(shortcut->params.color, sfBlack);
    sub_init_params(shortcut);
}

void init_shortcut(shortcut_t *shortcut)
{
    init_window(shortcut);
    init_drop_menus(shortcut);
    init_dec(shortcut);
    init_help(shortcut);
    init_info(shortcut);
    init_params(shortcut);
    shortcut->toolbox = init_toolbox(shortcut->toolbox);
    shortcut->bg = create_image(PAINT_FRAME, (sfVector2f){1, 0.936},
        (sfVector2f){0, 0});
}
