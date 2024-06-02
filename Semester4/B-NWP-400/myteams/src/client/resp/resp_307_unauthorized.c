/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_101_not_logged_in
*/

#include "client.h"

void resp_307_unauthorized(client_t *client, char *message)
{
    (void)client;
    (void)message;
    client_error_unauthorized();
}
