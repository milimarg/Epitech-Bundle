/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** handle_server
*/

#include "server.h"

static void handle_buffer_management(char *buffer, client_t *client,
    server_t *server)
{
    char *command = strtok(buffer, " \t");
    char *substring = strtok(NULL, "");

    if (command == NULL) {
        dprintf(client->fd, BAD_COMMAND);
        return;
    }
    handle_commands(command, substring, client, server);
}

static void handle_n_command(client_t *client, server_t *server, int newline)
{
    char **args = split_my_args(client->command, "\r\n");
    int i = 0;

    memset(client->command, 0, MAX_BUFFER);
    if (args == NULL) {
        dprintf(client->fd, BAD_COMMAND);
        free_tab(args);
        return;
    }
    for (i = 0; i < newline; i++) {
        if (client->fd > 0)
            handle_buffer_management(args[i], client, server);
        if (server->client_disconnect) {
            free_tab(args);
            return;
        }
    }
    for (; i < tab_len(args); i++)
        strcat(client->command, args[i]);
    free_tab(args);
}

static void read_client(client_t *client, server_t *server)
{
    char buffer[MAX_BUFFER] = {0};
    int nb = 0;
    int newline = 0;

    nb = read(client->fd, &buffer, MAX_BUFFER);
    if (nb <= 0)
        return;
    buffer[nb] = '\0';
    strcat(client->command, buffer);
    newline = count_char_number(client->command, '\n');
    if (newline == 0)
        return;
    handle_n_command(client, server, newline);
}

void get_client_input(server_t *server)
{
    int fd = 0;
    client_t *current = server->clients;

    while (current) {
        fd = current->fd;
        if (fd > 0 && FD_ISSET(fd, &server->readfds)) {
            read_client(current, server);
        }
        if (server->client_disconnect)
            break;
        current = current->next;
    }
    server->client_disconnect = false;
}

bool get_activity(server_t *server)
{
    int max_sd = server->serv_socket;
    int activity = 0;
    client_t *current = server->clients;

    while (current) {
        if (current->fd <= 0) {
            current = current->next;
            continue;
        }
        FD_SET(current->fd, &server->readfds);
        if (current->fd > max_sd)
            max_sd = current->fd;
        current = current->next;
    }
    activity = select(max_sd + 1, &server->readfds,
    &server->writefds, NULL, NULL);
    if (activity < 0)
        return false;
    return true;
}

static client_t *create_client(int fd)
{
    client_t *new_client = malloc(sizeof(client_t));

    new_client->fd = fd;
    new_client->is_identified = false;
    memset(new_client->username, 0, MAX_NAME_LENGTH + 1);
    memset(new_client->UUID, 0, MAX_UUID_LENGTH + 1);
    new_client->connected_users = 1;
    new_client->team_uuid = NULL;
    new_client->channel_uuid = NULL;
    new_client->thread_uuid = NULL;
    memset(new_client->command, 0, MAX_BUFFER);
    new_client->next = NULL;
    new_client->subscribed_teams = NULL;
    return new_client;
}

static void add_new_client(server_t *server, int fd)
{
    client_t *current = server->clients;

    if (!current) {
        server->clients = create_client(fd);
        return;
    }
    while (current->next)
        current = current->next;
    current->next = create_client(fd);
}

bool add_client(server_t *server)
{
    struct sockaddr *socket_adress = (struct sockaddr *) &server->adress;
    socklen_t *len = (socklen_t *)&server->len;

    if (!FD_ISSET(server->serv_socket, &server->readfds))
        return true;
    server->new_socket = accept(server->serv_socket, socket_adress, len);
    if (server->new_socket < 0)
        return false;
    add_new_client(server, server->new_socket);
    dprintf(server->new_socket, CONNECTED);
    return true;
}
