/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** handle_response
*/

#include "client.h"

void handle_server_response(client_t *client, char *str)
{
    char return_code[4] = {0};
    char message[BUFFER_SIZE] = {0};

    if (sscanf(str, "%3s %[^\r\n]",
        return_code, message) != 2) {
        dprintf(1, "Invalid server action");
        return;
    }
    dprintf(1, "server response: code=[%s], message=[%s]\n", return_code,
        message);
    for (size_t i = 0; response_handlers[i].handler != NULL; ++i) {
        if (strcmp(return_code, response_handlers[i].return_code) == 0) {
            response_handlers[i].handler(client, message);
            return;
        }
    }
    dprintf(1, "return code '%s' not handled", return_code);
    return;
}
