/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** get_files_array.c
*/

#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/my_struct.h"

int save_elements(char *filepath, int file_nb, int *args_indexes,
char **elements)
{
    DIR *ptrDir;
    struct dirent *ptrDirent;
    char *filename = "";
    int i = 0;

    ptrDir = opendir(filepath);
    ptrDirent = readdir(ptrDir);
    if (ptrDir == NULL)
        return (84);
    while (ptrDirent != NULL) {
        filename = ptrDirent->d_name;
        elements[i++] = my_strdup(filename);
        ptrDirent = readdir(ptrDir);
    }
    closedir(ptrDir);
    return (0);
}

int get_path_nb(int argc, char *argv[], path_helper_t *pathinfos)
{
    for (int i = 1; i < argc; i++)
        if (!(argv[i][0] == '-' && argv[i][1]))
            pathinfos->path_nb++;
    if (pathinfos->path_nb > 0)
        pathinfos->isfile = 1;
}

void check_is_file(int argc, char *argv[], char *allowed_args,
path_helper_t *pathinfos)
{
    int j = 0;

    if (!pathinfos->isfile) {
        pathinfos->path_array[0] = ".";
        pathinfos->path_nb = 1;
    }
    if (argc > 1 && pathinfos->isfile) {
        for (int i = 1; i < argc; i++) {
            pathinfos->path_array[j] = !(argv[i][0] == '-' && argv[i][1])
            ? argv[i] : pathinfos->path_array[j];
            j = !(argv[i][0] == '-' && argv[i][1]) ? j + 1 : j;
        }
    }
}
