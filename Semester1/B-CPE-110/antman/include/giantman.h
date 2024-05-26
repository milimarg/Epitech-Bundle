/*
** EPITECH PROJECT, 2022
** my
** File description:
** good prog
*/

#ifndef TEST_H3_
    #define TEST_H3_
    #define CONVERT_CHAR(c) (c < 0) ? c + 256 : c
    int texte_compression(int ac, char **av, char *str);
    int image_compression(int ac, char **av, char *str);
    int html_compression(int ac, char **av, char *str);
    int error_gestion(int ac, char **av, char *str);
    char *read_file(int ac, char **av);
    int get_number_len(int nb);
    void display_nb(int nb, char *values, int *char_index);
    int image_compression(int ac, char **av, char *str);
    int t_my_strncmp(const char *s1, const char *s2, int n);
    char **str_to_decompression(int ac, char **av, char *str);
    char **just_need(char **array);
    int find_size(char *str);
    char **create_local_tab(char *str, int i);
    int calculate_size_pip(char *str, int i);
    int html_check(char *str, char *buffer, int *i, int *a);
    char **create_local_tab(char *str, int i);
    int find_size(char *str);
    char **just_need(char **array);
    char **my_str_to_word_array_condition(char *str, char *separator);
    int store_buffer(char *str, char *buffer, int *i, int *a);
    int calculate_size_pip(char *str, int i);
    char **create_local_tab(char *str, int i);
    int find_size(char *str);
    char **just_need(char **array);
#endif
