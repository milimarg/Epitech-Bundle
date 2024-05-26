/*
** EPITECH PROJECT, 2023
** Dante
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #define my_char_isvisible(c) (c >= '!' && c <= '~')
char **my_str_to_word_array(char const *str);
int destroy_my_str_to_word_array(char **str);
int replace_abandoned_cells(maze *my_maze);
void run_end_of_maze(maze *my_maze, int x, int y);
#endif /*MY_H_*/
