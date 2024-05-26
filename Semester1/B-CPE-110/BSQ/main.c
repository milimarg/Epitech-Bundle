/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** main.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "./include/my.h"

int draw_square_in_array(char **map, int highest_nb, int x, int y)
{
    for (int shift_x = 0; shift_x < highest_nb; shift_x++)
        for (int shift_y = 0; shift_y < highest_nb; shift_y++)
            map[x - shift_x][y - shift_y] = 'x';
    printf("hello\n");
    return (0);
}

int **alloc_new_map(int *map_sizes)
{
    int **new_map = malloc(sizeof(int *) * map_sizes[0]);

    for (int i = 0; i < map_sizes[0]; i++)
        new_map[i] = malloc(sizeof(int) * map_sizes[1]);
    return (new_map);
}

int calc_map(char **map, int map_sizes[], int **new_map, int argc)
{
    convert_map(map, map_sizes, new_map, (argc == 2));
    get_biggest_square(new_map, map_sizes, (argc == 2));
    return (0);
}

int run(int argc, char **argv, char **map, int map_sizes[])
{
    int highest_nb = 0;
    int **new_map;
    int square_size = 0;

    if (argc == 3) {
        square_size = my_getnbr(argv[1]);
        if (check_map_pattern(argv) == 84 || square_size <= 1)
            return (84);
        map = map_generator(argc, argv, square_size);
    }
    for (int i = 0; map[i]; i++)
        map_sizes[0]++;
    for (int i = 0; map[1][i]; i++)
        map_sizes[1]++;
    new_map = alloc_new_map(map_sizes);
    calc_map(map, map_sizes, new_map, argc);
    highest_nb = get_highest_nb(new_map, map_sizes);
    replace_to_x(map, new_map, map_sizes, highest_nb);
    display_map(map, map_sizes, highest_nb, (argc == 2));
    free_new_map(map, new_map, map_sizes, (argc == 2));
}

int main(int argc, char **argv)
{
    int file_infos[] = {0, 0};
    char *file = "";
    char **map;
    int map_sizes[] = {0, 0};

    if (argc != 2 && argc != 3)
        return (84);
    if (argc == 2) {
        file = argv[1];
        file_infos[0] = get_fd(file);
        file_infos[1] = get_filesize(file);
        if (file_infos[0] == -84 || file_infos[1] == -84)
            return (84);
        map = fill_map(file_infos[0], file_infos[1]);
        if (check_file_is_valid(map) == 84)
            return (84);
    }
    if (run(argc, argv, map, map_sizes) == 84)
        return (84);
    return (0);
}
