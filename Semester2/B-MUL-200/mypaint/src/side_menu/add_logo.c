/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** add_logo
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"

static void detect_click(my_paint *p, my_window *window)
{
    for (int i = 0; p->m->b[i] != NULL; i++) {
        update_button_state(window, p->m->b[i]);
        if (IS_CLICK(p->m->b[i]->state)) {
            p->m->b[i]->function(p);
        }
    }
}

void display_logo(my_paint *p, my_window *window)
{
    sfRenderWindow_drawSprite(window->renderer, p->d->sprite, NULL);
    detect_click(p, window);
    for (int i = 0; p->m->b[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(window->renderer,
        p->m->b[i]->shape, NULL);
    }
    sfRenderWindow_drawText(window->renderer, p->m->b[2]->text, NULL);
    sfRenderWindow_drawCircleShape(window->renderer,
    p->m->btn_tool_circle, NULL);
    if (p->values->mouse_tool == PENCIL)
        sfRenderWindow_drawSprite(window->renderer, p->m->pencil_sprite, NULL);
    if (p->values->mouse_tool == ERASER)
        sfRenderWindow_drawSprite(window->renderer, p->m->eraser_sprite, NULL);
}

void destroy_menu(side_menu_t *menu)
{
    sfTexture_destroy(menu->pencil_logo);
    sfTexture_destroy(menu->eraser_logo);
    sfSprite_destroy(menu->pencil_sprite);
    sfSprite_destroy(menu->eraser_sprite);
    destroy_buttons_array(menu->b);
    free(menu->text);
    sfCircleShape_destroy(menu->btn_tool_circle);
    free(menu);
}
