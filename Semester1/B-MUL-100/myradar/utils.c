/*
** EPITECH PROJECT, 2023
** B-MUL-100-STG-1-1-myradar-florent.guittre
** File description:
** utils
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include "my_csfml/window/window.h"
#include "my_csfml/animation/animation.h"
#include "my_csfml/entity/entity.h"
#include "include/my_structs.h"

int free_airplane(airplane_t *airplane)
{
    destroy_entity(airplane->entity);
    sfRectangleShape_destroy(airplane->hitbox_square);
    free(airplane);
    return (0);
}

int remove_node(airplane_t **head, airplane_t *node_to_remove)
{
    //airplane_t *temp = NULL;
    //airplane_t *current = *head;

    //if (current == node_to_remove) {
    //    temp = *head;
    //    *head = (*head)->next;
    //    free_airplane(temp);
    //    return (0);
    //}
    //while (current->next != NULL) {
    //    if (current->next == node_to_remove) {
    //        temp = current->next;
    //        current->next = current->next->next;
    //        free_airplane(temp);
    //        return (0);
    //    } else
    //        current = current->next;
    //}
    if (*head == NULL || node_to_remove == NULL)
        return (1);
    if (node_to_remove->next != NULL)
        node_to_remove->next->prev = node_to_remove->prev;
    if (node_to_remove->prev != NULL)
        node_to_remove->prev->next = node_to_remove->next;
    free(node_to_remove);
    return (0);
}

void update_color(airplane_t *airplane)
{
    airplane->color.r = sin(airplane->color_int / 8) * 127 + 128;
    airplane->color.g = sin(airplane->color_int / 8 + 2) * 127 + 128;
    airplane->color.b = sin(airplane->color_int / 8 + 4) * 127 + 128;
    airplane->color_int = (airplane->color_int == 32) ? 0 :
    airplane->color_int + 1;
}
