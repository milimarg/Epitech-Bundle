/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** user
*/

#include "../../../include/server.h"

char *check_if_username_existed(char *username, server_t *server)
{
    client_t *current = server->clients;

    while (current) {
        if (!current->is_identified) {
            current = current->next;
            continue;
        }
        if (strcmp(current->username, username) == 0)
            return current->UUID;
        current = current->next;
    }
    return NULL;
}

client_t *check_if_uuid_existed(char *UUID, server_t *server)
{
    client_t *current = server->clients;

    while (current) {
        if (!current->is_identified) {
            current = current->next;
            continue;
        }
        if (strcmp(current->UUID, UUID) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void show_users(char *args __attribute_maybe_unused__, client_t *client,
    server_t *server)
{
    client_t *current = server->clients;

    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    dprintf(client->fd, USERS, get_number_of_users(server));
    while (current) {
        dprintf(current->fd, "\1UUID:%s, username:%s, status:%d\4",
        current->UUID, current->username, 1);
        current = current->next;
    }
    dprintf(client->fd, "]\r\n");
}

void show_one_user(char *uuid, client_t *client, server_t *server)
{
    client_t *current = check_if_uuid_existed(uuid, server);

    if (!current) {
        dprintf(client->fd, UNKNOW_USER, uuid);
        return;
    }
    dprintf(client->fd, USER,
    current->UUID, current->username, current->is_identified);
}

void get_user(char *args, client_t *client, server_t *server)
{
    char *uuid = NULL;

    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    if (args == NULL || count_char_number(args, '\"') < 2) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    uuid = consume(args, "\"");
    if (!uuid) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    show_one_user(uuid, client, server);
}
