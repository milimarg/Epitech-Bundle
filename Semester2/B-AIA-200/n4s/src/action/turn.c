/*
** EPITECH PROJECT, 2023
** N4S
** File description:
** turn
*/

#include "../../include/my.h"

char *car_turn(float value)
{
    size_t size = 0;
    char *buffer = NULL;
    char *read = NULL;

    dprintf(1, "WHEELS_DIR:%f\n", value);
    getline(&buffer, &size, stdin);
    read = strdup(buffer);
    check_my_buffer(read);
    return (read);
}
