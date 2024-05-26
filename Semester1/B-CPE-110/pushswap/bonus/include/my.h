/*
** EPITECH PROJECT, 2022
** B-CPE-110-STG-1-1-pushswap-florent.guittre
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
int my_getnbr(char const *str);
int pa_util(elements_t *elements);
int pb_util(elements_t *elements);
void ra_util(elements_t *elements);
void rra_util(elements_t *elements);
void display_delimiter(elements_t *elements, int j);
int shift_numbers_to_left(int j, elements_t *elements);
int shift_numbers_to_right(int j, elements_t *elements);
int pushswap_handler_basic(elements_t *elements);
int fill_arrays(int nb_arg, elements_t *elements, char **argv);
int *init_sizes_array(int nb_arg);
int *get_args(int argc, char *argv[]);
int my_strlen(char const *str);
int my_strcmp(const char *s1, const char *s2);
int my_put_nbr(int nb);
void display_lists(elements_t *elements);
#endif /* !MY_H_ */
