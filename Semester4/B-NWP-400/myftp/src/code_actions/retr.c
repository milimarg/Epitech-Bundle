/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** retr.c
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

static int run_command(int len, char *path, user_data *data)
{
    char *command = malloc(sizeof(char) * (len + 6));
    char *buffer = NULL;
    FILE *file = NULL;
    size_t len2 = 100;

    command = memset(command, 0, len + 6);
    command = strcat(command, "cat ");
    command = strcat(command, path);
    file = popen(command, "r");
    free(command);
    free(path);
    if (file == NULL)
        return 1;
    buffer = malloc(sizeof(char) * (len + 1));
    buffer = memset(buffer, 0, len);
    while (getline(&buffer, &len2, file) != -1)
        dprintf(data->pasv.accept_fd, "%s", buffer);
    pclose(file);
    free(buffer);
    return 0;
}

static int print_file(user_data *data, const char *value, int *len_,
    char **path_)
{
    int len_server_path = strlen(data->server_path);
    int len = len_server_path + strlen(value) + 6;
    char *path = malloc(sizeof(char) * len);
    struct stat s;

    path = memset(path, 0, len);
    path = strcat(path, data->server_path);
    if (data->server_path[len_server_path - 1] != '/')
        path = strcat(path, "/");
    path = strcat(path, value);
    *len_ = len;
    *path_ = path;
    return error_handling(path, data, &s);
}

static void forker(user_data *data, const char *value)
{
    static socklen_t len = sizeof(struct sockaddr_in);
    int len_ = 0;
    char *path_ = NULL;

    if (print_file(data, value, &len_, &path_) == 1)
        return;
    if (fork() == 0) {
        dprintf(data->fd, "%s\n", LIST_OPEN_CONNECTION);
        while (data->pasv.accept_fd == -1)
            data->pasv.accept_fd = accept(data->pasv.fd,
            (struct sockaddr *)&data->pasv.addr, &len);
        if (run_command(len_, path_, data) == 1)
            return;
        dprintf(data->fd, "%s\n", LIST_TRANSFER_COMPLETE);
        close(data->pasv.accept_fd);
        close(data->pasv.fd);
        data->pasv.accept_fd = -1;
        data->pasv.fd = -1;
        exit(0);
    }
}

int retr(my_ftp *ftp __attribute_maybe_unused__, user_data *data,
    const char *value)
{
    if (data->type != PASSIVE) {
        dprintf(data->fd, "%s\n", REJECTING_CONNECTION);
        return 1;
    }
    data->pasv.accept_fd = -1;
    forker(data, value);
    data->type = NONE;
    return 0;
}
