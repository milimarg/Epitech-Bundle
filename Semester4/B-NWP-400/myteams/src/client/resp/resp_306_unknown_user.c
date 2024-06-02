/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_103_user_not_found
*/

#include "client.h"

void resp_306_unknown_user(client_t *client, char *message)
{
    char user_uuid[MAX_UUID_LENGTH + 1] = {0};

    (void)client;
    if (sscanf(message, "[UUID:%37[^]]]", user_uuid) == 1) {
        client_error_unknown_user(user_uuid);
    } else {
        dprintf(1, "Error while retrieving the received message\n");
    }
}
