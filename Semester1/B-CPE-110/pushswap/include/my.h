/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
int my_getnbr(char const *str);
int sa_util(int *l_a, int *l_b, int *sizes);
int sb_util(int *l_a, int *l_b, int *sizes);
int sc_util(int *l_a, int *l_b, int *sizes);
int pa_util(int *l_a, int *l_b, int *sizes);
int pb_util(int *l_a, int *l_b, int *sizes);
int ra_util(int *l_a, int *l_b, int *sizes);
int rb_util(int *l_a, int *l_b, int *sizes);
int rr_util(int *l_a, int *l_b, int *sizes);
int rra_util(int *l_a, int *l_b, int *sizes);
int rrb_util(int *l_a, int *l_b, int *sizes);
int rrr_util(int *l_a, int *l_b, int *sizes);
void display_delimiter(int *sizes, int j);
int frees(int *l_a, int *l_b, int *sizes);
int shift_numbers_to_left(int j, int *sizes, int *l_a, int *l_b);
int shift_numbers_to_right(int j, int *sizes, int *l_a, int *l_b);
int pushswap_handler_basic(int *l_a, int *l_b, int *sizes);
int fill_arrays(int nb_arg, int *l_a, int *l_b, char **argv);
int *init_sizes_array(int nb_arg);
#endif /* !MY_H_ */
