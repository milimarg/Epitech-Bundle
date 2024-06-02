/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** help
*/

#include "server.h"

void get_help(char *args, client_t *client, server_t *server)
{
    (void)args;
    (void)server;
    dprintf(client->fd, HELP);
}
