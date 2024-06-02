/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myteams-noe.tritsch
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_
    #include "../libs/myteams/logging_client.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <sys/select.h>
    #include <sys/time.h>

    #define BUFFER_SIZE 4096
    #define MAX_CLIENTS 50
    #define MAX_NAME_LENGTH 32
    #define MAX_UUID_LENGTH 37
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

typedef struct client_info_s {
    char username[MAX_NAME_LENGTH + 1];
    char uuid[MAX_UUID_LENGTH + 1];
    bool is_connected;
    bool is_logged_in;
    int status;
} client_info_t;

typedef struct client_s {
    char command[BUFFER_SIZE];
    char server_response[BUFFER_SIZE];
    char *ip;
    int server_port;
    int server_fd;
    struct sockaddr_in server_addr;
    fd_set readfds;
    fd_set writefds;
    bool error;
    client_info_t info;
    client_info_t users[MAX_CLIENTS];
    int num_users;
} client_t;

bool start_cli(char *ip, int server_port);

void handle_user_input(client_t *client);
void handle_server_response(client_t *client, char *str);

bool cli_loop(client_t *client);

int read_server_response(client_t *client);

int count_char_number(char *str, char c);
char **split_my_args(char *str, char *rejected);
void free_tab(char **tab);
int tab_len(char **tab);;



typedef void (*response_handler_t)(client_t *client, char *message);

typedef struct response_type_s {
    char *return_code;
    response_handler_t handler;
} response_type_t;

void resp_001_connected(client_t *client, char *message);
void resp_002_disconnected(client_t *client, char *message);
void resp_003_logged_in(client_t *client, char *message);
void resp_004_logged_out(client_t *client, char *message);
void resp_005_help(client_t *client, char *message);

void resp_101_message_sent(client_t *client, char *message);
void resp_102_message_received(client_t *client, char *message);
void resp_103_thread_sent(client_t *client, char *message);
void resp_104_thread_received(client_t *client, char *message);
void resp_105_team_created(client_t *client, char *message);
void resp_106_channel_created(client_t *client, char *message);
void resp_107_thread_created(client_t *client, char *message);

void resp_201_subscribed(client_t *client, char *message);
void resp_202_unsubscribed(client_t *client, char *message);
void resp_203_team_created_successfully(client_t *client, char *message);
void resp_204_channel_created_successfully(client_t *client, char *message);
void resp_205_thread_created_successfully(client_t *client, char *message);
void resp_206_reply_created_successfully(client_t *client, char *message);
void resp_207_user_info(client_t *client, char *message);
void resp_208_list_users(client_t *client, char *message);
void resp_209_team_info(client_t *client, char *message);
void resp_210_list_teams(client_t *client, char *message);
void resp_211_channel_info(client_t *client, char *message);
void resp_212_list_channels(client_t *client, char *message);
void resp_213_thread_info(client_t *client, char *message);
void resp_214_list_threads(client_t *client, char *message);
void resp_215_list_replies(client_t *client, char *message);
void resp_216_list_messages(client_t *client, char *message);

void resp_301_already_logged_in(client_t *client, char *message);
void resp_302_not_logged_in(client_t *client, char *message);
void resp_303_unknown_team(client_t *client, char *message);
void resp_304_unknown_channel(client_t *client, char *message);
void resp_305_unknown_thread(client_t *client, char *message);
void resp_306_unknown_user(client_t *client, char *message);
void resp_307_unauthorized(client_t *client, char *message);
void resp_308_already_exist(client_t *client, char *message);
void resp_309_error(client_t *client, char *message);
void resp_310_syntax_error(client_t *client, char *message);
void resp_311_bad_command(client_t *client, char *message);

static const response_type_t response_handlers[] = {
    {"001", resp_001_connected},
    {"002", resp_002_disconnected},
    {"003", resp_003_logged_in},
    {"004", resp_004_logged_out},
    {"005", resp_005_help},

    {"101", resp_101_message_sent},
    {"102", resp_102_message_received},
    {"103", resp_103_thread_sent},
    {"104", resp_104_thread_received},
    {"105", resp_105_team_created},
    {"106", resp_106_channel_created},
    {"107", resp_107_thread_created},

    {"201", resp_201_subscribed},
    {"202", resp_202_unsubscribed},
    {"203", resp_203_team_created_successfully},
    {"204", resp_204_channel_created_successfully},
    {"205", resp_205_thread_created_successfully},
    {"206", resp_206_reply_created_successfully},
    {"207", resp_207_user_info},
    {"208", resp_208_list_users},
    {"209", resp_209_team_info},
    {"210", resp_210_list_teams},
    {"211", resp_211_channel_info},
    {"212", resp_212_list_channels},
    {"213", resp_213_thread_info},
    {"214", resp_214_list_threads},
    {"215", resp_215_list_replies},
    {"216", resp_216_list_messages},

    {"301", resp_301_already_logged_in},
    {"304", resp_302_not_logged_in},
    {"302", resp_303_unknown_team},
    {"303", resp_304_unknown_channel},
    {"305", resp_305_unknown_thread},
    {"306", resp_306_unknown_user},
    {"307", resp_307_unauthorized},
    {"308", resp_308_already_exist},
    {"309", resp_309_error},
    {"310", resp_310_syntax_error},
    {"311", resp_311_bad_command},

    {"", NULL}
};

#endif /* !CLIENT_H_ */
