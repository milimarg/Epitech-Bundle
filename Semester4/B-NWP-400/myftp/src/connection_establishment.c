/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** connection_establishment.c
*/

#include "../include/include.h"

int connection_establishment(user_data *data)
{
    if (data == NULL || data->is_connected)
        return 1;
    data->is_connected = true;
    dprintf(data->fd, SUCCESSFULLY_CONNECTION);
    return 0;
}
