/*
** EPITECH PROJECT, 2024
** init toolbox
** File description:
** self explanatory UWU
*/

#include <stdio.h>
#include "../include/mypaint.h"

void init_sounds(tool_box_t *tool)
{
    sound_t button = {sfSoundBuffer_createFromFile(SOUND_BUTTON),
        sfSound_create()};
    sound_t error = {sfSoundBuffer_createFromFile(SOUND_ERROR),
        sfSound_create()};

    tool->sound = button;
    sfSound_setBuffer(tool->sound.sound, tool->sound.buffer);
    tool->error = error;
    sfSound_setBuffer(tool->error.sound, tool->error.buffer);
}

void init_paintbrush(tool_box_t *tool)
{
    tool->paintbrush = malloc(sizeof(paintbrush_t));
    tool->paintbrush->inuse = false;
    tool->paintbrush->size = 5;
    tool->paintbrush->color = sfBlack;
}

tool_box_t *init_toolbox(tool_box_t *toolbox)
{
    tool_box_t *tool = malloc(sizeof(tool_box_t));

    tool->p_ar = malloc(sizeof(pixels_t));
    tool->p_ar->texture = sfTexture_create(1920, 1080);
    tool->p_ar->sprite = sfSprite_create();
    init_sounds(tool);
    init_paintbrush(tool);
    sfSprite_setTexture(tool->p_ar->sprite, tool->p_ar->texture, sfTrue);
    tool->p_ar->pix = malloc(sizeof(sfUint8) * (1920 * 1080 * 4));
    tool->p_ar->image = sfImage_createFromPixels(1920, 1080, tool->p_ar->pix);
    for (int i = 0; i < 1920 * 1080 * 4; i += 4) {
        tool->p_ar->pix[i] = 255;
        tool->p_ar->pix[i + 1] = 255;
        tool->p_ar->pix[i + 2] = 255;
        tool->p_ar->pix[i + 3] = 255;
    }
    return tool;
}
