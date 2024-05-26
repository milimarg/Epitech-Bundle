/*
** EPITECH PROJECT, 2022
** CPOOL_Day12_task01
** File description:
** my_cat.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void display_error(char *file)
{
    my_putstr("cat: ");
    my_putstr(file);
    my_putstr(": No such file or directory\n");
}

int my_cat_no_file(void)
{
    char buffer[32001] = "";
    int read_value = 0;

    read_value = read(0, buffer, 32000);
    write(1, buffer, read_value);
    return read_value;
}

int my_cat(char *file)
{
    int fd = 0;
    int size = 0;
    char buffer[32001] = "";

    fd = open(file, O_RDONLY);
    if (fd == -1) {
        display_error(file);
        return (84);
    }
    size = read(fd, buffer, 32000);
    write(1, buffer, size);
    close(fd);
    return (0);
}
