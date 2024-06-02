/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** list.c
*/

#include "../../include/include.h"

static void print_ls(user_data *data, int sockfd, int pasvfd)
{
    int len = strlen(data->server_path) + 7;
    char *buffer = malloc(sizeof(char) * len);
    FILE *fd = NULL;
    size_t len2 = 100;

    printf("server_path = %s\n", data->server_path);
    buffer = memset(buffer, 0, len);
    buffer = strcat(buffer, "ls -l ");
    buffer = strcat(buffer, data->server_path);
    fd = popen(buffer, "r");
    free(buffer);
    if (fd == NULL)
        return;
    buffer = malloc(sizeof(char) * (len + 1));
    buffer = memset(buffer, 0, len);
    while (getline(&buffer, &len2, fd) != -1)
        dprintf(pasvfd, "%s", buffer);
    pclose(fd);
    dprintf(sockfd, "%s\n", LIST_TRANSFER_COMPLETE);
    free(buffer);
}

static void forker(user_data *data)
{
    static socklen_t len = sizeof(struct sockaddr_in);

    if (fork() == 0) {
        dprintf(data->fd, "%s\n", LIST_OPEN_CONNECTION);
        while (data->pasv.accept_fd == -1) {
            data->pasv.accept_fd = accept(data->pasv.fd,
            (struct sockaddr *)&data->pasv.addr, &len);
        }
        printf("yey connection!!! (pasv accept = %d)\n", data->pasv.accept_fd);
        print_ls(data, data->fd, data->pasv.accept_fd);
        close(data->pasv.accept_fd);
        close(data->pasv.fd);
        data->pasv.accept_fd = -1;
        data->pasv.fd = -1;
        exit(0);
    }
}

int list(my_ftp *ftp __attribute_maybe_unused__,
    user_data *data, const char *value __attribute_maybe_unused__)
{
    if (data->type != PASSIVE) {
        dprintf(data->fd, "%s\n", REJECTING_CONNECTION);
        return 1;
    }
    data->pasv.accept_fd = -1;
    forker(data);
    data->type = NONE;
    return 0;
}
