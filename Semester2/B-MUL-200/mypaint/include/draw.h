/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** draw
*/

#ifndef DRAW_H_
    #define DRAW_H_
void draw_circle(pixels_t *pix, my_paint *p, sfVector2i *pos);
void draw_square(pixels_t *pix, my_paint *p, sfVector2i *pos);
void create_cursor(drawing_area_t *d, side_menu_t *m);
void display_cursor(my_paint *p);
int check_point_pos(sfVector2f *f_pos, drawing_area_t *d, pixels_t *pix,
my_window *window);
int anti_glitch_square(pixels_t *p, drawing_area_t *d, my_window *window);
#endif /* !DRAW_H_ */
