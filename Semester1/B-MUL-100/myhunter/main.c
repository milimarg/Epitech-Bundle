/*
** EPITECH PROJECT, 2022
** MyHunter
** File description:
** main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "./my-csfml/csfml_protos.h"
#include "./include/myhunter_structs.h"
#include "./include/myhunter_protos.h"

int display_help_menu(void)
{
    char *str = "Usage: ./my_hunter [options]\n"
                "MyHunter is a special clone of the original DuckHunt.\n"
                "Ducks are now going to heaven!\n"
                "Options:\n    -h    Display that help message.\n"
                "Inputs of the game:\n"
                "    left-click: shoot ducks\n"
                "    esc:        quit\n"
                "    1-3:        switch between backgrounds\n"
                "    m:          mute/demute the game (hold for 0.25s)\n"
                "Extra: Ducks' sprites are chosen randomly whilst spawning "
                "them at start!\n";

    write(1, str, 400);
    return (0);
}

int destroyer(game_i_t *game_i, window_t *window)
{
    free(window->target);
    destroy_digit_sprites(game_i);
    sfClock_destroy(window->clock);
    sfRenderWindow_destroy(window->renderer);
    return (0);
}

int main(int argc, char **argv)
{
    window_t window = {0};
    game_i_t game_i = {0};
    entity_t *entities = {0};

    if (argc != 2) {
        srand(time(NULL));
        window = create_window("Duckhunt: Road To Heaven");
        game_i = init_game_infos();
        game_i.mute->is_sound_muted = 0;
        init_score_digits(&game_i);
        entities = malloc(sizeof(entity_t) * game_i.entity_nb);
        if (run_game(&window, &game_i, entities) == 84)
            return (84);
        destroyer(&game_i, &window);
    }
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        display_help_menu();
    return (0);
}
