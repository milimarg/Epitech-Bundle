/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** append.c
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void append_c(string_t *this, const char *ap)
{
    int len = 0;
    char *s = NULL;

    if (this == NULL || this->str == NULL || ap == NULL) {
        return;
    }
    len = strlen(this->str) + strlen(ap);
    s = malloc(sizeof(char) * len + 1);
    s[0] = 0;
    s = strcat(s, this->str);
    s = strcat(s, ap);
    free((char *)this->str);
    this->str = s;
}

void append_s(string_t *this, const string_t *ap)
{
    if (ap == NULL) {
        return;
    }
    append_c(this, ap->str);
}
