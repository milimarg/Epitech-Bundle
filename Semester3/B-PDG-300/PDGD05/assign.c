/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** assign.c
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void assign_c(string_t *this, const char *s)
{
    if (this == NULL) {
        return;
    }
    free((char *)this->str);
    this->str = strdup(s);
}

void assign_s(string_t *this, const string_t *str)
{
    if (this == NULL) {
        return;
    }
    assign_c(this, str->str);
}
