/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** color_utils
*/

#include <unistd.h>
#include <SFML/Graphics.h>
#include "../../my_csfml/button/button.h"
#include "../../include/structs.h"
#include "../../include/my.h"
#include <stdlib.h>

array_of_color_t *init_arr_col(array_of_color_t *arr)
{
    arr = malloc(sizeof(array_of_color_t));

    arr->image = sfImage_createFromFile("./assets/color.png");
    if (arr->image == NULL)
        write(1, "(color palette) error\n", 22);
    arr->sprite_col = sfSprite_create();
    arr->color_texture = sfTexture_createFromImage(arr->image, NULL);
    sfSprite_setTexture(arr->sprite_col, arr->color_texture, sfTrue);
    arr->offset = 660;
    arr->sprite_pos = (sfVector2f){arr->offset, 0};
    sfSprite_setPosition(arr->sprite_col, arr->sprite_pos);
    return arr;
}
