/*
** EPITECH PROJECT, 2024
** robotfactory.h
** File description:
** header file of robot factory
*/

#ifndef ROBOTFACTORY_H_
    #define ROBOTFACTORY_H_

/* Includes */
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Graphics/Rect.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
/* Visual assets are listed here */
    #define BUTTON_TRAIL "assets/visual/button_trail.png"
    #define BUTTON_BRUSH "assets/visual/button_brush.png"
    #define BUTTON_FILE "assets/visual/button_file.png"
    #define BUTTON_SAVE "assets/visual/button_save.png"
    #define BUTTON_NEW "assets/visual/button_new.png"
    #define BUTTON_OPEN "assets/visual/button_open.png"
    #define BUTTON_ERASER "assets/visual/button_eraser.png"
    #define BUTTON_PARAMS "assets/visual/button_params.png"
    #define BUTTON_RGB "assets/visual/button_rgb.png"
    #define BUTTON_INFO "assets/visual/button_info.png"
    #define BUTTON_ABOUT "assets/visual/button_about.png"
    #define BUTTON_HELP "assets/visual/button_help.png"
    #define PAINT_FRAME "assets/visual/paint_frame.png"
    #define PORTAL_RADIO "assets/visual/portal_radio.png"
    #define PORTAL_TURRET "assets/visual/portal_turret.png"
    #define HELP_WINDOW "assets/visual/help_window.png"
    #define INFO_WINDOW "assets/visual/info_window.png"
    #define BUTTON_CLOSE "assets/visual/button_close.png"
    #define PARAMS_MENU "assets/visual/params_menu.png"
    #define BUTTON_PLUS "assets/visual/button_plus.png"
    #define BUTTON_MINUS "assets/visual/button_minus.png"

/* Audio assets are listed here */
    #define SOUND_BUTTON "assets/audio/sound_button.ogg"
    #define SOUND_DRAWING "assets/audio/sound_drawing.ogg"
    #define SOUND_ERROR "assets/audio/sound_error.ogg"
    #define SOUND_MUSIC "assets/audio/sound_music.ogg"
    #define SOUND_SAVED "assets/audio/sound_saved.ogg"
    #define CROWBAR_SOUND "assets/audio/crewbar.ogg"

/* Structures */
typedef struct img_s {
    sfTexture *text;
    sfSprite *sprt;
    sfVector2f scale;
    sfVector2f pos;
} img_t;

typedef struct sound_s {
    sfSoundBuffer *buffer;
    sfSound *sound;
} sound_t;

enum button_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct button_s {
    sfRectangleShape *rect;
    img_t img;
    enum button_state state;
} button_t;

typedef struct dm_button_s {
    sfRectangleShape *rect;
    enum button_state state;
} dm_button_t;

typedef struct drop_menu_s {
    struct dm_button_s *button;
    img_t img;
    button_t **options;
    button_t *hitbox;
} drop_menu_t;

typedef struct window_s {
    sfVideoMode mode;
    sfRenderWindow *win;
    sfEvent evt;
} window_t;

typedef struct paintbrush_s {
    bool inuse;
    sfColor color;
    int size;
} paintbrush_t;

typedef struct pixels_s {
    sfTexture *texture;
    sfUint8 *pix;
    sfSprite *sprite;
    sfImage *image;
} pixels_t;

typedef struct tool_box_s {
    paintbrush_t *paintbrush;
    pixels_t *p_ar;
    sound_t sound;
    sound_t error;
} tool_box_t;

typedef struct about_s {
    img_t help;
    button_t *close_help;
    img_t info;
    button_t *close_info;
} about_t;

typedef struct param_s {
    button_t *button;
    img_t menu;
    button_t *gradient;
    sfRectangleShape *color;
    button_t *plus;
    button_t *minus;
} param_t;

typedef struct shortcut_s {
    window_t set;
    img_t bg;
    tool_box_t *toolbox;
    drop_menu_t *drop_menus;
    param_t params;
    img_t radio;
    img_t turret;
    sound_t music;
    about_t about;
} shortcut_t;

void change_brush_size(shortcut_t *shortcut);
sfBool clicked_on(button_t *button, sfMouseButtonEvent *event, sfSound *sound);
void close_window(sfRenderWindow *window, sfEvent event);
drop_menu_t *create_drop_menu(sfVector2f position, sfVector2f size,
    int nb_options);
img_t create_image(char *path, sfVector2f scale, sfVector2f position);
void destroy_everything(shortcut_t *shortcut);
void draw_sprites(shortcut_t *shortcut);
sfColor get_color(shortcut_t *shortcut);
void handle_events(shortcut_t *shortcut);
button_t *init_button(sfVector2f position, sfVector2f size);
void init_help(shortcut_t *shortcut);
void init_info(shortcut_t *shortcut);
void init_shortcut(shortcut_t *shortcut);
tool_box_t *init_toolbox(tool_box_t *toolbox);
sfBool is_clicked(button_t *button, sfMouseButtonEvent *event, sfSound *sound);
sfBool is_hover(button_t *button, sfMouseMoveEvent *event);
sfBool is_hover_dm(shortcut_t *shortcut, int i);
void mouse_got_pressed(bool *ispressed, bool *ppressed, shortcut_t *shortcut);
int mouse_got_released(bool *ispressed, bool *ppressed, shortcut_t *shortcut);
void window_loop(shortcut_t *shortcut);
void save_from_pixels(shortcut_t *shortcut);
void button_click(shortcut_t *shortcut);
int new_filehandler(shortcut_t *shortcut);

#endif /* ROBOTFACTORY_H_ */
