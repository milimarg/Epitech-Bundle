/*
** EPITECH PROJECT, 2022
** CPOOL_Day13
** File description:
** my_list.h
*/

#ifndef MY_STRUCT_H
    #define MY_STRUCT_H
#include <SFML/Graphics/Color.h>

typedef struct framebuffer {
    sfColor *pixel;
    unsigned int width;
    unsigned int height;
} framebuffer_t;
#endif
