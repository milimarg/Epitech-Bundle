/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** structs.h
*/
#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include <SFML/Audio.h>
    #include "../my_csfml/button/button.h"
typedef struct drawing_area {
    sfImage *area;
    sfSprite *sprite;
    sfTexture *drawing_area;
    int offset;
    int x;
    sfRectangleShape *rect_modal;
    sfCircleShape *circle_modal;
    size_t curr_points_nb;
    sfSprite *pencil_sprite;
    sfSprite *eraser_sprite;
} drawing_area_t;
typedef struct pixels {
    int pos_y;
    int current_thickness;
    sfColor current_color;
    int temp_x;
    int temp_y;
    int i;
    int j;
    sfVector2f current;
    sfVector2f last;
} pixels_t;
typedef struct array_of_color {
    sfImage *image;
    sfSprite *sprite_col;
    sfTexture *color_texture;
    int offset;
    sfVector2f sprite_pos;
} array_of_color_t;
typedef struct side_menu {
    sfTexture *pencil_logo;
    sfTexture *eraser_logo;
    sfSprite *pencil_sprite;
    sfSprite *eraser_sprite;
    sfVector2f pos;
    my_button **b;
    sfColor slider_bg;
    sfColor slider_fill;
    sfColor slider_outline;
    int end_value;
    char *text;
    sfCircleShape *btn_tool_circle;
    int is_slider_selected;
    sfIntRect slider;
    sfVector2f slider_text_pos;
} side_menu_t;
typedef struct my_paint {
    char **env;
    int dp_number;
    int is_paint_open;
    int enable_os;
    int os_sounds_number;
    sfFont *font;
    sfColor bg_color;
    sfColor *btn_colors;
    my_dropdown **dp;
    sfSound **os_sounds;
    sfSoundBuffer **os_soundbuffers;
    sfTexture *os_bg_texture;
    sfSprite *os_bg_sprite;
    my_button **desktop_button;
    my_window *w;
    drawing_area_t *d;
    save_popup *save;
    open_popup *open;
    about_popup *about;
    help_popup *help;
    my_values *values;
    pixels_t *pix;
    array_of_color_t *arr_color;
    side_menu_t *m;
} my_paint;
#endif /*STRUCTS_H_*/
