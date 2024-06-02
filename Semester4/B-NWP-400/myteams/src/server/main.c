/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** main
*/

#include "server.h"

void print_usage(void)
{
    dprintf(1, "USAGE: ./myserver port\n\n");
    dprintf(1, "       port ");
    dprintf(1, "is the port number on which the server socket listens\n");
}

bool check_args(int argc, char **argv)
{
    if (argc == 2) {
        if (strcmp("-help", argv[1]) == 0) {
            print_usage();
            exit(0);
        }
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    server_t *server = malloc(sizeof(server_t));
    struct timeval timeout = {0};

    timeout.tv_usec = 1;
    select(0, NULL, NULL, NULL, &timeout);
    if (!check_args(argc, argv) || !setup_socket(server, argv[1])) {
        free(server);
        return 84;
    }
    if (!setup_server(server)) {
        free_all(server);
        return 84;
    }
    loop_server(server);
    free_all(server);
    return 0;
}
