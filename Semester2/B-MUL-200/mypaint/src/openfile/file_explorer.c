/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** file_explorer.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../my_csfml/lib/lib.h"
#include "../../include/structs.h"
#include "../../include/openfile.h"
#include "../../include/my.h"

void set_file_explorer(open_popup *o, sfFont *font)
{
    sfIntRect rect = {0};
    sfVector2f size = {20, o->window->height};
    sfVector2u ns = update_window_ratio(o->window);

    rect = (sfIntRect){20, 0, ns.x - 20, 30};
    o->buttons_nb = get_files_infos(o, font, 0, &rect);
    o->buttons = init_buttons_array(o->buttons_nb);
    get_files_infos(o, font, 1, &rect);
    o->buttons[o->buttons_nb] = NULL;
    closedir(o->pdir);
    if (o->buttons_nb > o->max_buttons) {
        size.y = o->window->height / (o->buttons_nb - o->max_buttons + 1);
        sfRectangleShape_setSize(o->scroll_bar, size);
    }
    o->scroll_rect = (sfIntRect){0, 0, size.x, size.y};
    update_sizes_openfile(o);
}

void destroy_file_explorer(path *fp)
{
    path *element = NULL;

    while (fp != NULL) {
        element = fp;
        fp = fp->next;
        free(element->dir_name);
        free(element);
    }
}
