/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** math
*/

#include <math.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"

double get_direction_angle(airplane_t *airplane)
{
    return (((atan2(airplane->pos_start.y - airplane->pos_end.y,
    airplane->pos_start.x - airplane->pos_end.x)) * 180 / M_PI));
}
