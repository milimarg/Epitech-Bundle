/*
** EPITECH PROJECT, 2023
** AIA
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <time.h>
    #define START start_simulation()
    #define STOP stop_simulation()
    #define FWD(value) car_forward(value)
    #define BWD(value) car_backward(value)
    #define TUR(value) car_turn(value)
    #define G_INF get_info_lidar()
    #define CYC(value) cycle(value)

    char **my_str_to_word_array_specified(char *str, char separator);
    void free_word_array(char **arr);
    char *start_simulation(void);
    char *stop_simulation(void);
    char *car_forward(float value);
    char *car_backward(float value);
    char *car_turn(float value);
    char *get_info_lidar(void);
    char *cycle(float value);
    float *get_between_idx(char **args, int start, int end);
    void print_float_tab(float *tab, int lenght);
    void print_informations(float *left, float *front, float *right,
    float *all);
    float compute_average_float(float *tab, int size);
    int check_my_buffer(char *buffer);

#endif /* !MY_H_ */
