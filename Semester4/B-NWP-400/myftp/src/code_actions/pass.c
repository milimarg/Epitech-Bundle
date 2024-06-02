/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** pass.c
*/

#include "../../include/include.h"

static int error_handling(user_data *data)
{
    if (!data->username) {
        printf("Cannot accept password: no given login\n");
        dprintf(data->fd, PASSWORD_WITHOUT_USER);
        return 1;
    }
    if (data->is_auth) {
        printf("User \"%s\" already connected\n", data->username);
        dprintf(data->fd, PASSWORD_OK);
        return 1;
    }
    return 0;
}

int pass(my_ftp *ftp, user_data *data, const char *value)
{
    char *password = NULL;

    if (error_handling(data) == 1)
        return 1;
    password = get_password_by_login(ftp, data->username);
    if (data->username && password && !strcmp(password, value)) {
        data->server_path = strdup(ftp->trying_path);
        data->user_path = strdup("/");
        data->absolute_root = strdup(data->server_path);
        data->is_auth = true;
        dprintf(data->fd, PASSWORD_OK);
        printf("Logged in as %s\n", data->username);
        return 0;
    }
    free(data->username);
    data->username = NULL;
    printf("Password for login \"%s\" not right\n", data->username);
    dprintf(data->fd, NOT_LOGGED_IN);
    return 1;
}
