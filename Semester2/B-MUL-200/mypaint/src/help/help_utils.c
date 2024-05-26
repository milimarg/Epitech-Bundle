/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** help_utils
*/

#include <stdlib.h>
#include "../../my_csfml/window/window.h"
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include "../../include/about.h"
#include "../../include/help.h"

void add_help_popup(my_paint *p)
{
    p->help->size.x = 500;
    p->help->size.y = 300;
}
