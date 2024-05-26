/*
** EPITECH PROJECT, 2023
** B-MAT-200-STG-2-1-106bombyx-florent.guittre
** File description:
** mandelbrot.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <math.h>
#include <complex.h>

#define WIDTH 1920
#define HEIGHT 1080

static void iteration_to_color(long long iterations, long long *red, long long *green, long long *blue) {
    double t = (double)iterations / 100.0; 
    double r = 0.5 + 0.5 * sin(t * M_PI);
    double g = t;
    double b = 0.5 + 0.5 * cos(t * M_PI);

    *red = (long long)(r * 255);
    *green = (long long)(g * 255);
    *blue = (long long)(b * 255);
}

static long long diverge(complex double c) {
    complex double z = 0;

    for (long long iter = 0; iter < 100; iter++) {
        z = z*z + c;
        if (cabs(z) > 2.0)
            return (iter);
    }
    return (-1);
}

static void calc(sfUint8 *pixels, int width, int height, double zoom, double offsetX, double offsetY) {
    long long index = 0;
    double half_height = 0.0;
    complex double c = 0;
    long long diverge_return = 0;
    long long rgb[3] = {0};

    for (long long y = 0; y < height; y++) {
        for (long long x = 0; x < width; x++) {
            index = (y * width + x) * 4;
            half_height = height / 2;
            c = (x - offsetX - width / 2.0) / (half_height * zoom) + (y - offsetY - height / 2.0) / (half_height * zoom) * I;
            diverge_return = diverge(c);
            if (diverge_return == -1) {
                rgb[0] = 0;
                rgb[1] = 0;
                rgb[2] = 0;
            } else {
                iteration_to_color(diverge_return, &rgb[0], &rgb[1], &rgb[2]);
            }
            pixels[index] = rgb[0];
            pixels[index + 1] = rgb[1];
            pixels[index + 2] = rgb[2];
            pixels[index + 3] = 255;
        }
    }
}

static void display_animation(sfUint8 *pixels, sfTexture *texture, sfSprite *sprite, sfRenderWindow *window, double zoom, sfVector2i *pos)
{
    double half_height = HEIGHT / 2.0;
    double half_width = WIDTH / 2.0;
    double offset_x = (pos->x - half_width) / (zoom * half_width);
    double offset_y = (pos->y - half_height) / (zoom * half_height);

    calc(pixels, WIDTH, HEIGHT, zoom, offset_x, offset_y);
    sfTexture_updateFromPixels(texture, pixels, WIDTH, HEIGHT, 0, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

int main(void) {
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = NULL;
    sfTexture *texture = sfTexture_create(WIDTH, HEIGHT);
    sfUint8 *pixels = malloc(WIDTH * HEIGHT * 4 * sizeof(sfUint8));
    sfSprite *sprite = sfSprite_create();
    sfEvent event = {0};
    double zoom = 1.0;

    window = sfRenderWindow_create(mode, "Fractals: Mandelbrot set", sfResize | sfClose, NULL);
    display_animation(pixels, texture, sprite, window, 0.5, &(sfVector2i){WIDTH / 2, HEIGHT / 2});
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfEvtMouseButtonPressed) {
                sfVector2i pos = sfMouse_getPositionRenderWindow(window);
                display_animation(pixels, texture, sprite, window, zoom, &pos);
                zoom++;
            }
        }
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    free(pixels);
    sfRenderWindow_destroy(window);
    return (0);
}
