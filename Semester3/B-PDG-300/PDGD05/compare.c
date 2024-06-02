/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** compare.c
*/

#include <stddef.h>
#include <string.h>
#include "string.h"

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL || this->str == NULL || str == NULL) {
        return -1;
    }
    return strcmp(this->str, str);
}

int compare_s(const string_t *this, const string_t *str)
{
    if (str == NULL) {
        return -1;
    }
    return compare_c(this, str->str);
}
