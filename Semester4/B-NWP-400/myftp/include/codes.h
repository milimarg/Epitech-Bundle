/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** codes.h
*/

#ifndef B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_CODES_H
    #define B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_CODES_H

    #define SUCCESSFULLY_CONNECTION "220 Service ready for new user.\n"
    #define NOT_LOGGED_IN "530 Not logged in.\n"

    #define USER_OK "331 User name okay, need password.\n"
    #define USER_ALREADY_LOGGED_IN PASSWORD_OK
    #define USER_SYNTAX_ERROR_IN_ARGUMENTS "501 Syntax error.\n"

    #define PASSWORD_OK "230 User logged in, proceed.\n"
    #define PASSWORD_SYNTAX_ERROR "503\n"
    #define PASSWORD_WITHOUT_USER "332 Need account for login.\n"

    #define PWD_OK "257"

    #define CWD_OK "250 Directory changed to"
    #define CWD_NOT_LOGGED_IN NOT_LOGGED_IN
    #define CWD_FILE_NOT_FOUND "550 No such directory.\n"

    #define COMMAND_NOT_FOUND "500 Command not found.\n"

    #define HELP_OK "214 meow!\n"

    #define NOOP_OK "200 'NOOP' OK.\n"

    #define CDUP_OK "200 Directory changed to "

    #define QUIT_OK "221 Bye bye!\n"

    #define PASV_OK "227 Entering Passive Mode"
    #define PASV_NOT_LOGGED_IN ""

    #define REJECTING_CONNECTION "425 Rejecting data connection."

    #define LIST_OPEN_CONNECTION "150 Opening 'BINARY' data connection."
    #define LIST_TRANSFER_COMPLETE "226 Transfer complete."

    #define DELE_OK "250 Deleted file."
    #define DELE_FILE_NOT_FOUND "550 File not found."
    #define DELE_FILE_NO_ACCESS "550 Access denied."

#endif //B_NWP_400_STG_4_1_MYFTP_FLORENT_GUITTRE_CODES_H
