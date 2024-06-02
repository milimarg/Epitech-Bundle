/*
** EPITECH PROJECT, 2024
** boostrap_myftp
** File description:
** main.c
*/

#include "../include/include.h"

static void destructor(my_ftp *ftp)
{
    free_linked_list(ftp->users);
    for (int i = 0; i < ftp->current_clients_number; i++) {
        free(ftp->data[i].username);
    }
    free(ftp->data);
    free(ftp->trying_path);
    printf("MyFTP: Going to shutdown\n");
}

int main(int argc, char **argv)
{
    my_ftp ftp = {.server_socket = 0, .current_clients_number = 10};

    if (argc != 3) {
        printf("Command should be: ./my_ftp <port_number> <path>\n");
        return 84;
    }
    if (init_ftp(&ftp, atoi(argv[1]), argv[2]) == 1)
        return 84;
    init_clients(&ftp);
    while (1)
        if (loop(&ftp) == 2)
            break;
    close(ftp.server_socket);
    destructor(&ftp);
    return 0;
}
