/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** length.c
*/

#include <string.h>
#include <stddef.h>
#include "string.h"

int length(const string_t *this)
{
    if (this == NULL || this->str == NULL) {
        return -1;
    }
    return strlen(this->str);
}
