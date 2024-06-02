/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** pwd.c
*/

#include "../../include/include.h"

int pwd(my_ftp *ftp __attribute_maybe_unused__, user_data *data,
    const char *value __attribute_maybe_unused__)
{
    char *path = !data->user_path ? "" : data->user_path;

    if (!data->username) {
        dprintf(data->fd, NOT_LOGGED_IN);
        return 1;
    }
    dprintf(data->fd, "%s \"%s\" is current directory.\n", PWD_OK, path);
    return 0;
}
