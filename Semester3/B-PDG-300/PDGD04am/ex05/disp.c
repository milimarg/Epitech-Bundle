/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** disp.c
*/

#include <stdio.h>

void disp_array(const void *array, size_t nmemb, size_t size,
    void (*print)(const void *))
{
    for (size_t i = 0; i < nmemb; i++) {
        print(array + size * i);
    }
}

void print_int(const void *a)
{
    printf("%d\n", *(int *)a);
}

void disp_int_array(const int *array, size_t nmemb)
{
    disp_array(array, nmemb, sizeof(int), print_int);
}
