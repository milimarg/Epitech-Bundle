/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** calc.c
*/

int get_map_sizes(int *map_sizes, char **map)
{
    for (int i = 0; map[i]; i++)
        map_sizes[0]++;
    for (int i = 0; map[1][i]; i++)
        map_sizes[1]++;
    return (0);
}

int find_lowest_nb(int **map, int MAP_SIZES[], char paths[], int lowest_nb)
{
    if (paths[0] < lowest_nb)
        lowest_nb = paths[0];
    if (paths[1] < lowest_nb)
        lowest_nb = paths[1];
    return (lowest_nb);
}

int get_biggest_square(int **map, int MAP_SIZES[], int isfile)
{
    int lowest_nb = 0;
    int current = 0;
    char paths[] = {0, 0};

    for (int x = isfile + 1; x < MAP_SIZES[0]; x++) {
        for (int y = 1; y < MAP_SIZES[1]; y++) {
            current = map[x][y];
            lowest_nb = map[x - 1][y - 1];
            paths[0] = map[x - 1][y];
            paths[1] = map[x][y - 1];
            lowest_nb = find_lowest_nb(map, MAP_SIZES, paths, lowest_nb);
            map[x][y] += (current != 0) ? lowest_nb : 0;
        }
    }
    return (0);
}

int get_highest_nb(int **map, int MAP_SIZES[])
{
    int highest_nb = 0;

    for (int x = 1; x < MAP_SIZES[0]; x++)
        for (int y = 0; y < MAP_SIZES[1]; y++)
            highest_nb = (map[x][y] > highest_nb) ? map[x][y] : highest_nb;
    return (highest_nb);
}
