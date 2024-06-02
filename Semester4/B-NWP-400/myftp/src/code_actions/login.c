/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** login.c
*/

#include "../../include/include.h"

int login(my_ftp *ftp __attribute_maybe_unused__, user_data *data,
    const char *value)
{
    if (data->is_auth) {
        printf("User \"%s\" already connected\n", data->username);
        dprintf(data->fd, USER_ALREADY_LOGGED_IN);
        return 1;
    }
    if (!strcmp(value, "")) {
        printf("User is empty\n");
        dprintf(data->fd, USER_SYNTAX_ERROR_IN_ARGUMENTS);
        return 1;
    }
    printf("Trying to log in as \"%s\"\n", value);
    data->username = strdup(value);
    dprintf(data->fd, USER_OK);
    return 0;
}
