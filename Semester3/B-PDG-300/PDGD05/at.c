/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** at.c
*/

#include <string.h>
#include "string.h"

char at(const string_t *this, size_t pos)
{
    if (this == NULL || this->str == NULL) {
        return -1;
    }
    if (pos > strlen(this->str) - 1) {
        return -1;
    }
    return this->str[pos];
}
