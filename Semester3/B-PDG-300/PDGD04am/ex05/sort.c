/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** sort.c
*/

#include <stdlib.h>

static int int_compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void sort_array(void *array, size_t nmemb, size_t size,
    int(*compar)(const void *, const void *))
{
    qsort(array, nmemb, size, compar);
}

void sort_int_array(int *array, size_t nmemb)
{
    sort_array(array, nmemb, sizeof(int), int_compare);
}
