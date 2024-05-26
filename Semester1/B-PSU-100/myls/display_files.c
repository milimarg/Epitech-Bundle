/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** display_files.c
*/

#include <stdlib.h>
#include <sys/stat.h>
#include "./include/my.h"

void get_file_infos(char *file, char *path, struct stat *lstats)
{
    int path_len = my_strlen(path);
    int file_len = my_strlen(file);
    char *fullpath = malloc(sizeof(char) * ((file_len + path_len) + 2));

    fullpath[0] = '\0';
    my_strcat(fullpath, path);
    if (path[path_len - 1] != '/')
        my_strcat(fullpath, "/");
    my_strcat(fullpath, file);
    lstat(fullpath, lstats);
    free(fullpath);
}

void if_not_flag_d(int *args_indexes, int values[], char *file_path[],
int highest_nbs[])
{
    int j = values[0];
    int file_to_display = values[1];
    int file_nb = values[2];

    if (args_indexes[1])
        display_file_infos(file_path, file_nb, highest_nbs, args_indexes);
    else
        display_filename(j, file_to_display, file_path[0], args_indexes);
}

void if_flag_d(int *args_indexes, char *path, int file_nb, int highest_nbs[])
{
    char *file_path[] = {path, ""};

    if (args_indexes[1])
        display_file_infos(file_path, file_nb, highest_nbs, args_indexes);
    else
        my_putstr(path);
}

int get_file_to_display(int file_nb, char **files, int *args_indexes)
{
    char *file;
    int files_to_display = 0;

    for (int i = 0; i < file_nb; i++) {
        file = (args_indexes[4]) ? files[file_nb - i - 1] : files[i];
        if (((file[0] == '.' && args_indexes[0]) || (file[0] != '.')) &&
        !args_indexes[3])
            files_to_display++;
        if (args_indexes[3]) {
            files_to_display++;
            break;
        }
    }
    return (files_to_display);
}

void display_files(char **files, int file_nb, int *args_indexes, char *path)
{
    int j = 0;
    int highest_nbs[] = {0, 0, 0, 0};
    int values[] = {0, 0, file_nb};
    char *file = "";
    char *file_path[] = {file, path};
    int file_to_display = get_file_to_display(file_nb, files, args_indexes);

    values[1] = file_to_display;
    highest_nbs[0] = get_highest_nb_len(files, file_nb, 'L', path);
    highest_nbs[1] = get_highest_nb_len(files, file_nb, 'S', path);
    highest_nbs[2] = get_highest_nb_len(files, file_nb, 'U', path);
    highest_nbs[3] = get_highest_nb_len(files, file_nb, 'G', path);
    sort_files_by_time(files, file_nb, path, args_indexes);
    for (int i = 0; i < file_nb; i++) {
        file_path[0] = (args_indexes[4]) ? files[file_nb - i - 1] : files[i];
        values[0] = count_files_to_display(args_indexes, file_path, values,
        highest_nbs);
        if (values[0] == -42)
            break;
    }
}
