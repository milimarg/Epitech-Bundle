/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** my_struct.h
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_
typedef struct path_helper {
    char **path_array;
    int path_nb;
    int isfile;
} path_helper_t;
#endif
