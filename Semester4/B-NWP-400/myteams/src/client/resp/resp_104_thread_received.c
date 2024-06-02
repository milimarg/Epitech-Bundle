/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_201_message_sent
*/

#include "client.h"

void resp_104_thread_received(client_t *client, char *message)
{
    char team_uuid[MAX_UUID_LENGTH + 1] = {0};
    char thread_uuid[MAX_UUID_LENGTH + 1] = {0};
    char user_uuid[MAX_UUID_LENGTH + 1] = {0};
    char reply_body[MAX_BODY_LENGTH + 1] = {0};

    (void)client;
    if (sscanf(message, "[%37[^/]/%37[^/]/%37[^]]]: %512[^\4]\4", team_uuid,
        thread_uuid, user_uuid, reply_body) == 4) {
        client_event_thread_reply_received(team_uuid, thread_uuid, user_uuid,
            reply_body);
    } else {
        dprintf(1, "Error while retrieving the received message\n");
    }
}
