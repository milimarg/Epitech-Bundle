/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_put_float_helper.c
*/

#include "../../include/funcs_struct_proto.h"
#include "../../include/pflags_fflags_protos.h"

int find_right_index_float(valuesbox_t flag_utils, int len_local, double value,
int isdisplaying)
{
    char *symbols_char = "+ -0#";
    char flag_char = flag_utils.flag_res[flag_utils.i];
    int (*symbols[])(int, valuesbox_t, double, int) = {&fflag_plus_float,
    &fflag_space_float, &fflag_dash_float, &fflag_zero_float,
    &fflag_hashtag_float};

    if (flag_utils.symbols_allowed[flag_utils.j] == flag_char)
        for (int k = 0; k < 5; k++) {
            len_local = (symbols_char[k] == flag_char) ?
            symbols[k](len_local, flag_utils, value, isdisplaying) : len_local;
        }
    return len_local;
}

int check_fflag_float(int len_local, valuesbox_t flag_utils, double value,
int isdisplaying)
{
    char flag_char = '\0';
    int symbols_allowed_len = my_strlen(flag_utils.symbols_allowed);

    flag_utils.i = 1;
    flag_char = flag_utils.flag_res[flag_utils.i];
    while (flag_char && !(flag_char >= '1' && flag_char <= '9')) {
        for (flag_utils.j = 0; flag_utils.j < symbols_allowed_len;
        flag_utils.j++) {
            len_local = find_right_index_float(flag_utils, len_local, value,
            isdisplaying);
        }
        flag_char = flag_utils.flag_res[++flag_utils.i];
    }
    return (len_local);
}

int my_putfloat_helper(int *fflag_output, int len, double double_value,
char *flag_res)
{
    int precision = (fflag_output[2] == 'p') ? fflag_output[3] : 6;
    int len_local = my_put_float(double_value, precision, 0);
    int width = fflag_output[1];

    if (fflag_output[0] != 'e') {
        len += (width - len_local >= 0) ? width : len_local;
        my_put_float(double_value, precision, 1);
    } else {
        len += my_strlen(flag_res);
        my_putstr(flag_res);
    }
    return (len);
}
