/*
** EPITECH PROJECT, 2023
** doom
** File description:
** my.h
*/

#ifndef MY_IDT1_H_
    #define MY_IDT1_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <math.h>
    #define deg_to_rad(x) (x / 180.0 * M_PI)
    #define char_isalpha(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    #define my_char_isvisible(c) (c >= '!' && c <= '~')
    #include "struct.h"
    #include "lib.h"

/* WORLD */

my_idt1 *create_world_from_file(char *filepath, map_type type,
sfKeyCode reload_key, my_idt1_player *player);
my_idt1 *create_world_from_memory(sfVector2u *size, my_idt1_player *player);
void reload_world(my_idt1 *world, char *filepath);
void display_world(my_idt1 *world);
void destroy_world(my_idt1 *world);

/* PLAYER */

void move_player(my_idt1 *world);
void clip_behind_player(sfVector3i *one, sfVector3i *two);
void move_front(my_idt1 *world, sfVector2i *delta);
void move_back(my_idt1 *world, sfVector2i *delta);
void turn_left(my_idt1 *world, sfVector2i *delta);
void turn_right(my_idt1 *world, sfVector2i *delta);
void go_up(my_idt1 *world, sfVector2i *delta);
void go_down(my_idt1 *world, sfVector2i *delta);
void lean_to_ground(my_idt1 *world, sfVector2i *delta);
void lean_to_sky(my_idt1 *world, sfVector2i *delta);
void strafe_left(my_idt1 *world, sfVector2i *delta);
void strafe_right(my_idt1 *world, sfVector2i *delta);

/* PARSING */

void parse_file(my_idt1 *world);
void convert_dante_to_config(char *filepath);
void fill_sector(sectors_t *sector, shape_type shape, sfVector3f *pos,
sfVector3f *size);

/* DRAW */

void draw_point(int x, int y, sfColor color, my_idt1 *world);
void draw_wall(coordinates_wall *wall, sfColor color, int s, my_idt1 *world);
void draw_one_wall(my_idt1 *world, int loop, int s, sfVector3i *wpos);

/* MISC */

sfColor get_texture_pixel(sfVector2u *pos, sfVector2u *texture_size,
sfImage *image);
void set_some_points_values(sfVector2i *one_two, my_idt1 *world,
wall_t *wall, int loop);
coordinates_wall set_walls_pos_depending_of_window_position(sfVector3i *wpos,
my_idt1 *world);
void set_surface_type(my_idt1 *world, int s);
void set_wpos_values(sfVector3i *wpos, sfVector2i *one_two,
int s, my_idt1 *world);
void parse_file(my_idt1 *world);
void create_shape(my_idt1 *world, shape_infos *infos);
void set_ground_and_sky(sfRenderWindow *window, my_idt1 *world);
void allocate_sectors(my_idt1 *world, int sectors_nb);
#endif /*MY_IDT1_H_*/
