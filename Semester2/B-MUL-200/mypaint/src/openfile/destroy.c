/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** destroy.c
*/

#include <stdlib.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"

void destroy_openfile_popup(open_popup *o)
{
    sfRectangleShape_destroy(o->scroll_bar);
    free(o);
}
