/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** dele.c
*/

#include "../../include/include.h"

static int error_handling(char *path, user_data *data, struct stat *s)
{
    if (stat(path, s) == -1) {
        dprintf(data->fd, "%s\n", DELE_FILE_NOT_FOUND);
        return 1;
    }
    if (access(path, W_OK) != 0) {
        dprintf(data->fd, "%s\n", DELE_FILE_NO_ACCESS);
        return 1;
    }
    return 0;
}

int dele(my_ftp *ftp __attribute_maybe_unused__,
    user_data *data, const char *value)
{
    int len_server_path = strlen(data->server_path);
    int len = len_server_path + strlen(value) + 5;
    char *path = malloc(sizeof(char) * len);
    char *command = malloc(sizeof(char) * (len + 5));
    struct stat s;

    path = memset(path, 0, len);
    path = strcat(path, data->server_path);
    if (data->server_path[len_server_path - 1] != '/')
        path = strcat(path, "/");
    path = strcat(path, value);
    if (error_handling(path, data, &s) == 1)
        return 1;
    command = memset(command, 0, len + 5);
    command = strcat(strcat(command, "rm "), path);
    system(command);
    free(command);
    free(path);
    dprintf(data->fd, "%s\n", DELE_OK);
    return 0;
}
