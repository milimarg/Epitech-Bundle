/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_101_not_logged_in
*/

#include "client.h"

void resp_303_unknown_team(client_t *client, char *message)
{
    char team_uuid[MAX_UUID_LENGTH + 1] = {0};

    (void)client;
    if (sscanf(message, "[UUID:%37[^]]]", team_uuid) == 1) {
        client_error_unknown_team(team_uuid);
    } else {
        dprintf(1, "Error while retrieving the received message\n");
    }
}
