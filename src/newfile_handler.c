/*
** EPITECH PROJECT, 2024
** newfile handler
** File description:
** newfile
*/

#include "../include/mypaint.h"
#include "../lib/my/mylib.h"

int new_filehandler(shortcut_t *shortcut)
{
    for (int i = 0; i < 1920 * 1080 * 4; i += 4) {
        shortcut->toolbox->p_ar->pix[i] = 255;
        shortcut->toolbox->p_ar->pix[i + 1] = 255;
        shortcut->toolbox->p_ar->pix[i + 2] = 255;
        shortcut->toolbox->p_ar->pix[i + 3] = 255;
    }
}
