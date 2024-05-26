/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** funcs_struct_proto.h
*/

#ifndef PFLAGS_FFLAGS_PROTOS_H
    #define PFLAGS_FFLAGS_PROTOS_H
    #include <stdarg.h>
int check_d(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_i(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_s(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_c(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_prc(va_list list, int len, int *fflag_output,
valuesbox_t flag_utils);
int check_sup(va_list list, int len, int *fflag_output,
valuesbox_t flag_utils);
int check_u(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_p(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_f(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_n(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_fup(va_list list, int len, int *fflag_output,
valuesbox_t flag_utils);
int check_o(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_x(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_xup(va_list list, int len, int *fflag_output,
valuesbox_t flag_utils);
int check_e(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_eup(va_list list, int len, int *fflag_output,
valuesbox_t flag_utils);
int check_g(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_gup(va_list list, int len, int *fflag_output,
valuesbox_t flag_utils);
int check_a(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int check_aup(va_list list, int len, int *fflag_output,
valuesbox_t flag_utils);
int check_b(va_list list, int len, int *fflag_output, valuesbox_t flag_utils);
int fflag_dash_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying);
int fflag_plus_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying);
int fflag_space_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying);
int fflag_hashtag_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying);
int fflag_zero_int(int len, valuesbox_t flag_utils, int value,
int isdisplaying);
int fflag_dash_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying);
int fflag_plus_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying);
int fflag_space_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying);
int fflag_hashtag_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying);
int fflag_zero_float(int len, valuesbox_t flag_utils, double value,
int isdisplaying);
int fflag_dash_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying);
int fflag_plus_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying);
int fflag_space_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying);
int fflag_hashtag_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying);
int fflag_zero_putnbr_base(int len, valuesbox_t flag_utils, long value,
int isdisplaying);
int fflag_dash_science(int len, valuesbox_t flag_utils, double value,
int isdisplaying);
int fflag_plus_science(int len, valuesbox_t flag_utils, double value,
int isdisplaying);
int fflag_space_science(int len, valuesbox_t flag_utils, double value,
int isdisplaying);
int fflag_hashtag_science(int len, valuesbox_t flag_utils, double value,
int isdisplaying);
#endif
