/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** to_int.c
*/

#include <stdlib.h>
#include "string.h"

int to_int(const string_t *this)
{
    if (this == NULL || (this && this->str == NULL)) {
        return -1;
    }
    return atoi(this->str);
}
