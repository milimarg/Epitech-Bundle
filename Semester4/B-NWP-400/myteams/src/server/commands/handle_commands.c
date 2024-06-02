/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** handle_commands
*/

#include "server.h"

struct commands {
    const char *command;
    void (*function)(char *args, client_t *client, server_t *server);
};

void handle_commands(char *command, char *substring,
    client_t *client, server_t *server)
{
    int tab_number = 14;
    struct commands tab[] = {
        { "/help", get_help }, { "/login", handle_login },
        { "/logout", handle_logout }, { "/users", show_users },
        { "/user", get_user }, { "/send", send_message },
        { "/messages", show_messages }, { "/use", use_command},
        { "/list", handle_list }, { "/info", handle_info },
        { "/create", handle_create }, { "/subscribe", subscribe },
        { "/unsubscribe", unsubscribe }, { "/subscribed", subscribed },
    };

    for (int i = 0; i < tab_number; i++) {
        if (strcmp(tab[i].command, command) == 0) {
            tab[i].function(substring, client, server);
            return;
        }
    }
    dprintf(client->fd, BAD_COMMAND);
    return;
}
