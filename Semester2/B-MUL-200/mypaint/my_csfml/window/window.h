/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_
    #include <SFML/Graphics.h>
    #include "../animation/animation.h"
typedef struct my_window {
    int width;
    int height;
    int bitsPerPixel;
    char *title;
    sfRenderWindow *renderer;
    sfClock *clock;
    sfVector2f ratio;
} my_window;
typedef struct my_background {
    int width;
    int height;
    sfSprite *sprite;
} my_background;
// @brief Init a window.
// @param title title of window
// @param width width of window
// @param height of window
// @return A window structure.
my_window *create_window(char *title, int width, int height);

// @brief Clears a window with black color.
// @param window window structure
void clear_window(my_window *window);

// @brief Display a window.
// @param window window structure
void refresh_window(my_window *window);

// @brief Init a background.
// @param name_tag name_tag for the background
// @param textures_list textures linked list
// @return A background structure
my_background *init_background(char *name_tag, my_textures_list *textures_list);

// @brief Display a background.
// @param window window structure
// @param background background structure
void display_background(my_window *window, my_background *background);
int get_time_clock(my_window *window);
void restart_clock(my_window *window);
int destroy_window(my_window *window);
int destroy_background(my_background *background);
sfVector2u update_window_ratio(my_window *window);
#endif /* !WINDOW_H_ */
