/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** buttons
*/

#ifndef BUTTONS_H_
    #define BUTTONS_H_
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <stdio.h>
    #include <dirent.h>
    #include "../window/window.h"
typedef enum button_state {
    NONE = 0,
    HOVER,
    CLICKED,
} button_state;
typedef enum tool {
    PENCIL,
    ERASER,
} tool;
typedef enum shape {
    SQUARE,
    CIRCLE,
} shape;
typedef enum popup {
    NO,
    SAVE_FILE,
    OPEN_FILE,
    ABOUT,
    HELP,
} popup;
typedef enum file_extension {
    JPG,
    BMP,
    PNG,
} file_extension;
typedef struct my_button {
    sfRectangleShape *shape;
    sfIntRect rect;
    sfColor color;
    button_state state;
    int is_clicked;
    sfText *text;
    void (*function)(void *);
} my_button;
typedef struct my_dropdown {
    sfRectangleShape *shape;
    sfIntRect rect;
    sfColor color;
    button_state state;
    my_button **buttons;
    sfText *text;
    int display_child;
    int buttons_nb;
    int timer;
    int btn_idx;
} my_dropdown;
typedef struct save_popup {
    sfVector2f size;
    my_button **buttons;
    int buttons_nb;
    int ext_nb;
    my_window *window;
    sfText **ext_names;
    sfText *field;
    char *field_content;
    int char_max;
    int field_size;
    int is_key_pressed;
    sfRectangleShape *field_bg;
    int is_field_selected;
    sfColor field_bg_color;
    char cursor;
    int is_cursor_visible;
    int timer;
} save_popup;
typedef struct path {
    char *dir_name;
    int len;
    struct path *next;
} path;
typedef struct open_popup {
    sfVector2f size;
    my_button **buttons;
    int buttons_nb;
    int max_buttons;
    my_window *window;
    DIR *pdir;
    char *current_path;
    path *filepath_list;
    int is_dir_clicked;
    int fp_index;
    sfRectangleShape *scroll_bar;
    sfIntRect scroll_rect;
} open_popup;
typedef struct about_popup {
    my_window *win;
    sfVector2f size;
    sfText *text;
    sfVector2f text_pos;
    char *log_name;
    sfText *creator;
    sfVector2f creator_pos;
} about_popup;
typedef struct help_popup {
    my_window *win;
    sfVector2f size;
    sfTexture *bg;
    sfSprite *sprite;
} help_popup;
typedef struct my_values {
    tool mouse_tool;
    int pencil_thickness;
    int eraser_thickness;
    shape pencil_shape;
    shape eraser_shape;
    sfColor pencil_color;
    popup popup_shown;
    file_extension file_ext;
} my_values;
    #define IS_HOVER(state) (state == HOVER)
    #define IS_CLICK(state) (state == CLICKED)
    #define IS_NONE(state) (state == NONE)
void update_button_state(my_window *window, my_button *button);
#endif /* !BUTTONS_H_ */
