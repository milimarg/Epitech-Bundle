/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** cdup.c
*/

#include "../../include/include.h"

int cdup(my_ftp *ftp __attribute_maybe_unused__, user_data *data,
    const char *value __attribute_maybe_unused__)
{
    free(data->server_path);
    free(data->user_path);
    data->server_path = strdup(data->absolute_root);
    data->user_path = strdup("/");
    dprintf(data->fd, "%s\"/\"\n", CDUP_OK);
    return 0;
}
