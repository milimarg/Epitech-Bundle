/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_put_int_helper.c
*/

#include "../../include/funcs_struct_proto.h"
#include "../../include/pflags_fflags_protos.h"

int find_right_index_int(valuesbox_t flag_utils, int len_local, int value,
int isdisplaying)
{
    char *symbols_char = "+ -0#";
    char flag_char = flag_utils.flag_res[flag_utils.i];
    int (*symbols[])(int, valuesbox_t, int, int) = {&fflag_plus_int,
    &fflag_space_int, &fflag_dash_int, &fflag_zero_int,
    &fflag_hashtag_int};

    if (flag_utils.symbols_allowed[flag_utils.j] == flag_char)
        for (int k = 0; k < 5; k++)
            len_local = (symbols_char[k] == flag_char) ?
            symbols[k](len_local, flag_utils, value, isdisplaying) : len_local;
    return len_local;
}

int check_fflag_int(int len_local, valuesbox_t flag_utils, int value,
int isdisplaying)
{
    char flag_char = '\0';
    int symbols_allowed_len = my_strlen(flag_utils.symbols_allowed);

    flag_utils.i = 1;
    flag_char = flag_utils.flag_res[flag_utils.i];
    while (flag_char && !(flag_char >= '1' && flag_char <= '9')) {
        for (flag_utils.j = 0; flag_utils.j < symbols_allowed_len;
        flag_utils.j++) {
            len_local = find_right_index_int(flag_utils, len_local, value,
            isdisplaying);
        }
        flag_char = flag_utils.flag_res[++flag_utils.i];
    }
    return (len_local);
}

int my_put_int_display(int len, int len_local, long long_value, int precision)
{
    for (int e = 0; e < (precision - len_local); e++) {
        my_put_nbr(0);
        len++;
    }
    len += len_local;
    my_put_nbr(long_value);
    return len;
}

int my_put_int_helper(int *fflag_output, int len, long long_value,
valuesbox_t flag_utils)
{
    int len_local = my_intlen(long_value);
    int precision = (fflag_output[2] == 'p') ? fflag_output[3] : 0;

    if (fflag_output[0] != 'e') {
        if (flag_utils.flag == 'u' && long_value < 0)
            long_value += 4294967296;
        len = my_put_int_display(len, len_local, long_value, precision);
    } else {
        len += my_strlen(flag_utils.flag_res);
        my_putstr(flag_utils.flag_res);
    }
    return (len);
}
