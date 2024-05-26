/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** my.h
*/
#ifndef MY_H_
    #define MY_H_
void fill_dropdowns(my_paint *paint);
void dropdown_handler(my_dropdown *dp, my_window *window, my_paint *paint);
void paint_destroyer(my_paint *paint);
int os_handler(my_window *window, sfEvent *event, my_paint *paint);
void paint_handler(my_window *window, sfEvent *event, my_paint *paint);
void init_pixel_area(drawing_area_t *d, my_values *v, my_window *window);
int init_first_boot(int is_first_boot, my_paint *paint, my_window *window);
void draw_function(my_window *window, my_paint *paint);
void destroy_drawing_area(drawing_area_t *d);
int is_quit(sfEvent *event, my_paint *paint, my_window *window);
void update_sizes_main(my_paint *paint);
my_button **init_buttons_array(unsigned int buttons_number);
my_button* add_button(sfIntRect *rectangle, sfColor *color,
void (*function)(void *values), char *display_name);
void display_buttons(my_button **buttons, my_window *window);
my_dropdown *init_dropdown(sfIntRect *rectangle, sfColor *color,
char *display_name);
void destroy_dropdown(my_dropdown *dp);
void display_dropdown(my_dropdown *dp, my_window *window);
void update_dropdown_state(my_window *window, my_dropdown *dp,
my_values *values);
void detect_clicks_dropdown(my_dropdown *dp, my_window *window,
my_values *values, void *dummy_paint);
int destroy_buttons_array(my_button **buttons);
void init_pixels(pixels_t *p);
void set_os_sounds(my_paint *paint);
void run_shutdown_sound(my_paint *paint);
void destroy_sounds(my_paint *p);
void set_pencil(void *values);
void set_eraser(void *values);
array_of_color_t *init_arr_col(array_of_color_t *arr);
void array_color(my_paint *p, my_window *win);
int display_array_color(my_paint *p, my_window *window);
void destroy_arr_color(array_of_color_t *arr);
void new_file(void *values);
void check_keyboard_shortcuts(my_paint *p);
void set_os_background(my_paint *p);
void destroy_os_background(my_paint *p);
#endif /*MY_H_*/
