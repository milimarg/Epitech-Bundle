/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** sidemenu
*/

#ifndef SIDEMENU_H_
    #define SIDEMENU_H_
void calc_slider_value(void *values);
void handle_slider(my_paint *p, my_window *window);
void set_slider_value(my_paint *p);
void init_side_menu(my_paint *p);
void display_logo(my_paint *p, my_window *window);
void destroy_menu(side_menu_t *menu);
void square(void *values);
void circle(void *values);
void dummy(void *values);
#endif /* !SIDEMENU_H_ */
