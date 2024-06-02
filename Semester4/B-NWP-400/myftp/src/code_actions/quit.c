/*
** EPITECH PROJECT, 2024
** B-NWP-400-STG-4-1-myftp-florent.guittre
** File description:
** quit.c
*/

#include "../../include/include.h"

int quit(my_ftp *ftp __attribute_maybe_unused__,
    user_data *data, const char *value __attribute_maybe_unused__)
{
    dprintf(data->fd, QUIT_OK);
    close(data->fd);
    data->fd = -1;
    return 0;
}
