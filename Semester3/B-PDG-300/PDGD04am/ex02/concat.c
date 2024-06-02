/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** concat.c
*/

#include <stdlib.h>
#include <string.h>
#include "concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    if (str1 == NULL || str2 == NULL || res == NULL) {
        return;
    }
    *res = malloc(sizeof(char) * strlen(str1) + strlen(str2) + 1);
    *res[0] = 0;
    *res = strcat(*res, str1);
    *res = strcat(*res, str2);
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}
