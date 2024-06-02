/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** find.c
*/

#include <string.h>
#include "string.h"

int find_c(const string_t *this, const char *str, size_t pos)
{
    size_t instance_len = this->length(this);
    char *ptr = NULL;
    size_t len = strlen(str);

    if (pos >= instance_len || str == NULL ||
        (str && len > instance_len) || pos > len - 1) {
        return -1;
    }
    ptr = strstr(&this->str[pos], str);
    return (ptr == NULL ? -1 : ptr - this->str);
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    if (this == NULL) {
        return -1;
    }
    return find_c(this, str->str, pos);
}
