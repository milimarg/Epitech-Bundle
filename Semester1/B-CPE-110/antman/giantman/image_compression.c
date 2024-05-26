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
#include "../include/giantman.h"

int count_chars(char *buffer, int *begin_idx, int *count_len, int filesize)
{
    int to_count = 0;

    for (int i = 0; i < filesize; i++) {
        if (!t_my_strncmp(&buffer[i - 4], "\n255\n", 5) && !to_count) {
            to_count = 1;
            *begin_idx = ++i;
        }
        if (to_count)
            *count_len += get_number_len(CONVERT_CHAR(buffer[i])) + 1;
    }
    return (0);
}

int write_and_free(char *values, int begin_idx, int count_len)
{
    write(1, values, begin_idx + count_len);
    free(values);
    return (0);
}

int image_parser(char *buffer, int filesize, char *values)
{
    int begin_idx = 0;
    int char_idx = 0;
    int count_len = 0;

    count_chars(buffer, &begin_idx, &count_len, filesize);
    values = malloc(sizeof(char) * (begin_idx + count_len + 1));
    if (values == NULL)
        return (84);
    for (int i = 0; i < begin_idx; i++)
        values[char_idx++] = buffer[i];
    for (int i = 0; i < (filesize - begin_idx); i++) {
        if (buffer[begin_idx + i] != 0)
            display_nb(CONVERT_CHAR(buffer[begin_idx + i]), values, &char_idx);
        else
            values[char_idx++] = '0';
        values[char_idx++] = '\n';
    }
    values[char_idx] = 0;
    write_and_free(values, begin_idx, count_len);
    return (0);
}

int image_compression(int ac, char **av, char *str)
{
    struct stat st = {0};
    int filesize = 0;
    char *values = NULL;
    int error = 0;

    error = stat(av[1], &st);
    filesize = st.st_size;
    if (error == -1)
        return (84);
    if (image_parser(str, filesize, values) == 84)
        return (84);
    return (0);
}
