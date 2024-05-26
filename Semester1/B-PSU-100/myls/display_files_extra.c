/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** display_files_extra.c
*/

#include <time.h>
#include <sys/stat.h>
#include <pwd.h>
#include "./include/my.h"

void get_permissions(struct stat *lstats)
{
    char filetype = '\0';

    if (S_ISDIR(lstats->st_mode))
        filetype = 'd';
    if (S_ISLNK(lstats->st_mode))
        filetype = 'l';
    if (!(S_ISDIR(lstats->st_mode) || S_ISLNK(lstats->st_mode)))
        filetype = '-';
    my_putchar(filetype);
    my_putchar((lstats->st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((lstats->st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((lstats->st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((lstats->st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((lstats->st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((lstats->st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((lstats->st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((lstats->st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((lstats->st_mode & S_IXOTH) ? 'x' : '-');
}

void display_file_time(struct stat *lstats)
{
    char *time_str = ctime(&lstats->st_mtim);

    for (int i = 4; i < my_strlen(time_str) - 9; i++)
        my_putchar(time_str[i]);
}

void display_filename(int j, int file_to_display, char *file, int *args_indexes)
{
    if (j != 0)
        my_putchar(' ');
    my_putstr(file);
    if (!file)
        my_putchar('\n');
}

int get_uid_gid_str(struct stat *lstats, char category, int isdisplaying,
int max_len)
{
    struct passwd *pwd;

    if (category == 'U')
        pwd = getpwuid(lstats->st_uid);
    if (category == 'G')
        pwd = getpwuid(lstats->st_gid);
    if (isdisplaying)
        format_str(pwd->pw_name, max_len);
    return (my_strlen(pwd->pw_name));
}

void display_file_infos(char **file_and_path, int file_nb, int higher_nbs[],
int *args_indexes)
{
    struct stat lstats;

    get_file_infos(file_and_path[0], file_and_path[1], &lstats);
    get_permissions(&lstats);
    my_putstr(". ");
    format_nb(lstats.st_nlink, higher_nbs[0], args_indexes);
    my_putchar(' ');
    get_uid_gid_str(&lstats, 'U', 1, higher_nbs[2]);
    my_putchar(' ');
    get_uid_gid_str(&lstats, 'G', 1, higher_nbs[3]);
    my_putchar(' ');
    format_nb(lstats.st_size, higher_nbs[1], args_indexes);
    my_putchar(' ');
    display_file_time(&lstats);
    my_putchar(' ');
    my_putstr(file_and_path[0]);
    if (file_and_path[0])
        my_putchar('\n');
}
