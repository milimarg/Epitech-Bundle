/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** insert.c
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *a = NULL;
    size_t instance_len = this->length(this);

    if (str == NULL) {
        return;
    }
    if (pos > instance_len) {
        this->append_c(this, str);
        return;
    }
    a = malloc(sizeof(char) * (instance_len + strlen(str) + 1));
    a[0] = 0;
    a = strncat(a, this->str, pos);
    a = strcat(a, str);
    a = strcat(a, &this->str[pos]);
    free((char *)this->str);
    this->str = a;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    if (this == NULL) {
        return;
    }
    insert_c(this, pos, str->str);
}
