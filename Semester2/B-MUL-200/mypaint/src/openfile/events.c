/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** events.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../my_csfml/lib/lib.h"
#include "../../include/structs.h"
#include "../../include/openfile.h"
#include "../../include/my.h"

static void fill_linked_list(my_paint *p, char *element)
{
    char *current_dir = my_strdup(element);
    path *fp = NULL;
    int full_len = 0;

    add_directory_to_path(p->open, current_dir);
    for (fp = p->open->filepath_list; fp != NULL; fp = fp->next)
        full_len += fp->len + 1;
    p->open->current_path = malloc(sizeof(char) * (full_len + 1));
    p->open->current_path[0] = 0;
    for (fp = p->open->filepath_list; fp != NULL; fp = fp->next) {
        p->open->current_path = my_strcat(p->open->current_path, fp->dir_name);
        p->open->current_path = my_strcat(p->open->current_path, "/");
    }
}

void update_sizes_openfile(open_popup *o)
{
    sfVector2u new_size = sfRenderWindow_getSize(o->window->renderer);
    sfVector2f value = {0};
    float subdivision = new_size.y / (o->buttons_nb - o->max_buttons + 1);

    o->scroll_rect = (sfIntRect){0, 0, 20, subdivision};
    sfRectangleShape_setPosition(o->scroll_bar, (sfVector2f){0});
    o->max_buttons = (double)new_size.y / 30.0;
    update_window_ratio(o->window);
    for (int i = 0; i < o->buttons_nb; i++) {
        sfRectangleShape_setScale(o->buttons[i]->shape, o->window->ratio);
        value.x = o->buttons[i]->rect.left * o->window->ratio.x;
        value.y = o->buttons[i]->rect.top * o->window->ratio.y;
        sfRectangleShape_setPosition(o->buttons[i]->shape, value);
        sfText_setScale(o->buttons[i]->text, o->window->ratio);
        sfText_setPosition(o->buttons[i]->text, value);
        value.x = new_size.x - 20;
        value.y = o->buttons[i]->rect.height;
        sfRectangleShape_setSize(o->buttons[i]->shape, value);
    }
}

static int events_loop(open_popup *o, my_values *v, my_paint *p)
{
    sfEvent event = {0};

    if (display_buttons_events_fp(o, p))
        return (1);
    while (sfRenderWindow_pollEvent(o->window->renderer, &event)) {
        if (event.type == sfEvtClosed || p->values->popup_shown == NO) {
            p->values->popup_shown = NO;
            destroy_buttons_array(o->buttons);
            destroy_file_explorer(o->filepath_list);
            destroy_window(o->window);
            return (1);
        }
        if (event.type == sfEvtResized)
            update_sizes_openfile(o);
        if (event.type == sfEvtMouseWheelScrolled)
            scroll_in_directory_fp(o, (event.mouseWheelScroll.delta == -1));
    }
    return (0);
}

int refresh_current_dir(my_paint *p, char *element)
{
    fill_linked_list(p, element);
    p->open->pdir = opendir(p->open->current_path);
    destroy_buttons_array(p->open->buttons);
    set_file_explorer(p->open, p->font);
    free(p->open->current_path);
    return (1);
}

int handle_open_popup(my_paint *p)
{
    if (p->values->popup_shown == OPEN_FILE) {
        sfRenderWindow_clear(p->open->window->renderer, p->bg_color);
        if (events_loop(p->open, p->values, p))
            return (1);
        sfRenderWindow_display(p->open->window->renderer);
    }
    return (0);
}
