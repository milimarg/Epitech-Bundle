/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_101_not_logged_in
*/

#include "client.h"

void resp_305_unknown_thread(client_t *client, char *message)
{
    char thread_uuid[MAX_UUID_LENGTH + 1] = {0};

    (void)client;
    if (sscanf(message, "[UUID:%37[^]]]", thread_uuid) == 1) {
        client_error_unknown_thread(thread_uuid);
    } else {
        dprintf(1, "Error while retrieving the received message\n");
    }
}
