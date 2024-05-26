/*
** EPITECH PROJECT, 2023
** my_csfml_container
** File description:
** items_utils
*/

#include <unistd.h>
#include "container.h"
#include "../lib/lib.h"

int set_item_texture(items_list *new_item, my_textures_list *textures_list,
char *name_tag)
{
    sfTexture *texture_to_find = NULL;

    for (; textures_list != NULL; textures_list = textures_list->next) {
        if (!my_strcmp(name_tag, textures_list->name_tag)) {
            texture_to_find = textures_list->texture;
            break;
        }
    }
    if (texture_to_find == NULL) {
        write(2, "my_container: cannot find texture of item\n", 42);
        return (84);
    }
    new_item->sprite = sfSprite_create();
    sfSprite_setTexture(new_item->sprite, texture_to_find, sfTrue);
    return (0);
}

items_list *browse_through_list(int index, items_list **prev)
{
    for (int i = 0; i < index - 1; i++) {
        if ((*prev)->next->next == NULL) {
            write(2, "remove_node: OUT OF RANGE\n", 26);
            return (NULL);
        }
        *prev = (*prev)->next;
    }
}

items_list *remove_node(my_container *container, int index)
{
    items_list *head = container->items;
    items_list *prev = head;
    items_list *to_remove = NULL;

    if (head == NULL) {
        write(2, "remove_node: HEAD IS NULL\n", 26);
        return (NULL);
    }
    if (index == 0) {
        to_remove = container->items;
        container->items = container->items->next;
        return (to_remove);
    }
    if (browse_through_list(index, &prev) == NULL)
        return (NULL);
    to_remove = prev->next;
    prev->next = to_remove->next;
    return (to_remove);
}
