/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_203_team_created_successfully
*/

#include "client.h"

void resp_209_team_info(client_t *client, char *message)
{
    char uuid[MAX_UUID_LENGTH + 1] = {0};
    char name[MAX_NAME_LENGTH + 1] = {0};
    char description[MAX_DESCRIPTION_LENGTH + 1] = {0};

    (void)client;
    if (sscanf(message, "[UUID:%37[^,], name:%32[^,], description:%255[^]]]",
        uuid, name, description) == 3) {
        client_print_team(uuid, name, description);
    } else {
        dprintf(1, "Error while retrieving the received message\n");
    }
}
