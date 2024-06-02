/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** copy.c
*/

#include <stddef.h>
#include <string.h>
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    if (this == NULL || (this && this->str == NULL)) {
        return 0;
    }
    if (n > (size_t)this->length(this) - 1 ||
        pos > (size_t)this->length(this) - 1) {
        return 0;
    }
    s = memcpy(s, &this->str[pos], n);
    return n;
}
