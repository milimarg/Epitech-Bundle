/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_ls.c
*/

#include <sys/stat.h>
#include <stdlib.h>
#include "./include/my.h"
#include "./include/my_struct.h"

int free_elements(char **elements, int file_nb)
{
    for (int w = 0; w < file_nb; w++)
        free(elements[w]);
    free(elements);
    return (0);
}

int take_path(int q, path_helper_t *pathinfos, int *args_indexes)
{
    struct stat stats;
    int file_nb = count_file_nb(pathinfos->path_array[q], args_indexes);
    char **elements;

    if (!lstat(pathinfos->path_array[q], &stats) && file_nb != -1) {
        elements = malloc(sizeof(char *) * (file_nb + 1));
        display_path_header(pathinfos, q, args_indexes);
        if (save_elements(pathinfos->path_array[q], file_nb, args_indexes,
        elements) == 84)
            return (84);
        display_files(elements, file_nb, args_indexes,
        pathinfos->path_array[q]);
        display_newlines(pathinfos, args_indexes, q);
        free_elements(elements, file_nb);
    } else {
        my_putstr("File not found\n");
        return (84);
    }
    return (0);
}

int fill_struct(path_helper_t *pathinfos)
{
    pathinfos->isfile = 0;
    pathinfos->path_nb = 0;
    return (0);
}

int free_my_ls(int *args_indexes, path_helper_t *pathinfos)
{
    free(args_indexes);
    free(pathinfos->path_array);
}

int my_ls(int argc, char *argv[])
{
    path_helper_t pathinfos;
    char *allowed_args = "alRdrt";
    int args_nb = my_strlen(allowed_args);
    int *args_indexes = malloc(sizeof(int) * args_nb);
    int files_existing = 0;
    int o = 0;

    fill_struct(&pathinfos);
    if (argc > 1)
        get_path_nb(argc, argv, &pathinfos);
    pathinfos.path_array = malloc(sizeof(char *) *
    ((pathinfos.isfile == 0) ? 1 : pathinfos.path_nb));
    check_is_file(argc, argv, allowed_args, &pathinfos);
    o = get_args(argv, args_nb, allowed_args, args_indexes);
    if (o == 84)
        return (84);
    for (int q = 0; q < pathinfos.path_nb; q++)
        files_existing += take_path(q, &pathinfos, args_indexes);
    free_my_ls(args_indexes, &pathinfos);
    return (files_existing);
}
