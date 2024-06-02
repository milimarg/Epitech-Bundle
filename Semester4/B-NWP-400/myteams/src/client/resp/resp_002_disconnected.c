/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** connected
*/

#include "client.h"

void resp_002_disconnected(client_t *client, char *message)
{
    (void)message;
    client->info.is_connected = false;
}
