/*
** EPITECH PROJECT, 2023
** N4S
** File description:
** stop
*/

#include "../../include/my.h"

char *stop_simulation(void)
{
    size_t size = 0;
    char *buffer = NULL;
    char *read = NULL;

    dprintf(2, "STOP SIMULATION\n");
    dprintf(1, "STOP_SIMULATION\n");
    getline(&buffer, &size, stdin);
    read = strdup(buffer);
    check_my_buffer(read);
    return (read);
}
