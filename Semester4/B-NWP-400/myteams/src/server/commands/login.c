/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** user
*/

#include "server.h"

void check_login(char *username, client_t *client, server_t *server)
{
    client_t *current = server->clients;

    strcpy(client->username, username);
    add_user(server, client);
    client->is_identified = true;
    server_event_user_logged_in(client->UUID);
    while (current) {
        if (current->is_identified)
            dprintf(current->fd, LOGIN,
            client->UUID, client->username);
        current = current->next;
    }
}

void handle_login(char *args, client_t *client, server_t *server)
{
    char *username = NULL;

    if (client->is_identified) {
        dprintf(client->fd, ALREADY_LOGIN);
        return;
    }
    if (args == NULL || count_char_number(args, '\"') < 2) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    username = consume(args, "\"");
    if (!username) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    check_login(username, client, server);
}
