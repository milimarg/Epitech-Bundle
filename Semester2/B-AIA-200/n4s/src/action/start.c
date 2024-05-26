/*
** EPITECH PROJECT, 2023
** N4S
** File description:
** start
*/

#include "../../include/my.h"

char *start_simulation(void)
{
    size_t size = 0;
    char *buffer = NULL;
    char *read = NULL;

    dprintf(2, "START SIMULATION\n");
    dprintf(1, "START_SIMULATION\n");
    getline(&buffer, &size, stdin);
    read = strdup(buffer);
    check_my_buffer(read);
    return (read);
}
