/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** c_str.c
*/

#include <string.h>
#include "string.h"

const char *c_str(const string_t *this)
{
    return this == NULL ? NULL : this->str;
}
