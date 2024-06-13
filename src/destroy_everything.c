/*
** EPITECH PROJECT, 2024
** my paint
** File description:
** destroy_everything.c
*/

#include "../include/mypaint.h"
#include <stdlib.h>

static void destroy_params(shortcut_t *shortcut)
{
    sfTexture_destroy(shortcut->params.button->img.text);
    sfSprite_destroy(shortcut->params.button->img.sprt);
    sfRectangleShape_destroy(shortcut->params.button->rect);
    free(shortcut->params.button);
    sfTexture_destroy(shortcut->params.plus->img.text);
    sfSprite_destroy(shortcut->params.plus->img.sprt);
    sfRectangleShape_destroy(shortcut->params.plus->rect);
    free(shortcut->params.plus);
    sfTexture_destroy(shortcut->params.minus->img.text);
    sfSprite_destroy(shortcut->params.minus->img.sprt);
    sfRectangleShape_destroy(shortcut->params.minus->rect);
    free(shortcut->params.minus);
    sfRectangleShape_destroy(shortcut->params.gradient->rect);
    free(shortcut->params.gradient);
    sfTexture_destroy(shortcut->params.menu.text);
    sfSprite_destroy(shortcut->params.menu.sprt);
    sfRectangleShape_destroy(shortcut->params.color);
}

static void destroy_dec(shortcut_t *shortcut)
{
    sfRenderWindow_destroy(shortcut->set.win);
    sfTexture_destroy(shortcut->bg.text);
    sfSprite_destroy(shortcut->bg.sprt);
    sfTexture_destroy(shortcut->radio.text);
    sfSprite_destroy(shortcut->radio.sprt);
    sfTexture_destroy(shortcut->turret.text);
    sfSprite_destroy(shortcut->turret.sprt);
}

static void destroy_buttons(shortcut_t *shortcut)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; shortcut->drop_menus[i].options[j] != NULL; j++) {
            sfTexture_destroy(shortcut->drop_menus[i].options[j]->img.text);
            sfSprite_destroy(shortcut->drop_menus[i].options[j]->img.sprt);
            sfRectangleShape_destroy(shortcut->drop_menus[i].options[j]->rect);
            free(shortcut->drop_menus[i].options[j]);
        }
        sfTexture_destroy(shortcut->drop_menus[i].img.text);
        sfSprite_destroy(shortcut->drop_menus[i].img.sprt);
        sfRectangleShape_destroy(shortcut->drop_menus[i].button->rect);
        free(shortcut->drop_menus[i].options);
    }
}

static void destroy_about(shortcut_t *shortcut)
{
    sfTexture_destroy(shortcut->about.help.text);
    sfSprite_destroy(shortcut->about.help.sprt);
    sfTexture_destroy(shortcut->about.info.text);
    sfSprite_destroy(shortcut->about.info.sprt);
    sfTexture_destroy(shortcut->about.close_help->img.text);
    sfSprite_destroy(shortcut->about.close_help->img.sprt);
    sfRectangleShape_destroy(shortcut->about.close_help->rect);
    free(shortcut->about.close_help);
    sfTexture_destroy(shortcut->about.close_info->img.text);
    sfSprite_destroy(shortcut->about.close_info->img.sprt);
    sfRectangleShape_destroy(shortcut->about.close_info->rect);
    free(shortcut->about.close_info);
}

void destroy_everything(shortcut_t *shortcut)
{
    destroy_dec(shortcut);
    destroy_buttons(shortcut);
    destroy_about(shortcut);
    destroy_params(shortcut);
}
