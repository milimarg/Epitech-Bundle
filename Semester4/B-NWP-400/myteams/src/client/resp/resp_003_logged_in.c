/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_102_logged_in
*/

#include "client.h"

void resp_003_logged_in(client_t *client, char *message)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char username[MAX_NAME_LENGTH + 1] = {0};

    if (sscanf(message, "[UUID:%37[^]]] [username:%32[^]]", uuid, username)
        == 2) {
        if (!client->info.is_logged_in) {
            snprintf(client->info.uuid, sizeof(client->info.uuid), "%s", uuid);
            snprintf(client->info.username, sizeof(client->info.username),
                "%s", username);
            client->info.is_logged_in = true;
        }
        client_event_logged_in(uuid, username);
    } else {
        dprintf(1, "Error parsing response.\n");
    }
}
