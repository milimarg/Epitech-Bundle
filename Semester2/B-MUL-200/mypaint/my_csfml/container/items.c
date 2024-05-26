/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** items
*/

#include <stdlib.h>
#include <unistd.h>
#include "container.h"

items_list *allocate_fill_new_item(item_infos *infos)
{
    items_list *new_item = malloc(sizeof(items_list));

    new_item->name_tag = infos->name_tag;
    new_item->display_name = infos->display_name;
    new_item->description = infos->description;
    new_item->effects = infos->effects;
    new_item->next = NULL;
    return (new_item);
}

int add_item(my_container *container, item_infos *infos,
my_textures_list *textures_list)
{
    items_list *new_item = NULL;
    items_list *head = container->items;

    if (container->current_items_nb == container->max_items_nb) {
        write(2, "my_container: cannot add item, inventory full\n", 46);
        return (84);
    }
    container->current_items_nb++;
    new_item = allocate_fill_new_item(infos);
    if (set_item_texture(new_item, textures_list, new_item->name_tag) == 84)
        return (84);
    if (container->items == NULL) {
        container->items = new_item;
        return (0);
    }
    while (head->next != NULL)
        head = head->next;
    head->next = new_item;
    return (0);
}

int remove_item(my_container *container, unsigned int index)
{
    items_list *to_remove = remove_node(container, index);

    if (to_remove == NULL)
        return (84);
    container->current_items_nb--;
    sfSprite_destroy(to_remove->sprite);
    free(to_remove);
    return (0);
}

int move_item_to_container(my_container *container_src, unsigned int index,
my_container *container_dest)
{
    items_list *to_move = remove_node(container_src, index);
    items_list *head = container_dest->items;
    items_list *current = container_dest->items;

    if (to_move == NULL)
        return (84);
    container_src->current_items_nb--;
    container_dest->current_items_nb++;
    to_move->next = NULL;
    if (head == NULL) {
        container_dest->items = to_move;
        return (0);
    }
    while (current->next != NULL)
        current = current->next;
    current->next = to_move;
    return (0);
}
