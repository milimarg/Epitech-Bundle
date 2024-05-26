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

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    int a = 0;
    framebuffer_t pix;
    framebuffer_t *arr;

    arr = malloc(sizeof(pix) * (width * height));

    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            arr[a].pixel = &sfMagenta;
            arr[a].height = i;
            arr[a].width = j;
            a++;
        }
    }
    return arr;
}
