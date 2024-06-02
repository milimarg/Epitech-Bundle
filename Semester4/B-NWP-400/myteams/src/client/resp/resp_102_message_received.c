/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_202_message_received
*/

#include "client.h"

void resp_102_message_received(client_t *client, char *message)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char username[MAX_NAME_LENGTH + 1] = {0};
    char body[MAX_BODY_LENGTH + 1] = {0};

    (void)client;
    if (sscanf(message, "[%37[^/]/%32[^]]]: %512[^\4]\4", uuid, username, body)
        == 3) {
        client_event_private_message_received(uuid, body);
    } else {
        dprintf(1, "Error while retrieving the received message\n");
    }
}
