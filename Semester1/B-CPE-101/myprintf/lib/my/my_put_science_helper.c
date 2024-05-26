/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** idk_launcher.c
*/

#include "../../include/funcs_struct_proto.h"
#include "../../include/pflags_fflags_protos.h"

int my_put_science_helper(int *fflag_output, int len, double double_value,
char **values)
{
    char *flag_res = values[0];
    char science_e = values[1][0];
    int precision = (fflag_output[2] == 'p') ? fflag_output[3] : 6;
    int len_local = my_put_science(double_value, science_e, 0, precision);
    int width = fflag_output[1];

    if (fflag_output[0] != science_e) {
        if (width > 0)
            len += thefor(width, len_local, ' ');
        len += my_put_science(double_value, science_e, 1, precision);
        if (width < 0)
            len += thefor(width, len_local, ' ');
    } else {
        len += my_strlen(flag_res);
        my_putstr(flag_res);
    }
    return (len);
}
