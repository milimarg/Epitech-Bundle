/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** check_code.c
*/

#include "../include/include.h"

static int run_action(my_ftp *ftp, user_data *data, const char *keyword,
    const char *value)
{
    static const char *connection_names[] = {"USER", "PASS", "CWD",
    "CDUP", "PWD", "NOOP", "HELP", "QUIT", "PASV", "LIST", "DELE", "RETR", " ",
    NULL};
    static int (*connection_actions[])(my_ftp *, user_data *, const char *) = {
    &login, &pass, &cwd, &cdup, &pwd, &noop, &help, &quit, &pasv, &list,
    &dele, &retr, &dummy};

    for (int i = 0; connection_names[i] != NULL; i++) {
        if (!strcmp(connection_names[i], keyword)) {
            data->is_cdup = false;
            return connection_actions[i](ftp, data, value);
        }
    }
    dprintf(data->fd, COMMAND_NOT_FOUND);
    return 84;
}

int receive_code(my_ftp *ftp, user_data *data)
{
    char buffer[MAX_BUFFER_SIZE] = {0};
    char *keyword = NULL;
    char *value = NULL;
    ssize_t input = 0;

    if (data == NULL)
        return 1;
    input = read(data->fd, buffer, MAX_BUFFER_SIZE - 1);
    if (input <= 0)
        return 0;
    printf("size = %ld ; received = \"%s\"\n", input, buffer);
    keyword = malloc(sizeof(char) * input);
    value = malloc(sizeof(char) * input);
    keyword = memset(keyword, 0, input);
    value = memset(value, 0, input);
    sscanf(buffer, "%s %s", keyword, value);
    run_action(ftp, data, keyword, value);
    free(keyword);
    free(value);
    return 0;
}
