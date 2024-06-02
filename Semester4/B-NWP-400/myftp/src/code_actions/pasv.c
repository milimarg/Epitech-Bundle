/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** pasv.c
*/

#include "../../include/include.h"

static unsigned int get_nearest_power_2_below(unsigned int n)
{
    return n == 0 ? 0 : (1 << (31 - __builtin_clz(n)));
}

static void print_ip_and_port(my_ftp *ftp, user_data *data)
{
    int nearest = get_nearest_power_2_below(data->pasv.port);
    int port1 = nearest / 256;
    int port2 = data->pasv.port - nearest;

    dprintf(data->fd, "%s (%d,%d,%d,%d,%d,%d)\n", PASV_OK, ftp->ip[0],
    ftp->ip[1], ftp->ip[2], ftp->ip[3], port1, port2);
}

static void get_next_available_port(my_ftp *ftp, user_data *data)
{
    unsigned short int start_port = 1024;
    const unsigned short int end_port = 65535;

    data->pasv.addr.sin_family = AF_INET;
    data->pasv.addr.sin_addr.s_addr = INADDR_ANY;
    while (start_port < end_port) {
        data->pasv.addr.sin_port = htons(start_port);
        start_port++;
        if (bind(data->pasv.fd, (struct sockaddr *)&data->pasv.addr,
        sizeof(data->pasv.addr)) != -1)
            break;
    }
    if (listen(data->pasv.fd, 10) != 0)
        return;
    data->pasv.port = start_port - 1;
    print_ip_and_port(ftp, data);
}

int pasv(my_ftp *ftp, user_data *data,
    const char *value __attribute_maybe_unused__)
{
    if (!data->username) {
        dprintf(data->fd, NOT_LOGGED_IN);
        return 1;
    }
    if (data->pasv.fd != -1)
        close(data->pasv.fd);
    data->type = PASSIVE;
    data->pasv.fd = socket(AF_INET, SOCK_STREAM, 0);
    get_next_available_port(ftp, data);
    printf("miaou -- port %d ; fd %d\n", data->pasv.port, data->pasv.fd);
    return 0;
}
