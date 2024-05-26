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

int count_elements(char *buffer, int *elements_nb, int *begin_index)
{
    int to_count = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (!to_count)
            write(1, &buffer[i], 1);
        if (!t_my_strncmp(&buffer[i - 4], "\n255\n", 5) && !to_count) {
            to_count = 1;
            *begin_index = ++i;
        }
        if (to_count && buffer[i] == '\n')
            (*elements_nb)++;
    }
    return (0);
}

int parse_element(char *buffer, unsigned char *values, int i, int *char_index)
{
    int temp_nb = 0;

    for (; buffer[i] >= '0' && buffer[i] <= '9'; i++)
        temp_nb = temp_nb * 10 + (buffer[i] - '0');
    values[(*char_index)++] = temp_nb;
    return (i);
}

int image_parser(char *buffer)
{
    unsigned char *values = NULL;
    int elements_nb = 0;
    int begin_index = 0;
    int char_index = 0;

    count_elements(buffer, &elements_nb, &begin_index);
    values = malloc(sizeof(unsigned char) * elements_nb);
    if (values == NULL)
        return (84);
    for (; buffer[begin_index] != '\0'; begin_index++)
        begin_index = parse_element(buffer, values, begin_index, &char_index);
    write(1, values, elements_nb);
    free(values);
    return (0);
}

int image_compression(int ac, char **av, char *str)
{
    struct stat st = {0};
    int filesize = 0;
    int begin_index = 0;
    int error = 0;

    if (image_parser(str) == 84)
        return (84);
    return (0);
}
