/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** file_utils.c
*/

#include <fcntl.h>
#include "./include/my.h"

int get_fd(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return (-84);
    return (fd);
}

int nb_rows_check(char **map)
{
    int nb_rows_in_file = 0;
    int nb_rows_calc = 0;

    nb_rows_in_file = my_getnbr(map[0]);
    for (int i = 1; map[i]; i++)
        nb_rows_calc++;
    if (nb_rows_in_file != nb_rows_calc)
        return (-84);
    return (nb_rows_calc);
}

int nb_columns_check(char **map)
{
    int nb_columns_in_file = 0;
    int nb_columns_calc = 0;

    for (int i = 0; map[1][i]; i++)
        nb_columns_calc++;
    for (int i = 1; map[i]; i++) {
        for (int j = 0; map[i][j]; j++)
            nb_columns_in_file++;
        if (nb_columns_in_file != nb_columns_calc)
            return (-84);
        nb_columns_in_file = 0;
    }
    return (nb_columns_calc);
}

int check_chars_in_file(char **map, int rows_nb, int columns_nb)
{
    int is_valid = 1;

    for (int x = 1; (x < rows_nb && is_valid); x++)
        for (int y = 0; (y < columns_nb && is_valid); y++)
            is_valid = (map[x][y] == '.' || map[x][y] == 'o');
    return (is_valid);
}

int check_file_is_valid(char **map)
{
    int rows_nb = 0;
    int columns_nb = 0;

    rows_nb = nb_rows_check(map);
    columns_nb = nb_columns_check(map);
    if (rows_nb == -84 || columns_nb == -84 ||
    !check_chars_in_file(map, rows_nb, columns_nb))
        return (84);
    return (0);
}
