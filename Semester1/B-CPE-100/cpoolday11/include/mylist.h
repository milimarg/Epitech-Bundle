/*
** EPITECH PROJECT, 2022
** CPOOL_Day11
** File description:
** mylist.h
*/

#ifndef MYLIST_H
    #define MYLIST_H
typedef struct linked_list {
    void *data;
    struct linked_list *next;
} linked_list_t;
#endif
