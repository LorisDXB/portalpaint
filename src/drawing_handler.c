/*
** EPITECH PROJECT, 2024
** drawing handle
** File description:
** the portion that handles the drawing !
*/

#include "../include/mypaint.h"
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

void color_handling(int xx, int yy, int index, shortcut_t *shortcut)
{
    if (xx >= 0 && xx < 1920 && yy >= 0 && yy < 1080) {
        index = (yy * 1920 + xx) * 4;
        shortcut->toolbox->p_ar->pix[index] =
            shortcut->toolbox->paintbrush->color.r;
        shortcut->toolbox->p_ar->pix[index + 1] =
            shortcut->toolbox->paintbrush->color.g;
        shortcut->toolbox->p_ar->pix[index + 2] =
            shortcut->toolbox->paintbrush->color.b;
        shortcut->toolbox->p_ar->pix[index + 3] =
            shortcut->toolbox->paintbrush->color.a;
    }
}

void size_handling(int x, int y, int pixelSize, shortcut_t *shortcut)
{
    int xx;
    int yy;

    for (int j = -pixelSize / 2; j <= pixelSize / 2; j++) {
        for (int k = -pixelSize / 2; k <= pixelSize / 2; k++) {
            xx = x + j;
            yy = y + k;
            color_handling(xx, yy, 0, shortcut);
        }
    }
}

static int get_highest_value(int a, int b)
{
    return (((a) > (b)) ? (a) : (b));
}

void calc_fillfromexpos(sfVector2i *exMousePos, int dx,
    int dy, shortcut_t *shortcut)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(shortcut->set.win);
    int pixelSize = shortcut->toolbox->paintbrush->size;
    int x = 0;
    int y = 0;

    if (dx != 0 || dy != 0) {
        for (int i = 0; i <= get_highest_value(abs(dx), abs(dy)); i++) {
            x = exMousePos->x + i * dx / get_highest_value(abs(dx), abs(dy));
            y = exMousePos->y + i * dy / get_highest_value(abs(dx), abs(dy));
            size_handling(x, y, pixelSize, shortcut);
        }
        sfTexture_updateFromPixels(shortcut->toolbox->p_ar->texture,
                shortcut->toolbox->p_ar->pix, 1920, 1080, 0, 0);
        (*exMousePos) = mousePos;
    }
}

void mouse_got_pressed(bool *ispressed, bool *ppressed, shortcut_t *shortcut)
{
    static sfVector2i exMousePos = {0, 0};
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(shortcut->set.win);
    int dx;
    int dy;

    if ((*ppressed) == false) {
        exMousePos = mousePos;
        (*ppressed) = true;
    }
    if (sfMouse_getPositionRenderWindow(shortcut->set.win).x >= 215 &&
        sfMouse_getPositionRenderWindow(shortcut->set.win).x <= 1868 &&
        sfMouse_getPositionRenderWindow(shortcut->set.win).y >= 36 &&
        sfMouse_getPositionRenderWindow(shortcut->set.win).y <= 980) {
        if (*ispressed && sfMouse_isButtonPressed(sfMouseLeft)) {
            dx = mousePos.x - exMousePos.x;
            dy = mousePos.y - exMousePos.y;
            calc_fillfromexpos(&exMousePos, dx, dy, shortcut);
        }
    }
}

int mouse_got_released(bool *ispressed, bool *ppressed, shortcut_t *shortcut)
{
    if ((*ppressed) == true)
        (*ppressed) = false;
    return 0;
}
