/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** init.c
*/

#include "../include/include.h"

static int error_handling(my_ftp *ftp)
{
    if (bind(ftp->server_socket, ((struct sockaddr *)&ftp->addr),
        sizeof(ftp->addr)) == -1) {
        printf("Connection has failed.\n");
        return 1;
    }
    if (listen(ftp->server_socket, 10) != 0) {
        printf("Listen error\n");
        return 1;
    }
    return 0;
}

static void get_loopback_ip(my_ftp *ftp)
{
    char buffer[INET_ADDRSTRLEN] = {0};

    inet_ntop(AF_INET, &(ftp->addr.sin_addr), buffer, INET_ADDRSTRLEN);
    printf("test = %s\n", buffer);
    sscanf(buffer, "%d.%d.%d.%d", (int *)&ftp->ip[0], (int *)&ftp->ip[1],
    (int *)&ftp->ip[2], (int *)&ftp->ip[3]);
    ftp->addr.sin_addr.s_addr = INADDR_ANY;
}

int init_ftp(my_ftp *ftp, uint16_t port, char *path)
{
    ftp->server_socket = socket(AF_INET, SOCK_STREAM, 0);
    ftp->addr.sin_family = AF_INET;
    ftp->addr.sin_port = htons(port);
    ftp->addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if (error_handling(ftp) == 1)
        return 1;
    get_loopback_ip(ftp);
    printf("MyFTP: Initialization\n");
    ftp->data = malloc(sizeof(user_data) * ftp->current_clients_number);
    ftp->current_connected = 0;
    ftp->trying_path = malloc(sizeof(char) * MAX_PATH_SIZE);
    ftp->trying_path = memset(ftp->trying_path, 0, MAX_PATH_SIZE - 1);
    ftp->trying_path = realpath(path, ftp->trying_path);
    ftp->users = NULL;
    add_user(ftp, "Anonymous", "");
    add_user(ftp, "anonymous", "anonymous@example.com");
    return 0;
}

void init_clients(my_ftp *ftp)
{
    for (int i = 0; i < ftp->current_clients_number; i++) {
        ftp->data[i].is_connected = false;
        ftp->data[i].is_auth = false;
        ftp->data[i].username = NULL;
        ftp->data[i].fd = 0;
        ftp->data[i].user_path = NULL;
        ftp->data[i].server_path = NULL;
        ftp->data[i].pasv = (pasv_t){.port = -1, .fd = -1, .accept_fd = -1};
        ftp->data[i].type = NONE;
    }
}
