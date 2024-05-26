/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include "./my_struct.h"
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
int my_intlen(int nb);
void my_swap(void *a, void *b);
char *my_strdup(char const *src);
int count_file_nb(char *filepath, int *args_indexes);
int get_args(char *argv[], int args_nb, char *allowed_args,
int *args_indexes);
int save_elements(char *filepath, int file_nb, int *args_indexes,
char **elements);
void check_is_file(int argc, char *argv[], char *allowed_args,
path_helper_t *pathinfos);
int check_if_args(int *args_indexes, int args_nb);
void display_files(char **files, int file_nb, int *args_indexes,
char *file_to_stat);
void display_filename(int j, int file_to_display, char *file,
int *args_indexes);
void get_file_infos(char *file, char *path, struct stat *lstats);
void get_permissions(struct stat *lstats);
void display_file_time(struct stat *lstats);
void format_nb(int value, int max_len, int *args_indexes);
void format_str(char *value, int max_len);
int get_highest_nb_len(char **files, int file_nb, char target_vab, char *path);
void display_file_infos(char **file_and_path, int file_nb, int higher_nbs[],
int *args_indexes);
int sort_files_by_time(char **files, int file_nb, char *path,
int *args_indexes);
int get_uid_gid_str(struct stat *lstats, char category, int isdisplaying,
int max_len);
int count_files_to_display(int *args_indexes, char *file_path[], int values[],
int highest_nbs[]);
void if_flag_d(int *args_indexes, char *path, int file_nb, int highest_nbs[]);
void if_not_flag_d(int *args_indexes, int values[], char *file_path[],
int highest_nbs[]);
int get_path_nb(int argc, char *argv[], path_helper_t *pathinfos);
void display_path_header(path_helper_t *pathinfos, int q, int *args_indexes);
void display_newlines(path_helper_t *pathinfos, int *args_indexes, int q);
#endif
