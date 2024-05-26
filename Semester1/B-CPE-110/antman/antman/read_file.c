/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "../include/antman.h"

char *read_file(int ac, char **av)
{
    struct stat info = {0};
    int fd = open(av[1], O_RDONLY);
    int error = stat(av[1], &info);
    char *buffer = NULL;

    if (!S_ISREG(info.st_mode))
        return (NULL);
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    if (error == -1)
        return (NULL);
    if (buffer == NULL || read(fd, buffer, info.st_size) == -1 || fd == -1)
        return (NULL);
    buffer[info.st_size] = 0;
    close(fd);
    return (buffer);
}
