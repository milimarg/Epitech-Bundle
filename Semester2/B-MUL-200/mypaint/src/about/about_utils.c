/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** about_utils
*/

#include <stdlib.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include "../../include/about.h"

void add_about_popup(my_paint *p)
{
    p->about->size.x = 500;
    p->about->size.y = 300;
    p->about->text_pos.x = 10;
    p->about->text_pos.y = 50;
    p->about->creator_pos.x = 10;
    p->about->creator_pos.y = 100;
}
