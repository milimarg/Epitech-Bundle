/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** sort_by_time.c
*/

#include <sys/stat.h>
#include "../include/my.h"

void reverse_array(int file_nb, char **files)
{
    char *temp_files[file_nb];

    for (int i = 0; i < file_nb; i++)
        temp_files[i] = files[file_nb - 1 - i];
    for (int i = 0; i < file_nb; i++)
        files[i] = temp_files[i];
}

void sort_files_manager(int file_nb, int file_m_time[file_nb], char **files)
{
    int test = 0;

    for (int i = 0; i < file_nb - 1; i++) {
        test = i;
        for (int j = i + 1; j < file_nb; j++)
            test = (file_m_time[j] < file_m_time[test]) ? j : test;
        my_swap(&file_m_time[test], &file_m_time[i]);
        my_swap(&files[test], &files[i]);
    }
}

int sort_files_by_time(char **files, int file_nb, char *path,
int *args_indexes)
{
    struct stat lstats;
    int blocks_used = 0;
    int file_m_time[file_nb];

    for (int i = 0; i < file_nb; i++) {
        get_file_infos(files[i], path, &lstats);
        file_m_time[i] = lstats.st_mtim.tv_sec;
        if ((files[i][0] == '.' && args_indexes[0]) || files[i][0] != '.')
            blocks_used += (lstats.st_blocks / 2);
    }
    if (args_indexes[5]) {
        sort_files_manager(file_nb, file_m_time, files);
        reverse_array(file_nb, files);
    }
    if ((args_indexes[1] || args_indexes[6]) && !args_indexes[3]) {
        my_putstr("total ");
        my_put_nbr(blocks_used);
        my_putchar('\n');
    }
    return (0);
}
