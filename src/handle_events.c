/*
** EPITECH PROJECT, 2024
** my paint
** File description:
** handle_events.c
*/

#include "../include/mypaint.h"
#include "../lib/my/mylib.h"

static int hover_options(drop_menu_t drop_menu)
{
    for (int i = 0; drop_menu.options[i] != NULL; i++) {
        if (drop_menu.options[i]->state == HOVER)
            return 1;
    }
    return 0;
}

static void handle_params(shortcut_t *shortcut)
{
    is_clicked(shortcut->params.button, &shortcut->set.evt.mouseButton,
        shortcut->toolbox->sound.sound);
    if (shortcut->params.button->state == PRESSED) {
        shortcut->toolbox->paintbrush->inuse = false;
        is_hover(shortcut->params.plus, &shortcut->set.evt.mouseMove);
        is_hover(shortcut->params.minus, &shortcut->set.evt.mouseMove);
        if (clicked_on(shortcut->params.gradient,
            &shortcut->set.evt.mouseButton,
            shortcut->toolbox->sound.sound) == sfTrue) {
            sfRectangleShape_setFillColor(shortcut->params.color,
                get_color(shortcut));
            shortcut->toolbox->paintbrush->color = get_color(shortcut);
        }
        change_brush_size(shortcut);
    }
}

static void sub_handle_display(shortcut_t *shortcut, int i)
{
    for (int j = 0; shortcut->drop_menus[i].options[j] != NULL; j++) {
        is_hover(shortcut->drop_menus[i].options[j],
                &shortcut->set.evt.mouseMove);
        if (shortcut->drop_menus[i].options[j]->state == PRESSED)
            shortcut->drop_menus[i].options[j]->state = HOVER;
    }
    if (shortcut->drop_menus[i].button->state == RELEASED
            && hover_options(shortcut->drop_menus[i]) == 0)
        shortcut->drop_menus[i].hitbox->state = RELEASED;
}

static void click_about(shortcut_t *shortcut, int i)
{
    if (shortcut->drop_menus[2].hitbox->state == HOVER)
        is_clicked(shortcut->drop_menus[2].options[i],
        &shortcut->set.evt.mouseButton, shortcut->toolbox->sound.sound);
}

static void handle_display(shortcut_t *shortcut)
{
    close_window(shortcut->set.win, shortcut->set.evt);
    is_hover(shortcut->params.button, &shortcut->set.evt.mouseMove);
    if (shortcut->params.button->state != PRESSED) {
        shortcut->toolbox->paintbrush->inuse = true;
        for (int i = 0; i < 2; i++) {
            is_hover_dm(shortcut, i);
            sub_handle_display(shortcut, i);
        }
        is_hover_dm(shortcut, 2);
        for (int i = 0; shortcut->drop_menus[2].options[i] != NULL; i++) {
            is_hover(shortcut->drop_menus[2].options[i],
                &shortcut->set.evt.mouseMove);
            click_about(shortcut, i);
        }
        if (shortcut->drop_menus[2].button->state == RELEASED
                && hover_options(shortcut->drop_menus[2]) == 0)
            shortcut->drop_menus[2].hitbox->state = RELEASED;
    }
}

static void handle_keys(shortcut_t *shortcut)
{
    if (shortcut->set.evt.type == sfEvtKeyPressed &&
            shortcut->set.evt.key.code == sfKeyS) {
        my_printf("which format? (.png, .jpg, .bmp): ");
        save_from_pixels(shortcut);
    }
}

static void get_held_statement(shortcut_t *shortcut, bool *ispressed)
{
    if (shortcut->set.evt.type == sfEvtMouseButtonPressed &&
            shortcut->set.evt.mouseButton.button == sfMouseLeft)
        (*ispressed) = true;
    if (shortcut->set.evt.type == sfEvtMouseButtonReleased &&
            shortcut->set.evt.mouseButton.button == sfMouseLeft)
        (*ispressed) = false;
}

static void sub_handle_clicks(shortcut_t *shortcut)
{
    static bool ispressed = false;
    static bool ppressed = false;

    get_held_statement(shortcut, &ispressed);
    if (ispressed == true && shortcut->toolbox->paintbrush->inuse == true)
        mouse_got_pressed(&ispressed, &ppressed, shortcut);
    if (ispressed == false)
        mouse_got_released(&ispressed, &ppressed, shortcut);
}

static void handle_clicks(shortcut_t *shortcut)
{
    if (shortcut->params.button->state != PRESSED) {
        is_clicked(shortcut->about.close_help, &shortcut->set.evt.mouseButton,
            shortcut->toolbox->sound.sound);
        if (shortcut->about.close_help->state == PRESSED) {
            shortcut->drop_menus[2].options[0]->state = RELEASED;
            shortcut->about.close_help->state = RELEASED;
        }
        is_clicked(shortcut->about.close_info, &shortcut->set.evt.mouseButton,
            shortcut->toolbox->sound.sound);
        if (shortcut->about.close_info->state == PRESSED) {
            shortcut->drop_menus[2].options[1]->state = RELEASED;
            shortcut->about.close_info->state = RELEASED;
        }
    }
    sub_handle_clicks(shortcut);
}

void handle_events(shortcut_t *shortcut)
{
    handle_display(shortcut);
    handle_clicks(shortcut);
    handle_params(shortcut);
    handle_keys(shortcut);
    button_click(shortcut);
}
