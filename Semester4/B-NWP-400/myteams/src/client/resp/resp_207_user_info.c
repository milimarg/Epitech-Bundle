/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_203_team_created_successfully
*/

#include "client.h"

void resp_207_user_info(client_t *client, char *message)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char username[MAX_NAME_LENGTH + 1] = {0};
    int status = 0;

    (void)client;
    if (sscanf(message, "[UUID:%37[^,], username:%32[^,], status:%d]",
        uuid, username, &status) == 3) {
        client_print_user(uuid, username, status);
    } else {
        dprintf(1, "Error while retrieving the received message\n");
    }
}
