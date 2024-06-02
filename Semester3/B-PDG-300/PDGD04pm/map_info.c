/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** map_info.c
*/

#include <stddef.h>
#include "map.h"

unsigned int map_get_size(map_t *map)
{
    return list_get_size(map);
}

bool map_is_empty(map_t *map)
{
    return list_is_empty(map);
}

void *map_get_elem(map_t *map, void *key, key_comparator_t key_cmp)
{
    for (map_t *temp = map; temp != NULL; temp = temp->next) {
        if (!key_cmp(((pair_t *)temp->value)->key, key)) {
            return (((pair_t *)temp->value)->value);
        }
    }
    return (NULL);
}
