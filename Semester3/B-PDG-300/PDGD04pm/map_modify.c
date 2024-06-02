/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04pm-florent.guittre
** File description:
** map_modify.c
*/

#include <stdlib.h>
#include "map.h"

bool map_add_elem(map_t **map_ptr, void *key, void *value,
    key_comparator_t key_cmp)
{
    pair_t *pair = NULL;

    if (map_ptr == NULL) {
        return false;
    }
    for (map_t *temp = *map_ptr; temp != NULL; temp = temp->next) {
        if (!key_cmp(((pair_t *)temp->value)->key, key)) {
            ((pair_t *)temp->value)->value = value;
            return true;
        }
    }
    pair = malloc(sizeof(pair_t));
    pair->key = key;
    pair->value = value;
    list_add_elem_at_front(map_ptr, pair);
    return true;
}

bool map_del_elem(map_t **map_ptr, void *key, key_comparator_t key_cmp)
{
    unsigned int i = 0;

    if (map_ptr == NULL) {
        return false;
    }
    for (map_t *temp = *map_ptr; temp != NULL; temp = temp->next) {
        if (!key_cmp(((pair_t *)temp->value)->key, key)) {
            free(temp->value);
            return list_del_elem_at_position(map_ptr, i);
        }
        i++;
    }
    return false;
}

void map_clear(map_t **map_ptr)
{
    if (map_ptr == NULL) {
        return;
    }
    for (map_t *delete = NULL; *map_ptr != NULL;) {
        delete = *map_ptr;
        *map_ptr = (*map_ptr)->next;
        free(delete->value);
        free(delete);
    }
}
