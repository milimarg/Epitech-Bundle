/*
** EPITECH PROJECT, 2022
** CPOOL_count_island
** File description:
** count_island.c
*/

#include <stddef.h>

void my_putstr(const char *str);

void my_putchar(char c);

int my_put_nbr(int nb);

char int_to_char(int nb);

int format_co(int value, char letter, char **world);

int get_limits(char letter, char **world);

int find_unique_island(int coordinates[], char **world, int counter, int island_nb)
{
    int x = coordinates[0];
    int y = coordinates[1];
    int is_vertical = 0;
    int is_horizontal = 0;

    if (world[x][format_co(y + 1, 'y', world)] == '.' && world[x][format_co(y - 1, 'y', world)] == '.')
        is_vertical = 1;
    if (world[format_co(x + 1, 'x', world)][y] == '.' && world[format_co(x - 1, 'x', world)][y] == '.')
        is_horizontal = 1;
    if (world[x][y] == 'X' && is_vertical && is_horizontal) {
        world[x][y] = int_to_char(counter);
        counter++;
    }
    if (island_nb == counter) {
        world[x][y] = int_to_char(counter);
        counter++;
    }
    return counter;
}

int search_path(int coordinates[], char **world, int counter, int a)
{
    int x = coordinates[0];
    int y = coordinates[1];
    int coor[10] = {x, y, x - 1, y, x + 1, y, x, y - 1, x, y + 1};
    for (int i = 0; i < 10; i += 2) {
        x = format_co(coor[i], 'x', world);
        y = format_co(coor[i + 1], 'y', world);
        coordinates[0] = x;
        coordinates[1] = y;
        if (world[x][y] == 'X') {
            world[x][y] = int_to_char(counter);
            a = search_path(coordinates, world, counter, ++a);
        }
    }
    return a;
}

int count_island_func(char **world, int island_nb)
{
    int limits[2];
    int coordinates[2];
    int counter = 0;
    int a = 0;
    int z;

    limits[0] = get_limits('x', world);
    limits[1] = get_limits('y', world);
    for (int x = 0; x < limits[0]; x++)
        for (int y = 0; y < limits[1]; y++) {
            coordinates[0] = x;
            coordinates[1] = y;
            z = counter;
            counter = find_unique_island(coordinates, world, counter, island_nb);
            a = (world[x][y] == 'X' && z == counter) ?
            search_path(coordinates, world, counter, a) : 0;
            world[x][y] = (world[x][y] == int_to_char(counter) &&
            world[x][format_co(y - 1, 'y', world)] == int_to_char(counter - 1)) ?
            int_to_char(counter - 1) : world[x][y];
            world[x][y] = (world[x][y] > int_to_char(island_nb)) ?
            int_to_char(island_nb - 1) : world[x][y];
            counter += (a > 2) ? 1 : 0;
            a = (a > 1) ? 0 : a;
        }
    return counter;
}

int count_island(char **world)
{
    int island_nb = count_island_func(world, 10);
    my_putstr("islands nb: ");
    my_put_nbr(island_nb);
    my_putchar ('\n');

    for (int i = 0; world[i] != NULL; i++)
        for (int j = 0; world[i][j] != '\0'; j++)
            world[i][j] = (world[i][j] >= '0') ? 'X' : '.';
    return count_island_func(world, island_nb);
}
