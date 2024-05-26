/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** array_of_color
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include <stdlib.h>

int display_array_color(my_paint *p, my_window *window)
{
    if (!p->arr_color->color_texture)
        return 84;
    if (p->values->mouse_tool == PENCIL)
        sfRenderWindow_drawSprite(window->renderer,
        p->arr_color->sprite_col, NULL);
    return 0;
}

void array_color(my_paint *p, my_window *win)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win->renderer);
    sfFloatRect rec = sfSprite_getGlobalBounds(p->arr_color->sprite_col);

    if (sfFloatRect_contains(&rec, pos.x, pos.y))
        p->values->pencil_color = sfImage_getPixel(p->arr_color->image,
        pos.x - p->arr_color->offset, pos.y);
}

void destroy_arr_color(array_of_color_t *arr)
{
    sfImage_destroy(arr->image);
    sfSprite_destroy(arr->sprite_col);
    sfTexture_destroy(arr->color_texture);
    free(arr);
}
