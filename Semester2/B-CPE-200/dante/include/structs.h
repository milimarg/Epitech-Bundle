/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-dante-noam.nedjar
** File description:
** structs.h
*/
#ifndef STRUCTS_H_
    #define STRUCTS_H_
typedef struct maze {
    int width;
    int height;
    int verbose;
    int refresh_delay;
    char **map;
} maze;
#endif /*STRUCTS_H_*/
