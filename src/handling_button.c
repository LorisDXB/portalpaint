/*
** EPITECH PROJECT, 2024
** bootstrap
** File description:
** handling_button.c
*/

#include "../include/mypaint.h"
#include <stdlib.h>

static sfBool sub_is_clicked(button_t *button, sfMouseButtonEvent *event,
    sfFloatRect button_zone, sfSound *sound)
{
    if (sfFloatRect_contains(&button_zone, event->x, event->y)) {
        sfSound_play(sound);
        button->state = (button->state == RELEASED) ? PRESSED : RELEASED;
    }
    if (button->state == PRESSED)
        return sfFalse;
    else if (button->state == RELEASED)
        return sfTrue;
}

sfBool is_clicked(button_t *button, sfMouseButtonEvent *event, sfSound *sound)
{
    sfFloatRect button_zone = sfRectangleShape_getGlobalBounds(button->rect);

    if (event->type == sfEvtMouseButtonPressed)
        return sub_is_clicked(button, event, button_zone, sound);
}

sfBool is_hover(button_t *button, sfMouseMoveEvent *event)
{
    sfFloatRect button_zone = sfRectangleShape_getGlobalBounds(button->rect);
    sfColor color = sfSprite_getColor(button->img.sprt);

    if (sfFloatRect_contains(&button_zone, event->x, event->y)
        && button->state != PRESSED) {
        color.a = 150;
        sfSprite_setColor(button->img.sprt, color);
        button->state = HOVER;
        return sfTrue;
    } else if (!sfFloatRect_contains(&button_zone, event->x, event->y)
        && button->state != PRESSED) {
        color.a = 255;
        sfSprite_setColor(button->img.sprt, color);
        button->state = RELEASED;
        return sfFalse;
    }
}

button_t *init_button(sfVector2f position, sfVector2f size)
{
    button_t *button = malloc(sizeof(button_t));

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    button->state = RELEASED;
    return button;
}
