/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_102_logged_out
*/

#include "client.h"

void resp_004_logged_out(client_t *client, char *message)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char username[MAX_NAME_LENGTH + 1] = {0};

    if (sscanf(message, "[UUID:%37[^]]] [username:%32[^]]", uuid, username)
        == 2) {
        if (strcmp(uuid, client->info.uuid) == 0)
            client->info.is_logged_in = false;
        client_event_logged_out(uuid, username);
    } else {
        dprintf(1, "Error parsing response.\n");
    }
}
