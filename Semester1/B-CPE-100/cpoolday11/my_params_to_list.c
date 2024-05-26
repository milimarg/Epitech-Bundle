/*
** EPITECH PROJECT, 2022
** CPOOL_Day09
** File description:
** my_params_to_list.c
*/

#include <stdlib.h>
#include "./include/my.h"
#include "./include/mylist.h"

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *list;
    linked_list_t *element = NULL;

    for (int i = 0; i < ac; i++) {
        element = malloc(sizeof(*element));
        element->data = av[i];
        element->next = list;
        list = element;
    }
    return element;
}
