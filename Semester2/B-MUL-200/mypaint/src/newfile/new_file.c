/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** new_file.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/savefile.h"
#include "../../include/openfile.h"
#include "../../include/my.h"

void new_file(void *values)
{
    my_paint *p = values;

    sfImage_destroy(p->d->area);
    sfTexture_destroy(p->d->drawing_area);
    p->d->area =
    sfImage_createFromColor(740, p->w->height - p->d->offset, sfWhite);
    p->d->drawing_area =
    sfTexture_createFromImage(p->d->area, NULL);
}
