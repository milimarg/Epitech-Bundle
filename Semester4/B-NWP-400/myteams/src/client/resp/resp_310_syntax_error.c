/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** resp_501_error
*/

#include "client.h"

void resp_310_syntax_error(client_t *client, char *message)
{
    (void)client;
    dprintf(1, "syntax error - message: [%s]", message);
}
