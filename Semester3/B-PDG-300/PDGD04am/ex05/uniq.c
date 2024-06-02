/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** uniq.c
*/

#include <string.h>

int inside_loop(size_t length_size[2], void *array, void *current_element,
    int (*compar)(const void *, const void *))
{
    for (size_t j = 0; j < length_size[0]; j++) {
        if (compar(array + length_size[1] * j, current_element)) {
            return 1;
        }
    }
    return 0;
}

size_t uniq_array(void *array, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *))
{
    size_t length = 1;
    void *current_element = 0;
    size_t length_size[2] = {0};

    if (nmemb == 0) {
        return (0);
    }
    for (size_t i = 1; i < nmemb; i++) {
        current_element = array + (size * i);
        length_size[0] = length;
        length_size[1] = size;
        if (!inside_loop(length_size, array, current_element, compar)) {
            memcpy((array + (size * length)), current_element, size);
            length++;
        }
    }
    return (length);
}

static int compare_int(const void *a, const void *b)
{
    return (*(int *)a == *(int *)b);
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    return uniq_array(array, nmemb, sizeof(int), compare_int);
}
