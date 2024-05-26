/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** util
*/

#include <unistd.h>
#include "include/my_struct.h"
#include "include/my.h"

void swap_elem(int *array, int index1, int index2)
{
    int temp = 0;

    temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void display_delimiter(elements_t *elements, int j)
{
    write(1,
    (elements->sizes[0] == elements->sizes[2] && !j && !elements->args[0])
    ? "\n" : " ", 1);
}

int shift_numbers_to_left(int j, elements_t *elements)
{
    for (; j > 0; j--) {
        ra_util(elements);
        display_delimiter(elements, j);
        if (elements->args[0])
            display_lists(elements);
    }
    return (j);
}

int shift_numbers_to_right(int j, elements_t *elements)
{
    for (; j < elements->sizes[0]; j++) {
        rra_util(elements);
        display_delimiter(elements, j);
        if (elements->args[0])
            display_lists(elements);
    }
    return (j);
}
