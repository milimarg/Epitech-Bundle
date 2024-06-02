/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myserver-noe.tritsch
** File description:
** messages
*/

#ifndef MESSAGES_H_
    #define MESSAGES_H_

    // 000 -> connection/disconnection
    #define CONNECTED "001 connected to server.\r\n"
    // NONE
    #define DISCONNECTED "002 Service closing control connection.\r\n"
    // NONE
    #define LOGIN "003 [UUID:%s] [username:%s]\r\n"
    // client_event_logged_in
    #define LOGOUT "004 [UUID:%s] [username:%s]\r\n"
    // client_event_logged_out
    #define HELP "005 Help message.\r\n"
    // NONE

    // 100 -> user event for every client
    #define MESSAGE_SEND "101 [%s/%s]: %s\r\n"
    // NONE
    #define MESSAGE_RECEIVED "102 [%s/%s]: %s\4\r\n"
    // client_event_private_message_received
    #define THREAD_SEND "103 To determine\r\n"
    // NONE
    #define THREAD_RECEIVED "104 [%s/%s/%s]: %s\4\r\n"
    // ? team_uuid, thread_uuid, user_uuid, reply_body
    // client_event_thread_reply_received
    #define TEAM_CREATED "105 [%s/%s]: %s\4\r\n"
    // ? team_uuid, team_name, team_description
    // client_event_team_created
    #define CHANNEL_CREATED "106 [%s/%s]: %s\4\r\n"
    // ? channel_uuid, channel_name, channel_description
    // client_event_channel_created
    #define THREAD_CREATED "107 [%s/%s/%ld/%s]: %s\4\r\n"
    // ? thread_uuid, user_uuid, thread_timestamp, thread_title, thread_body
    // client_event_thread_created

    // 200 -> user print for only the concerned one
    #define SUBSCRIBED "201 [%s/%s]\r\n"
    // ? user_uuid, team_uuid
    // client_print_subscribed
    #define UNSUBSCRIBED "202 [%s/%s]\r\n"
    // ? user_uuid, team_uuid
    // client_print_unsubscribed
    #define TEAM_CREATED_SUCCESSFULLY "203 [%s/%s]: %s\4\r\n"
    // ? team_uuid, team_name, team_description
    // client_print_team_created
    #define CHANNEL_CREATED_SUCCESSFULLY "204 [%s/%s]: %s\4\r\n"
    // ? channel_uuid, channel_name, channel_description
    // client_print_channel_created
    #define THREAD_CREATED_SUCCESSFULLY "205 [%s/%s/%ld/%s]: %s\4\r\n"
    // ? thread_uuid, user_uuid, thread_timestamp, thread_title, thread_body
    // client_print_thread_created
    #define REPLY_CREATED_SUCCESSFULLY "206 [%s/%s/%ld]: %s\4\r\n"
    // ? thread_uuid, user_uuid, reply_timestamp, reply_body
    // client_print_reply_created
    #define USER "207 [UUID:%s, username:%s, status:%d]\r\n"
    // ? uuid, username, status
    // client_print_user
    #define USERS "208 users (%d): ["
    // client_print_users
    #define TEAM "209 [UUID:%s, name:%s, description:%s]\r\n"
    // ? uuid, name, description
    // client_print_team
    #define TEAMS "210 teams (%ld): ["
    // ? for each team:
    // ? uuid, name, description
    // ? same individual print format as [209 - TEAM]
    // ? + (start = \1, end = \4)
    // client_print_teams
    #define CHANNEL "211 [UUID:%s, name:%s, description:%s]\r\n"
    // ? uuid, name, description
    // client_print_channel
    #define CHANNELS "212 channels (%ld): ["
    // ? for each channel:
    // ? uuid, name, description
    // ? same individual print format as [211 - CHANNEL]
    // ? + (start = \1, end = \4)
    // client_team_print_channels
    #define THREAD "213 [%s/%s/%ld/%s]: %s\4\r\n"
    // ? thread_uuid, user_uuid, thread_timestamp, thread_title, thread_body
    // client_print_thread
    #define THREADS "214 threads (%ld): ["
    // ? for each thread:
    // ? thread_uuid, user_uuid, thread_timestamp, thread_title, thread_body
    // ? same individual print format as [213 - THREAD]
    // ? + (start = \1, end = \4)
    // client_channel_print_threads
    #define REPLIES "215 replies (%ld): ["
    // ? for each reply:
    // ? thread_uuid, user_uuid, reply_timestamp, reply_body
    // ? individual print format: "[%s/%s/%ld]: %s"
    // ? + (start = \1, end = \4)
    // client_thread_print_replies
    #define MESSAGES "216 Here are all the messages with %s: ["
    // client_private_message_print_messages

    // 300 -> user error
    #define ALREADY_LOGIN "301 User already logged in.\r\n"
    // NONE
    #define NOT_LOGIN "302 Not logged in.\r\n"
    // NONE
    #define UNKNOW_TEAM "303 [UUID:%s]\r\n"
    // ? team_uuid
    // client_error_unknown_team
    #define UNKNOW_CHANNEL "304 [UUID:%s]\r\n"
    // ? channel_uuid
    // client_error_unknown_channel
    #define UNKNOW_THREAD "305 [UUID:%s]\r\n"
    // ? thread_uuid
    // client_error_unknown_thread
    #define UNKNOW_USER "306 [UUID:%s]\r\n"
    // ? user_uuid
    // client_error_unknown_user
    #define ERROR_UNAUTHORIZED "307 unauthorized\r\n"
    // client_error_unauthorized
    #define ALREADY_EXIST "308 already exist\r\n"
    // client_error_already_exist
    #define ERROR_MESSAGE "309 to determine\r\n"
    // NONE
    #define SYNTAX_ERROR "310 Syntax error in parameters or arguments.\r\n"
    // NONE
    #define BAD_COMMAND "311 Syntax error, command unrecognized.\r\n"
    // NONE

    // useful define for error handling
    // ! HOW TO EXECUTE
    // ? export LD_LIBRARY_PATH=./libs/myteams/

#endif /* !MESSAGES_H_ */
