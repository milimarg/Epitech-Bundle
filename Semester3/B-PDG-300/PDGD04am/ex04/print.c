/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** print.c
*/

#include <stdio.h>
#include <string.h>
#include "print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_upper(const char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            printf("%c", str[i] - 32);
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

void print_42(const char *str)
{
    printf("42\n");
    str++;
}

void do_action(action_t action, const char *str)
{
    void (*functions[])(const char *str) = {
            &print_normal, &print_reverse, &print_upper, &print_42};

    for (action_t i = 0; i < PRINT_COUNT; i++) {
        if (action == i) {
            functions[i](str);
        }
    }
}
