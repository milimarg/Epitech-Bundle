/*
** EPITECH PROJECT, 2022
** CPOOL_Day09
** File description:
** my_list_size.c
*/

#include <stddef.h>
#include "./include/my.h"
#include "./include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    linked_list_t *test = begin;
    int len = 0;

    while (test != NULL) {
        len++;
        test = test->next;
    }
    return (len);
}
