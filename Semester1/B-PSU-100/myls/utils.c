/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** utils.c
*/

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include "./include/my.h"

int count_file_nb(char *filepath, int *args_indexes)
{
    DIR *ptrDir;
    struct dirent *ptrDirent;
    char *filename = "";
    int i = 0;

    ptrDir = opendir(filepath);
    if (ptrDir == NULL)
        return (-1);
    ptrDirent = readdir(ptrDir);
    while (ptrDirent != NULL) {
        i++;
        ptrDirent = readdir(ptrDir);
    }
    closedir(ptrDir);
    return (i);
}

void add_spaces(int i, char pos, char *file)
{
    if (i != 0 && pos == 'B')
        my_putchar(' ');
    if (file && pos == 'E')
        my_putchar(' ');
}

void format_nb(int value, int max_len, int *args_indexes)
{
    int value_len = 0;

    if (!args_indexes[3]) {
        value_len = my_intlen(value);
        for (int m = 0; m < (max_len - value_len); m++)
            my_putchar(' ');
    }
    my_put_nbr(value);
}

void format_str(char *value, int max_len)
{
    int value_len = 0;

    value_len = my_strlen(value);
    for (int m = 0; m < (max_len - value_len); m++)
        my_putchar(' ');
    my_putstr(value);
}

int get_highest_nb_len(char **files, int file_nb, char target_vab, char *path)
{
    int final = 0;
    int value_check = 0;
    int o = 0;
    struct stat lstat_temp;

    for (int i = 0; i < file_nb; i++) {
        get_file_infos(files[i], path, &lstat_temp);
        if (target_vab == 'L')
            value_check = lstat_temp.st_nlink;
        if (target_vab == 'S')
            value_check = lstat_temp.st_size;
        if (target_vab == 'U')
            value_check = get_uid_gid_str(&lstat_temp, 'U', 0, 0);
        if (target_vab == 'G')
            value_check = get_uid_gid_str(&lstat_temp, 'G', 0, 0);
        if (value_check > final)
            final = value_check;
    }
    o = (target_vab == 'U' || target_vab == 'G') ? final : my_intlen(final);
    return (o);
}
