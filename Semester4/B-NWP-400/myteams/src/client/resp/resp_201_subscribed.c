/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_201_message_sent
*/

#include "client.h"

void resp_201_subscribed(client_t *client, char *message)
{
    char user_uuid[MAX_UUID_LENGTH + 1] = {0};
    char team_uuid[MAX_UUID_LENGTH + 1] = {0};

    (void)client;
    if (sscanf(message, "[%37[^/]/%37[^]]]",
        user_uuid, team_uuid) == 2) {
        client_print_subscribed(user_uuid, team_uuid);
    } else {
        dprintf(1, "Error while retrieving the received message\n");
    }
}
