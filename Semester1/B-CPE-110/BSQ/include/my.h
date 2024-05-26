/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
char **my_str_to_word_array(char const *str, char separator, int size);
void display_map(char **map, int map_sizes[], int highest_nb, int isfile);
int convert_map(char **map, int MAP_SIZES[], int **new_map, int isfile);
int free_new_map(char **map, int **new_map, int map_sizes[], int isfile);
int find_lowest_nb(int **map, int MAP_SIZES[], int x, int y);
int replace_to_x(char **map, int **new_map, int MAP_SIZES[], int highest_nb);
int get_fd(char *file);
int get_filesize(char *file);
char **fill_map(int fd, int size);
int draw_square_in_array(char **map, int highest_nb, int x, int y);
int get_highest_nb(int **map, int MAP_SIZES[]);
int get_biggest_square(int **map, int MAP_SIZES[], int isfile);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int **alloc_new_map(int *map_sizes);
char **map_manager(int argc, char **argv, int fd, int size);
int check_map_pattern(char **argv);
char **map_generator(int argc, char **argv, int square_size);
int my_getnbr(char const *str);
int check_file_is_valid(char **map);
#endif
