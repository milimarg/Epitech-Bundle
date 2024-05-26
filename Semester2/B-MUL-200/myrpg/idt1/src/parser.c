/*
** EPITECH PROJECT, 2023
** doom
** File description:
** parser.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "../include/my.h"

static void check_parameters_are_right(char **output)
{
    if (my_array_len(output) != 7) {
        write(2, "polyhedron parameters are wrong\n", 32);
    }
}

void get_line_info(int index, my_idt1 *world, char *buffer)
{
    char **output = NULL;

    if (index == 0) {
        world->sectors_nb = my_getnbr(buffer);
        world->sectors = malloc(sizeof(sectors_t *) * world->sectors_nb);
        for (int i = 0; i < world->sectors_nb; i++) {
            world->sectors[i] = malloc(sizeof(sectors_t));
            world->sectors[i]->points_surface = malloc(sizeof(int) *
            world->map.win_size.x);
        }
    } else {
        output = my_str_to_word_array_extra(buffer);
        check_parameters_are_right(output);
        fill_sector(world->sectors[index - 1], RECTANGLE,
        &(sfVector3f){my_getnbr(output[1]), my_getnbr(output[2]),
        my_getnbr(output[3])}, &(sfVector3f){my_getnbr(output[4]),
        my_getnbr(output[5]), my_getnbr(output[6])});
    }
}

void parse_file(my_idt1 *world)
{
    FILE *fd = NULL;
    char *buffer = NULL;
    size_t s = 0;
    int index = 0;
    char *types[] = {world->filepath, "3d_config"};

    fd = fopen(types[world->map.type], "r");
    if (fd == NULL) {
        write(2, "fd returns NULL\n", 16);
    }
    while (getline(&buffer, &s, fd) != -1) {
        get_line_info(index, world, buffer);
        index++;
    }
    fclose(fd);
}
