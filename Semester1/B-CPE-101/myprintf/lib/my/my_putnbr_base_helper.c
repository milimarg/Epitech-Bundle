/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** my_putnbr_base_helper
*/

#include "../../include/funcs_struct_proto.h"
#include "../../include/pflags_fflags_protos.h"

int find_right_index_putnbr_base(valuesbox_t flag_utils, int len_local,
int value, int isdisplaying)
{
    char *symbols_char = "+ -0#";
    char flag_char = flag_utils.flag_res[flag_utils.i];
    int (*symbols[])(int, valuesbox_t, long, int) = {&fflag_plus_putnbr_base,
    &fflag_space_putnbr_base, &fflag_dash_putnbr_base, &fflag_zero_putnbr_base,
    &fflag_hashtag_putnbr_base};

    if (flag_utils.symbols_allowed[flag_utils.j] == flag_char)
        for (int k = 0; k < 5; k++)
            len_local = (symbols_char[k] == flag_char) ?
            symbols[k](len_local, flag_utils, value, isdisplaying) : len_local;
    return len_local;
}

int check_fflag_putnbr_base(int len_local, valuesbox_t flag_utils, long value,
int isdisplaying)
{
    char flag_char = '\0';
    int symbols_allowed_len = my_strlen(flag_utils.symbols_allowed);

    flag_utils.i = 1;
    flag_char = flag_utils.flag_res[flag_utils.i];
    while (flag_char && !(flag_char >= '1' && flag_char <= '9')) {
        for (flag_utils.j = 0; flag_utils.j < symbols_allowed_len;
        flag_utils.j++) {
            len_local = find_right_index_putnbr_base(flag_utils, len_local,
            value, isdisplaying);
        }
        flag_char = flag_utils.flag_res[++flag_utils.i];
    }
    return (len_local);
}

int my_putnbr_base_helper(int *fflag_output, int len, long long_value,
char **values)
{
    char *flag_res = values[0];
    char *base = values[1];
    int len_local = my_putnbr_base(long_value, base, 0);
    char flag = flag_res[my_strlen(flag_res) - 1];
    int precision = (fflag_output[2] == 'p') ? fflag_output[3] : 0;

    if (fflag_output[0] != 'e') {
        if (flag == 'p')
            my_putstr("0x");
        for (int e = 0; e < (precision - len_local); e++) {
            my_put_nbr(0);
            len++;
        }
        my_putnbr_base(long_value, base, 1);
        len += len_local;
    } else {
        my_putstr(flag_res);
        len += my_strlen(flag_res);
    }
    return (len);
}
