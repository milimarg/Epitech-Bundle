/*
** EPITECH PROJECT, 2022
** All_prototypes
** File description:
** vous etes dans l'abus
*/

#include <unistd.h>
#include <stdarg.h>

#ifndef ZAZA
    #define ZAZA

    int print_str(va_list list_arg, int count);

    int print_unsi(va_list list_arg, int count);

    char *my_strdup(char *string);

    int print_char(va_list list_arg, int count);

    int print_int(va_list list_arg, int count);

    int my_array_len(char **array);

    char **my_str_to_word_array(char const *str);

    int my_print_purcent(va_list list_arg, int count);

    int print_octal(va_list list_arg, int count);

    int print_hexa_maj(va_list list_arg, int count);

    int print_hexa_min(va_list list_arg, int count);

    int print_adress(va_list list_arg, int count);

    int printn(va_list list_arg, int count);

    int print_adress(va_list list_arg, int count);

    int my_printf(const char *format, ...);

    int compareword(char *w1, char *w2);

    int my_binary(va_list list_arg, int count);

    int print_float(va_list list_arg, int count);

    int print_scien(va_list list_arg, int count);

    int print_scienup(va_list list_arg, int count);

    int tabeau(int a, va_list list_arg, int count);

    int plus_flag(va_list list_arg, int count);

    int no_flag(char *arg);

    int main_l(char **array, char *arg, char flag_a, int k);

    int flag_detected(char *flag, int k);

    int print_space(const char *format, int i);

    int my_compute_power_rec(int nb, int p);

    int my_compute_square_root(int nb);

    int my_find_prime_sup(int nb);

    int my_getnbr(char const *str);

    void my_putchar(char c);

    int my_isneg(int n);

    int bouboucle01(int nb);

    int my_is_prime(int nb);

    int my_put_nbr(int nb);

    void my_put_unnbr(int long nb);

    int my_putstr(char const *str);

    int my_strlen(char const *str);

    char *my_revstr(char *str);

    int my_showmem(char const *str, int size);

    int my_showstr(char const *str);

    void my_sort_int_array(int *tab, int size);

    char *my_strcapitalize(char *str);

    char *my_strcat(char *dest, char const *src);

    int my_strcmp(char const *s1, char const *s2);

    char *my_strcpy(char *dest, char const *src);

    int my_str_isalpha(char const *str);

    int my_str_islower(char const *str);

    int my_str_isnum(char const *str);

    int my_str_isprintable(char const *str);

    int my_str_isupper(char const *str);

    char *my_strlowcase(char *str);

    char *my_strncat(char *dest, char const *src, int n);

    int my_strncmp(char const *s1, char const *s2);

    char *my_strncpy(char *dest, char const *src, int n);

    char *my_strstr(char *str, char const *to_find);

    char *my_strupcase(char *str);

    void my_swap(int *a, int *b);

    int my_rev_nbr(int long nb);

    int my_nbrlen(int long nb);

#endif
