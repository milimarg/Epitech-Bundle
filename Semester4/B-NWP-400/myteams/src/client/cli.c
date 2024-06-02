/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** cli
*/

#include "client.h"

static bool run_cli(client_t *client)
{
    if (select(FD_SETSIZE, &client->readfds, &client->writefds, NULL, NULL)
        == -1) {
        dprintf(1, "select error\n");
        return false;
    }
    read_server_response(client);
    return cli_loop(client);
}

// ? handle localhost -> replace by "127.0.0.1"?
static bool connect_to_server(client_t *client)
{
    client->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client->server_fd < 0)
        return false;
    memset(&client->server_addr, 0, sizeof(client->server_addr));
    client->server_addr.sin_family = AF_INET;
    client->server_addr.sin_port = htons(client->server_port);
    if (inet_pton(AF_INET, client->ip,
        &client->server_addr.sin_addr) <= 0)
        return false;
    if (connect(client->server_fd, (struct sockaddr *)&client->server_addr,
        sizeof(client->server_addr)) < 0)
        return false;
    FD_ZERO(&client->readfds);
    FD_ZERO(&client->writefds);
    FD_SET(0, &client->readfds);
    FD_SET(client->server_fd, &client->readfds);
    return true;
}

static void init_client(client_t *client, char *ip, int server_port)
{
    *client = (client_t){
        .command = {0},
        .server_response = {0},
        .ip = ip,
        .server_port = server_port,
        .server_fd = 0,
        .server_addr = {0},
        .readfds = {{0}},
        .writefds = {{0}},
        .error = false,
        .info = {
            .is_connected = false,
            .is_logged_in = false,
            .username = {0},
            .uuid = {0},
            .status = 0
        },
        .users = {{{0}}},
        .num_users = 0
    };
}

bool start_cli(char *ip, int server_port)
{
    client_t client = {0};

    init_client(&client, ip, server_port);
    if (!connect_to_server(&client)) {
        dprintf(1, "Connect to address %s: Connection refused\n",
            client.ip);
        return false;
    }
    dprintf(1, "Connected to the server at port [%d] and address [%s]\n",
        client.server_port, client.ip);
    if (!run_cli(&client))
        return false;
    return true;
}
