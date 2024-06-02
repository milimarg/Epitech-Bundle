/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** cwd.c
*/

#include "../../include/include.h"

static bool check_if_directory_exist(const char *filepath)
{
    struct stat st;

    if (!filepath)
        return false;
    return stat(filepath, &st) != -1;
}

static int error_handling(user_data *data, char *value)
{
    if (!data->username) {
        dprintf(data->fd, CWD_NOT_LOGGED_IN);
        return 1;
    }
    if (!strcmp(data->user_path, "/") && !strcmp(basename(value), "..")) {
        dprintf(data->fd, "%s \"%s\".\n", data->is_cdup ? CDUP_OK : CWD_OK,
        data->user_path);
        return 0;
    }
    if (!strcmp(value, "."))
        return 0;
    return -1;
}

static char *realloc_strcat(char *dest, char *src)
{
    size_t len = strlen(dest) + strlen(src) + 1;
    char *new_dest = malloc(sizeof(char) * len);

    new_dest = memset(new_dest, 0, len);
    new_dest = strcat(new_dest, dest);
    new_dest = strcat(new_dest, src);
    free(dest);
    return new_dest;
}

static void concatenate_path(char *test, char **user, char **server)
{
    int user_len = 0;
    int server_len = 0;

    if (!strcmp(test, "..")) {
        if (strcmp(*user, "/") != 0) {
            *user = strdup(dirname(*user));
            *server = strdup(dirname(*server));
        }
        return;
    }
    user_len = strlen(*user);
    server_len = strlen(*server);
    if ((*user)[user_len - 1] != '/')
        *user = realloc_strcat(*user, "/");
    if ((*server)[server_len - 1] != '/')
        *server = realloc_strcat(*server, "/");
    *user = realloc_strcat(*user, test);
    *server = realloc_strcat(*server, test);
}

int cwd(my_ftp *ftp __attribute_maybe_unused__, user_data *data,
    const char *value)
{
    char *user = strdup(data->user_path);
    char *server = strdup(data->server_path);
    int error = error_handling(data, (char *)value);
    char *test = strtok((char *)value, "/");

    if (error != -1)
        return error;
    for (; test != NULL; test = strtok(NULL, "/")) {
        if (!strcmp(test, "."))
            continue;
        concatenate_path(test, &user, &server);
    }
    if (!check_if_directory_exist(server)) {
        dprintf(data->fd, CWD_FILE_NOT_FOUND);
        return 1;
    }
    data->user_path = user;
    data->server_path = server;
    return 0;
}
