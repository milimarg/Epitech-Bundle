/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** setup_server
*/

#include "server.h"

bool setup_opt(server_t *server)
{
    int opt = setsockopt(server->serv_socket, 1, 2, &server->opt, sizeof(int));

    if (opt < 0) {
        dprintf(1, "Failed to set the socket options\n");
        return false;
    }
    return true;
}

bool setup_socket(server_t *server, char *port)
{
    memset(server, 0, sizeof(server_t));
    server->opt = 0;
    server->len = sizeof(server->adress);
    server->PORT = atoi(port);
    server->messages = NULL;
    if (server->PORT <= 0) {
        dprintf(1, "Bad PORT\n");
        return false;
    }
    server->serv_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->serv_socket == -1) {
        dprintf(1, "Failed to create the socket\n");
        return false;
    }
    return setup_opt(server);
}

bool setup_server(server_t *server)
{
    int tmp = 0;

    memset(&server->adress, 0, sizeof(struct sockaddr_in));
    server->teams = NULL;
    server->teams_numbers = 0;
    server->adress.sin_family = AF_INET;
    server->adress.sin_port = htons(server->PORT);
    server->adress.sin_addr.s_addr = INADDR_ANY;
    tmp = bind(server->serv_socket, (struct sockaddr*) &server->adress,
        server->len);
    if (tmp < 0) {
        dprintf(1, "Failed to bind the socket\n");
        return false;
    }
    if (listen(server->serv_socket, BACKLOG) < 0) {
        dprintf(1, "Failed to listen the socket\n");
        return false;
    }
    server->clients = NULL;
    return true;
}
