/*
** EPITECH PROJECT, 2024
** save function
** File description:
** for my_paint
*/

#include "../include/mypaint.h"
#include "../lib/my/mylib.h"
#include <string.h>

char *cat_image(char *format, char *name)
{
    char *newpath = malloc(sizeof(char)
        * (my_strlen(format) + my_strlen(name) + 1));

    my_strcpy(newpath, name);
    my_strcat(newpath, format);
    my_printf("swaved successfuwwy :3");
    return newpath;
}

void save_from_pixels(shortcut_t *shortcut)
{
    char *format = NULL;
    char *name = NULL;
    size_t size = 0;
    ssize_t chars_read;
    char *truename;
    sfImage *tosave;

    chars_read = getline(&format, &size, stdin);
    if (chars_read < 0)
        return;
    format[chars_read - 1] = '\0';
    my_printf("name your image: ");
    chars_read = getline(&name, &size, stdin);
    if (chars_read < 0)
        return;
    name[chars_read - 1] = '\0';
    truename = cat_image(format, name);
    tosave = sfImage_createFromPixels(1920,
        1080, shortcut->toolbox->p_ar->pix);
    sfImage_saveToFile(tosave, truename);
}
