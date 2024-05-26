/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include <sys/stat.h>
#include "../include/my.h"
#include "../include/antman.h"

int error_gestion(int ac, char **av, char *str)
{
    struct stat information;
    int error = stat(av[1], &information);

    if (error == -1)
        return (84);
    return (0);
}
