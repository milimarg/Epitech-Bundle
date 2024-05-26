/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** file
*/

#include <stdlib.h>
#include <string.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"
#include "include/my.h"
#include <stdio.h>

int my_strlen(char const *str);

char number_finder(char *buffer, int *temp_infos)
{
    char ent_sym = 0;
    int temp_nb = 0;
    int power_shift = 1;
    int infos_shift = 0;

    for (int i = my_strlen(buffer); i >= 0; i--) {
        ent_sym = (buffer[i] == 'A' || buffer[i] == 'T') ? buffer[i] : ent_sym;
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            temp_nb += ((buffer[i] - '0') * power_shift);
            power_shift *= 10;
        }
        if ((buffer[i] == ' ' || buffer[i] == '\t')) {
            temp_infos[infos_shift++] = temp_nb;
            power_shift = 1;
            temp_nb = 0;
        }
    }
    return (ent_sym);
}

void parse_file(char *buffer, game_t *game, int *temp_infos)
{
    airplane_t *element = NULL;
    static int tower_index = 0;
    char ent_sym = number_finder(buffer, temp_infos);

    if (ent_sym == 'A') {
        element = malloc(sizeof(airplane_t));
        element->pos_start.x = temp_infos[5];
        element->pos_start.y = temp_infos[4];
        element->pos_end.x = temp_infos[3];
        element->pos_end.y = temp_infos[2];
        element->speed = temp_infos[1];
        element->seconds_to_go = temp_infos[0];
        element->next = game->airplane_list;
        element->prev = NULL;
        if (game->airplane_list != NULL)
            game->airplane_list->prev = element;
        game->airplane_list = element;
    }
    if (ent_sym == 'T') {
        game->towers[tower_index].pos.x = temp_infos[2];
        game->towers[tower_index].pos.y = temp_infos[1];
        game->towers[tower_index++].radius = temp_infos[0];
    }
}

int free_parsing(FILE *script, char *buffer, int *temp_infos)
{
    fclose(script);
    free(buffer);
    free(temp_infos);
    return (0);
}

int check_entity_name(char *buffer, game_t *game)
{
    if (buffer[0] == 'T')
        game->tower_nb++;
    if (buffer[0] != 'A' && buffer[0] != 'T')
        return (84);
    return (0);
}

int get_infos(game_t *game, char *filename)
{
    FILE *script = NULL;
    size_t size = 0;
    char *buffer = NULL;
    int *temp_infos = malloc(sizeof(int) * 6);

    script = fopen(filename, "r");
    if (script == NULL)
        return (84);
    while (getline(&buffer, &size, script) != -1)
        if (check_entity_name(buffer, game) == 84)
            return (84);
    fclose(script);
    script = fopen(filename, "r");
    game->airplane_list = NULL;
    game->towers = malloc(sizeof(tower_t) * game->tower_nb);
    while (getline(&buffer, &size, script) != -1)
        parse_file(buffer, game, temp_infos);
    free_parsing(script, buffer, temp_infos);
    return (0);
}
