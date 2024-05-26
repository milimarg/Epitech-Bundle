/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** modify_map.c
*/

int draw_square_in_array(char **map, int highest_nb, int x, int y);

int add_x(char **map, int **new_map, int values[], int *map_sizes)
{
    int x = values[0];
    int highest_nb = values[1];

    for (int y = 0; y < map_sizes[1]; y++) {
        if (new_map[x][y] == highest_nb) {
            draw_square_in_array(map, highest_nb, x, y);
            return (0);
        }
    }
    return (-1);
}

int replace_to_x(char **map, int **new_map, int map_sizes[], int highest_nb)
{
    int values[] = {0, 0};

    for (int x = 1; x < map_sizes[0]; x++) {
        values[0] = x;
        values[1] = highest_nb;
        if (add_x(map, new_map, values, map_sizes) == 0)
            return (0);
    }
    return (0);
}
