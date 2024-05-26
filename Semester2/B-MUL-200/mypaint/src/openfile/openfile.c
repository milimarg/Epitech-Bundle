/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** openfile.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include "../../include/savefile.h"
#include "../../include/openfile.h"

void dummy(void *values)
{
    return;
}

void add_open_file_popup(my_paint *p)
{
    p->open = malloc(sizeof(open_popup));
    p->open->size = (sfVector2f){400, 300};
    p->open->max_buttons = (p->open->size.y / 30);
    p->open->fp_index = 0;
    p->open->scroll_bar = sfRectangleShape_create();
    sfRectangleShape_setFillColor(p->open->scroll_bar, p->btn_colors[3]);
    sfRectangleShape_setOutlineColor(p->open->scroll_bar, p->btn_colors[3]);
}

int open_image(char *path_to_file, drawing_area_t *d)
{
    sfImage_destroy(d->area);
    d->area = sfImage_createFromFile(path_to_file);
    if (d->area == NULL)
        return (1);
    sfTexture_destroy(d->drawing_area);
    d->drawing_area = sfTexture_createFromImage(d->area, NULL);
    return (0);
}
