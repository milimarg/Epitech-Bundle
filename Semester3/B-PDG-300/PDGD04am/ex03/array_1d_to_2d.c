/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** array_1d_to_2d.c
*/

#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int index = 0;
    int **result = NULL;

    if (array == NULL || res == NULL) {
        return;
    }
    result = malloc(sizeof(int *) * height);
    for (size_t i = 0; i < height; i++) {
        result[i] = malloc(sizeof(int) * width);
        for (size_t j = 0; j < width; j++) {
            result[i][j] = array[index];
            index++;
        }
    }
    *res = result;
}

void array_2d_free(int **array, size_t height, size_t width)
{
    width += 0;
    for (size_t i = 0; i < height; i++) {
        free(array[i]);
    }
    free(array);
}
