/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** loop_server
*/

#include "server.h"

bool handle_signal(bool getter, bool stat)
{
    static bool loop_enable = false;

    if (!getter)
        loop_enable = stat;
    return loop_enable;
}

void signal_handler(int signum)
{
    (void)signum;
    handle_signal(false, false);
}

void loop_server(server_t *server)
{
    handle_signal(false, true);
    signal(SIGINT, signal_handler);
    server->client_disconnect = false;
    while (handle_signal(true, true)) {
        FD_ZERO(&server->readfds);
        FD_SET(server->serv_socket, &server->readfds);
        if (!get_activity(server)) {
            dprintf(1, "Error get activity");
            break;
        }
        if (!add_client(server)) {
            dprintf(1, "Error add client");
            break;
        }
        get_client_input(server);
    }
    signal(SIGINT, SIG_DFL);
}
