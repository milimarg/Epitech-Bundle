/*
** EPITECH PROJECT, 2023
** N4S
** File description:
** compute_average_float
*/

#include "../include/my.h"

float compute_average_float(float *tab, int size)
{
    float average = 0.0;

    for (int i = 0; i < size; i++)
        average += tab[i];
    return (average / (float)size);
}
