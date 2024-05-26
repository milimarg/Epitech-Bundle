/*
** EPITECH PROJECT, 2022
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** main
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"
#include "include/my.h"
#include <stdio.h>

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->background = init_background("./assets/world_map.jpg", 1920, 1080);
    game->seconds = 0;
    game->tower_nb = 0;
    game->display_hitboxes = 1;
    game->display_sprites = 1;
    game->display_rainbow = 0;
    return (game);
}

int main(int argc, char **argv)
{
    my_window *window = NULL;
    game_t *game = init_game();
    int argv_parsing_output = argv_parsing(argc, argv);
    char *timer = malloc(sizeof(char) * 6);

    if (argv_parsing_output == 84 || argv_parsing_output == 0)
        return (argv_parsing_output);
    if (get_infos(game, argv[1]) == 84)
        return (84);
    window = create_window("MyRadar", 1920, 1080);
    set_offset_background(game->background, 0, 0);
    run_game(window, game, timer);
    destroy_background(game->background);
    frees(timer, game, window);
    return (0);
}
