/*
** EPITECH PROJECT, 2023
** B-MUL-200-STG-2-1-mypaint-florent.guittre
** File description:
** sounds.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "../my_csfml/window/window.h"
#include "../my_csfml/button/button.h"
#include "../include/structs.h"
#include "../include/my.h"

void set_os_sounds(my_paint *p)
{
    char *files[] = {"./assets/start.ogg", "./assets/halt.ogg",
    "./assets/error.ogg"};

    p->os_sounds_number = 3;
    p->os_sounds = malloc(sizeof(sfSound *) * p->os_sounds_number);
    p->os_soundbuffers = malloc(sizeof(sfSoundBuffer *) * p->os_sounds_number);
    for (int i = 0; i < p->os_sounds_number; i++) {
        p->os_sounds[i] = sfSound_create();
        p->os_soundbuffers[i] = sfSoundBuffer_createFromFile(files[i]);
        sfSound_setBuffer(p->os_sounds[i], p->os_soundbuffers[i]);
    }
}

void destroy_sounds(my_paint *p)
{
    for (int i = 0; i < p->os_sounds_number; i++) {
        sfSoundBuffer_destroy(p->os_soundbuffers[i]);
        sfSound_destroy(p->os_sounds[i]);
    }
    free(p->os_soundbuffers);
    free(p->os_sounds);
}

void run_shutdown_sound(my_paint *p)
{
    sfTime playing_offset = {0};
    int has_begun = 0;

    sfSound_play(p->os_sounds[1]);
    do {
        playing_offset = sfSound_getPlayingOffset(p->os_sounds[1]);
        if (playing_offset.microseconds != 0)
            has_begun = 1;
    } while (!(has_begun && playing_offset.microseconds == 0));
}

void set_os_background(my_paint *p)
{
    int size = 72;
    sfIntRect rect = {p->w->width - size, 0, size, size};

    p->os_bg_texture = sfTexture_createFromFile("./assets/desktop.jpg", NULL);
    p->os_bg_sprite = sfSprite_create();
    sfSprite_setTexture(p->os_bg_sprite, p->os_bg_texture, sfTrue);
    p->desktop_button = init_buttons_array(1);
    p->desktop_button[0] = add_button(&rect, &sfTransparent, NULL, "");
    update_window_ratio(p->w);
}

void destroy_os_background(my_paint *p)
{
    sfTexture_destroy(p->os_bg_texture);
    sfSprite_destroy(p->os_bg_sprite);
    destroy_buttons_array(p->desktop_button);
}
