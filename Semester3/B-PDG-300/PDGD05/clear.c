/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** clear.c
*/

#include <string.h>
#include "string.h"

void clear(string_t *this)
{
    if (this == NULL) {
        return;
    }
    this->assign_c(this, "");
}
