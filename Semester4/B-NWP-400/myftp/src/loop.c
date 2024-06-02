/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** loop.c
*/

#include "../include/include.h"

// check client function
//printf("message successfully sent to %d\n", data->fd);
//close(temp_client.fd);
//ftp->data[i].fd = 0;
//connected_number--;

// loop function
// status == 2 -> TODO: set this only if server have to be stopped

void set_socket_fds(my_ftp *ftp, int *max_socket)
{
    user_data temp_client = {0};

    FD_ZERO(&ftp->readfds);
    FD_SET(ftp->server_socket, &ftp->readfds);
    *max_socket = ftp->server_socket;
    for (int i = 0; i < ftp->current_clients_number; i++) {
        temp_client = ftp->data[i];
        if (temp_client.fd <= 0)
            continue;
        FD_SET(temp_client.fd, &ftp->readfds);
        if (temp_client.fd > *max_socket)
            *max_socket = temp_client.fd;
    }
}

int handle_accept(my_ftp *ftp)
{
    int accept_status = 0;
    static socklen_t accept_len = sizeof(struct sockaddr_in);

    accept_status = accept(ftp->server_socket, ((struct sockaddr *)&ftp->addr),
        &accept_len);
    if (accept_status == -1) {
        printf("error accept_status\n");
        return 1;
    }
    printf("new socket connection from %d\n", accept_status);
    ftp->current_connected++;
    for (int i = 0; i < ftp->current_clients_number; i++) {
        if (ftp->data[i].fd == 0) {
            ftp->data[i].fd = accept_status;
            connection_establishment(&ftp->data[i]);
            break;
        }
    }
    return 0;
}

int check_client_connection(my_ftp *ftp, user_data *data)
{
    if (data->fd <= 0 || !FD_ISSET(data->fd, &ftp->readfds))
        return 1;
    if (receive_code(ftp, data) == 2)
        return 2;
    return 0;
}

int loop(my_ftp *ftp)
{
    int activity = 0;
    int max_socket = 0;
    int status = 0;

    set_socket_fds(ftp, &max_socket);
    activity = select(max_socket + 1, &ftp->readfds, NULL, NULL, NULL);
    if (activity < 0) {
        printf("activity error\n");
        return 1;
    }
    if (FD_ISSET(ftp->server_socket, &ftp->readfds))
        handle_accept(ftp);
    for (int i = 0; i < ftp->current_clients_number; i++) {
        status = check_client_connection(ftp, &ftp->data[i]);
        if (status == 1)
            continue;
        if (status == 2)
            return 2;
    }
    return 0;
}
