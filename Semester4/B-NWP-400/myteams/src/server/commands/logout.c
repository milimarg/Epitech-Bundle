/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** quit
*/

#include "server.h"

static void close_client(server_t *server, client_t *client, client_t *prev)
{
    client->connected_users--;
    server->client_disconnect = true;
    if (client->connected_users > 0)
        return;
    if (prev)
        prev->next = client->next;
    else
        server->clients = client->next;
    close(client->fd);
    free(client);
}

static void send_logout(server_t *server, client_t *client)
{
    client_t *current = server->clients;

    while (current) {
        if (current->is_identified)
            dprintf(current->fd, LOGOUT,
            client->UUID, client->username);
        current = current->next;
    }
}

void handle_logout(char *args, client_t *client, server_t *server)
{
    client_t *current = server->clients;
    client_t *prev = NULL;

    (void)args;
    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    while (current) {
        if (client->fd == current->fd) {
            send_logout(server, client);
            dprintf(client->fd, DISCONNECTED);
            server_event_user_logged_out(client->UUID);
            close_client(server, current, prev);
            break;
        }
        prev = current;
        current = current->next;
    }
}
