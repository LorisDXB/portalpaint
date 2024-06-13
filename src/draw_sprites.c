/*
** EPITECH PROJECT, 2024
** my paint
** File description:
** draw_sprites.c
*/

#include "../include/mypaint.h"

static void draw_drop_menu(shortcut_t *shortcut, int i)
{
    sfRenderWindow_drawRectangleShape(shortcut->set.win,
        shortcut->params.button->rect, NULL);
    sfRenderWindow_drawSprite(shortcut->set.win,
        shortcut->params.button->img.sprt, NULL);
    if (shortcut->drop_menus[i].hitbox->state == HOVER) {
        for (int j = 0; shortcut->drop_menus[i].options[j] != NULL; j++) {
            sfRenderWindow_drawRectangleShape(shortcut->set.win,
                shortcut->drop_menus[i].options[j]->rect, NULL);
            sfRenderWindow_drawSprite(shortcut->set.win,
                shortcut->drop_menus[i].options[j]->img.sprt, NULL);
        }
    }
}

static void draw_about(shortcut_t *shortcut)
{
    if (shortcut->drop_menus[2].options[0]->state == PRESSED
        && shortcut->about.close_help->state == RELEASED) {
        sfRenderWindow_drawSprite(shortcut->set.win,
            shortcut->about.help.sprt, NULL);
        sfRenderWindow_drawSprite(shortcut->set.win,
            shortcut->about.close_help->img.sprt, NULL);
    }
    if (shortcut->drop_menus[2].options[1]->state == PRESSED
        && shortcut->about.close_info->state == RELEASED) {
        sfRenderWindow_drawSprite(shortcut->set.win,
            shortcut->about.info.sprt, NULL);
        sfRenderWindow_drawSprite(shortcut->set.win,
            shortcut->about.close_info->img.sprt, NULL);
    }
}

static void draw_params(shortcut_t *shortcut)
{
    if (shortcut->params.button->state == PRESSED) {
        sfRectangleShape_setOutlineThickness(shortcut->params.button->rect, 3);
        sfRenderWindow_drawSprite(shortcut->set.win,
            shortcut->params.menu.sprt, NULL);
        sfRenderWindow_drawRectangleShape(shortcut->set.win,
            shortcut->params.color, NULL);
        sfRenderWindow_drawRectangleShape(shortcut->set.win,
            shortcut->params.plus->rect, NULL);
        sfRenderWindow_drawSprite(shortcut->set.win,
            shortcut->params.plus->img.sprt, NULL);
        sfRenderWindow_drawRectangleShape(shortcut->set.win,
            shortcut->params.minus->rect, NULL);
        sfRenderWindow_drawSprite(shortcut->set.win,
            shortcut->params.minus->img.sprt, NULL);
    } else if (shortcut->params.button->state == RELEASED) {
        sfRectangleShape_setOutlineThickness(shortcut->params.button->rect, 0);
    }
}

void draw_sprites(shortcut_t *shortcut)
{
    sfRenderWindow_drawSprite(shortcut->set.win,
        shortcut->toolbox->p_ar->sprite, NULL);
    sfRenderWindow_drawSprite(shortcut->set.win, shortcut->bg.sprt, NULL);
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawRectangleShape(shortcut->set.win,
            shortcut->drop_menus[i].button->rect, NULL);
        sfRenderWindow_drawSprite(shortcut->set.win,
            shortcut->drop_menus[i].img.sprt, NULL);
        draw_drop_menu(shortcut, i);
    }
    sfRenderWindow_drawSprite(shortcut->set.win, shortcut->turret.sprt, NULL);
    sfRenderWindow_drawSprite(shortcut->set.win, shortcut->radio.sprt, NULL);
    draw_about(shortcut);
    draw_params(shortcut);
}
