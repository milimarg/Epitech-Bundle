/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** setup_database
*/

#include "server.h"
#include "../../libs/myteams/logging_server.h"

client_t *add_new_user(client_t *client)
{
    uuid_t uuid;

    uuid_generate(uuid);
    uuid_unparse(uuid, client->UUID);
    server_event_user_created(client->UUID, client->username);
    return client;
}

void add_user(server_t *server, client_t *client)
{
    char *current_uuid = check_if_username_existed(client->username, server);

    if (!current_uuid) {
        add_new_user(client);
    } else {
        strcpy(client->UUID, current_uuid);
    }
    return;
}
