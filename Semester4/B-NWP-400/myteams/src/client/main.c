/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** main
*/

#include "client.h"

static void print_usage(const char *program_name)
{
    dprintf(1,
        "USAGE: %s ip port\n"
        "\tip    is the server ip address on which the server socket listens\n"
        "\tport  is the port number on which the server socket listens\n",
    program_name);
}

static bool parse_args(char **argv, char **ip, int *server_port)
{
    int temp_server_port = 0;

    if (!argv || !ip || !server_port)
        return false;
    *ip = argv[1];
    temp_server_port = atoi(argv[2]);
    if (temp_server_port == 0)
        return false;
    *server_port = temp_server_port;
    return true;
}

int main(int argc, char **argv)
{
    char *ip = NULL;
    int server_port = 0;
    struct timeval timeout = {0};

    timeout.tv_usec = 1;
    select(0, NULL, NULL, NULL, &timeout);
    if (argc != 3) {
        print_usage(argv[0]);
        return 84;
    }
    if (!parse_args(argv, &ip, &server_port))
        return 84;
    if (!start_cli(ip, server_port))
        return 84;
    return 0;
}
