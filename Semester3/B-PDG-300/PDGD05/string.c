/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD05-florent.guittre
** File description:
** string.c
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

static void set_actions(string_t *this)
{
    this->assign_c = &assign_c;
    this->assign_s = &assign_s;
    this->append_c = &append_c;
    this->append_s = &append_s;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_c = &compare_c;
    this->compare_s = &compare_s;
}

void string_init(string_t *this, const char *s)
{
    int len = 0;

    if (this == NULL)
        return;
    if (s != NULL) {
        len = strlen(s);
        this->str = malloc(len + 1);
        this->str = strcpy((char *)this->str, s);
    } else {
        this->str = NULL;
    }
    set_actions(this);
}

void string_destroy(string_t *this)
{
    if (this == NULL) {
        return;
    }
    free((char *)this->str);
    this->str = NULL;
}
