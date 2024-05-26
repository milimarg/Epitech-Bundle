/*
** EPITECH PROJECT, 2023
** N4S
** File description:
** get_info_lidar
*/

#include "../../include/my.h"

char *get_info_lidar(void)
{
    size_t size = 0;
    char *buffer = NULL;
    char *read = NULL;

    dprintf(1, "GET_INFO_LIDAR\n");
    getline(&buffer, &size, stdin);
    read = strdup(buffer);
    check_my_buffer(read);
    return (read);
}
