/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** loop
*/

#include "client.h"

bool cli_loop(client_t *client)
{
    while (!client->error && client->info.is_connected) {
        FD_ZERO(&client->readfds);
        FD_ZERO(&client->writefds);
        FD_SET(0, &client->readfds);
        FD_SET(client->server_fd, &client->readfds);
        if (select(FD_SETSIZE, &client->readfds, &client->writefds, NULL,
            NULL) == -1) {
            dprintf(1, "select error\n");
            return false;
        }
        handle_user_input(client);
    }
    if (client->error)
        return false;
    return true;
}
