/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** file.c
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int get_filesize(char *filename)
{
    struct stat st = {0};

    if (stat(filename, &st))
        return (-84);
    return (st.st_size);
}
