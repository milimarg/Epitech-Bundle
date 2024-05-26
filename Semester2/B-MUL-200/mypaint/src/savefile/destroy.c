/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** destroy_savefile_popup.c
*/

#include <stdlib.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"

void destroy_savefile_popup(save_popup *s)
{
    s->buttons[s->buttons_nb] = NULL;
    destroy_buttons_array(s->buttons);
    for (int i = 0; i < s->ext_nb; i++) {
        sfText_destroy(s->ext_names[i]);
    }
    sfText_destroy(s->field);
    sfRectangleShape_destroy(s->field_bg);
    free(s->ext_names);
    free(s->field_content);
    free(s);
}
