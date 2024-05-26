/*
** EPITECH PROJECT, 2022
** CPOOL_Day13_task02
** File description:
** framebuffer_create.c
*/

#include <SFML/Graphics/Color.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_struct.h"

void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y, sfColor color)
{
    framebuffer[(x * 600) + y].pixel = &color;
}
