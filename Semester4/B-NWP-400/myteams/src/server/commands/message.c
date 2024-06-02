/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** message
*/

#include "server.h"

static messages_t *new_message(char *sender, char *receiver, char *message)
{
    messages_t *new_message = malloc(sizeof(messages_t));

    new_message->sender_uuid = strdup(sender);
    new_message->receiver_uuid = strdup(receiver);
    new_message->timestamp = time(NULL);
    new_message->message = strdup(message);
    new_message->next = NULL;
    return new_message;
}

static void send_to_all_receiver(char *uuid, char *message,
    client_t *sender, server_t *server)
{
    client_t *current = server->clients;

    while (current) {
        if (current->fd <= 0) {
            current = current->next;
            continue;
        }
        if (strcmp(current->UUID, uuid) == 0) {
            dprintf(current->fd, MESSAGE_RECEIVED,
            sender->UUID, sender->username, message);
        }
        current = current->next;
    }
}

void send_all_words(char *uuid, char *message, client_t *sender,
    server_t *server)
{
    client_t *receiver = check_if_uuid_existed(uuid, server);
    messages_t *messages = server->messages;

    if (!receiver) {
        dprintf(sender->fd, UNKNOW_USER, uuid);
        return;
    }
    send_to_all_receiver(receiver->UUID, message, sender, server);
    dprintf(sender->fd, MESSAGE_SEND,
    receiver->UUID, receiver->username, message);
    server_event_private_message_sended(sender->UUID, uuid, message);
    if (!server->messages)
        server->messages = new_message(sender->UUID, uuid, message);
    else {
        while (messages->next)
            messages = messages->next;
        messages->next = new_message(sender->UUID, uuid, message);
    }
}

void send_message(char *args, client_t *client, server_t *server)
{
    char *uuid = NULL;
    char *message = NULL;

    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    if (args == NULL || count_char_number(args, '\"') < 4) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    uuid = consume(args, "\"");
    message = consume(NULL, "\"");
    if (!uuid || !message) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    send_all_words(uuid, message, client, server);
}

void show_content(client_t *client, char *uuid, server_t *server)
{
    messages_t *messages = server->messages;

    dprintf(client->fd, MESSAGES, uuid);
    while (messages) {
        if (!strcmp(messages->receiver_uuid, uuid) &&
            !strcmp(messages->sender_uuid, client->UUID)) {
            dprintf(client->fd, "\1UUID:%s, timestamp:%ld, messages: %s\4",
            client->UUID, messages->timestamp, messages->message);
        }
        if (!strcmp(messages->receiver_uuid, client->UUID) &&
            !strcmp(messages->sender_uuid, uuid)) {
            dprintf(client->fd, "\1UUID:%s, timestamp:%ld, messages: %s\4",
            messages->sender_uuid, messages->timestamp, messages->message);
        }
        messages = messages->next;
    }
    dprintf(client->fd, "]\r\n");
}

void show_messages(char *args, client_t *client, server_t *server)
{
    char *uuid = NULL;

    if (!client->is_identified) {
        dprintf(client->fd, NOT_LOGIN);
        return;
    }
    if (args == NULL || count_char_number(args, '\"') < 2) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    uuid = consume(args, "\"");
    if (!uuid) {
        dprintf(client->fd, SYNTAX_ERROR);
        return;
    }
    if (!check_if_uuid_existed(uuid, server)) {
        dprintf(client->fd, UNKNOW_USER, uuid);
        return;
    }
    show_content(client, uuid, server);
}
