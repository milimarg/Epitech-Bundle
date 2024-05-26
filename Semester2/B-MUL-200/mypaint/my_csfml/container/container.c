/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** container.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "container.h"

my_container *init_container(char type, char *display_name,
unsigned int max_items_nb)
{
    my_container *container = NULL;

    if (type != 'I' && type != 'C') {
        write(2, "container: error type for init_container\n", 42);
        return (container);
    }
    container = malloc(sizeof(my_container));
    container->type = type;
    container->display_name = display_name;
    container->current_items_nb = 0;
    container->max_items_nb = max_items_nb;
    container->items = NULL;
    return (container);
}

int destroy_container(my_container *container)
{
    items_list *temp = NULL;

    while (container->items != NULL) {
        temp = container->items;
        container->items = container->items->next;
        sfSprite_destroy(temp->sprite);
        free(temp);
    }
    free(container);
    return (0);
}
