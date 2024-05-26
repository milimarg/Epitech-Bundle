/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** funcs_struct_proto.h
*/

#ifndef PROTO_H
    #define PROTO_H
    #include <stdarg.h>
typedef struct valuesbox {
    int i;
    int len;
    int vab_nb;
    char flag;
    char *flag_res;
    int is_flag_separated;
    char *symbols_allowed;
    int width;
    int j;
} valuesbox_t;
int char_alpha(char c);
void my_putchar(char c);
void my_putstr(const char *str);
int my_strlen(const char *str);
int my_intlen(int nb);
int my_put_nbr(int nb);
int my_putstr_full(char const *str, int isdisplaying, int len);
int my_put_float(double nb, int max_decimal, int isdisplaying);
int my_put_science(double nb, char exp_char, int isdisplaying,
int max_decimal);
int my_putnbr_base(long num, char const *base, int isdisplaying);
int my_compute_power_rec(int nb, int p);
int pflag_replacer(int vab_nb, valuesbox_t flag_utils, va_list list, int len);
int thefor(int width, int len_local, char space);
int my_putnbr_base_helper(int *fflag_output, int len, long long_value,
char **values);
int my_put_science_helper(int *fflag_output, int len, double double_value,
char **values);
int my_put_int_helper(int *fflag_output, int len, long long_value,
valuesbox_t flag_utils);
int my_putstr_helper(int *fflag_output, int len, char *string_value,
char *flag_res);
int my_putchar_helper(int *fflag_output, int len, char char_value,
char *flag_res);
int my_putfloat_helper(int *fflag_output, int len, double double_value,
char *flag_res);
int check_fflag_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying);
int check_fflag_float(int len_local, valuesbox_t flag_utils, double value,
int isdisplaying);
int check_fflag_putnbr_base(int len_local, valuesbox_t flag_utils, long value,
int isdisplaying);
#endif
