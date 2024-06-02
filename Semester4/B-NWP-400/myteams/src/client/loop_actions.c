/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** loop_actions
*/

#include "client.h"

static void handle_n_server_response(client_t *client, int newline)
{
    char **args = split_my_args(client->server_response, "\r\n");
    int i = 0;

    memset(client->server_response, 0, BUFFER_SIZE);
    if (args == NULL)
        return;
    for (i = 0; i < newline; i++)
        handle_server_response(client, args[i]);
    for (; i < tab_len(args); i++)
        strcat(client->server_response, args[i]);
    free_tab(args);
}

static void handle_server_response_actions(client_t *client)
{
    int newline = count_char_number(client->server_response, '\n');

    if (newline == 0)
        return;
    FD_SET(client->server_fd, &client->writefds);
    if (!FD_ISSET(client->server_fd, &client->writefds))
        return;
    handle_n_server_response(client, newline);
    FD_CLR(client->server_fd, &client->writefds);
}

int read_server_response(client_t *client)
{
    int server_fd = client->server_fd;
    char buffer[BUFFER_SIZE] = {0};
    int bytes_received = read(server_fd, buffer, BUFFER_SIZE);

    if (bytes_received < 0)
        return -1;
    if (bytes_received == 0) {
        dprintf(1, "Connection closed by distant host.\n");
        return 1;
    }
    buffer[bytes_received] = '\0';
    strcat(client->server_response, buffer);
    handle_server_response_actions(client);
    return 0;
}

void write_to_server(client_t *client, char *str)
{
    if (dprintf(client->server_fd, "%s\r\n", str) < 0) {
        client->error = true;
        return;
    }
}

static void handle_n_user_command(client_t *client, int newline)
{
    char **args = split_my_args(client->command, "\r\n");
    int i = 0;

    memset(client->command, 0, BUFFER_SIZE);
    if (args == NULL)
        return;
    for (i = 0; i < newline; i++)
        write_to_server(client, args[i]);
    for (; i < tab_len(args); i++)
        strcat(client->command, args[i]);
    free_tab(args);
}

bool read_user_command(client_t *client)
{
    char buffer[BUFFER_SIZE] = {0};
    int bytes_received = read(0, buffer, BUFFER_SIZE);
    int newline = 0;

    if (bytes_received <= 0)
        return false;
    strcat(client->command, buffer);
    newline = count_char_number(client->command, '\n');
    if (newline == 0)
        return true;
    handle_n_user_command(client, newline);
    return true;
}

void handle_user_input(client_t *client)
{
    if (FD_ISSET(0, &client->readfds)) {
        if (!read_user_command(client)) {
            client->info.is_connected = false;
            return;
        }
    }
    if (FD_ISSET(client->server_fd, &client->readfds)) {
        switch (read_server_response(client)) {
            case -1:
                client->error = true;
                return;
            case 1:
                client->info.is_connected = false;
                return;
            default:
                break;
        }
    }
}
