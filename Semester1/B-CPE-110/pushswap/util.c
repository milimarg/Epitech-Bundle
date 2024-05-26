/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** util
*/

#include <unistd.h>
#include "include/my.h"
#include "include/my_macros.h"

void swap_elem(int *array, int index1, int index2)
{
    int temp = 0;

    temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

void display_delimiter(int *sizes, int j)
{
    if (sizes[0] == sizes[2] && j == 0)
        write(1, "\n", 1);
    else
        write(1, " ", 1);
}

int shift_numbers_to_left(int j, int *sizes, int *l_a, int *l_b)
{
    for (; j < sizes[0]; j++) {
        RRA;
        DELIM;
    }
    return (j);
}

int shift_numbers_to_right(int j, int *sizes, int *l_a, int *l_b)
{
    for (; j > 0; j--) {
        RA;
        DELIM;
    }
    return (j);
}
