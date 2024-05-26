/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-dante-noam.nedjar
** File description:
** my_str_to_word_array_destroy.c
*/

#include <stdlib.h>
#include "../include/structs.h"
#include "../include/solver.h"

int destroy_my_str_to_word_array(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
    return (0);
}
