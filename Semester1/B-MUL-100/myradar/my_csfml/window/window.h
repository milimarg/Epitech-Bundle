/*
** EPITECH PROJECT, 2022
** my_csfml
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_
typedef struct my_window {
    int width;
    int height;
    int bitsPerPixel;
    char *title;
    sfRenderWindow *renderer;
    sfClock *clock;
    void (*clear)(struct my_window *);
    void (*refresh)(struct my_window *);
    int (*destroy)(struct my_window *);
} my_window;
typedef struct my_background {
    int width;
    int height;
    char *path;
    float x_offset;
    float y_offset;
    sfTexture *texture;
    sfSprite *sprite;
    void (*init)(struct my_background *, char *, int, int);
    void (*finish)(struct my_background *, int, int);
    void (*display)(my_window *, struct my_background *);
    int (*destroy)(struct my_background *);
} my_background;
my_window *create_window(char *title, int width, int height);
my_background *init_background(char *path, int width, int height);
void set_offset_background(my_background *ptr, int x_offset, int y_offset);
void display_background(my_window *window, my_background *background);
int get_time_clock(my_window *window);
void restart_clock(my_window *window);
int destroy_window(my_window *window);
int destroy_background(my_background *background);
#endif /* !WINDOW_H_ */
