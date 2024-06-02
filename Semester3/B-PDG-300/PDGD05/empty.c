/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** empty.c
*/

#include <string.h>
#include "string.h"

int empty(const string_t *this)
{
    if (this == NULL || (this && this->str == NULL)) {
        return 0;
    }
    return this->str[0] == '\0';
}
