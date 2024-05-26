/*
** EPITECH PROJECT, 2022
** CPOOL_Day09
** File description:
** my_list_size.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/mylist.h"

int my_list_size(linked_list_t const *begin);

int dummy_res(linked_list_t **list, int argc, char **argv)
{
    linked_list_t *a;

    for (int i = 0; i < argc; i++) {
        a = malloc(sizeof(*a));
        a->data = argv[i];
        a->next = *list;
        *list = a;
    }
    return (0);
}

void my_rev_list(linked_list_t **begin)
{
    int LEN = my_list_size(*begin);
    char *temp[4];

    for (int i = 0; i < LEN; i++) {
        temp[i] = (*begin)->data;
        *begin = (*begin)->next;
    }
    for (int i = LEN - 1; i >= 0; i--) {
        //(*begin)->data = temp[i];
        //(*begin)->next = (*begin);
    }
}

int main(int argc, char **argv)
{
    linked_list_t *list = NULL;

    dummy_res(&list, argc, argv);
    my_rev_list(&list);
    return (0);
}
