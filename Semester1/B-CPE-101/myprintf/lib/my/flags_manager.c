/*
** EPITECH PROJECT, 2022
** CPOOL_my_printf
** File description:
** pflag_manager.c
*/

#include <stdlib.h>
#include "../../include/funcs_struct_proto.h"
#include "../../include/pflags_fflags_protos.h"

int width_precision_helper(char *flag_res, int *fflag_output, int i,
char fflag_cat)
{
    int shift = 0;
    int shift_power = 0;
    int nb = 0;
    int fflag_cat_index = (fflag_cat == 'w') ? 1 : 3;
    int isneg = (flag_res[i] == '-') ? (-1) : 1;

    while ((flag_res[i] >= '0' && flag_res[i] <= '9') || flag_res[i] == '-') {
        shift++;
        i++;
    }
    i -= (isneg == -1) ? ((shift--) - 1) : shift;
    while (shift > 0) {
        shift_power = my_compute_power_rec(10, (shift--) - 1);
        nb += (flag_res[i++] - '0') * shift_power;
    }
    fflag_output[fflag_cat_index - 1] = fflag_cat;
    fflag_output[fflag_cat_index] = nb * isneg;
    if (i + 1 != my_strlen(flag_res))
        fflag_output[fflag_cat_index - 1] = 'e';
    return i;
}

void fill_fflag_output(int *fflag_output)
{
    for (int i = 0; i < 4; i += 2) {
        fflag_output[i] = 'n';
        fflag_output[i + 1] = 0;
    }
}

int *fflag_generator(valuesbox_t flag_utils)
{
    char *flag_res = flag_utils.flag_res;
    char flag = flag_utils.flag;
    int flag_res_len = my_strlen(flag_res);
    int *fflag_output = malloc(sizeof(int) * 4);
    int shift = 1;

    fill_fflag_output(fflag_output);
    for (int i = 0; i < flag_res_len; i++) {
        if (((flag_res[i + 1] >= '0' && flag_res[i + 1] <= '9')
        || flag_res[i + 1] == '-') && flag_res[i] != '.') {
            i = width_precision_helper(flag_res, fflag_output, i + 1, 'w');
        }
        if (flag_res[i] == '.')
            i = width_precision_helper(flag_res, fflag_output, i + 1, 'p');
    }
    return (fflag_output);
}

int pflag_replacer(int vab_nb, valuesbox_t flag_utils, va_list list, int len)
{
    char *vabs = "disc%SupfnFoxXeEgGaAb";
    int (*pflags[])(va_list, int, int *, valuesbox_t) =
    {&check_d, &check_i, &check_s, &check_c, &check_prc, &check_sup,
    &check_u, &check_p, &check_f, &check_n, &check_fup, &check_o, &check_x,
    &check_xup, &check_e, &check_eup, &check_g, &check_gup,
    &check_a, &check_aup, &check_b};
    int *fflag_output = fflag_generator(flag_utils);

    for (int i = 0; i < vab_nb; i++)
        if (vabs[i] == flag_utils.flag)
            len = pflags[i](list, len, fflag_output, flag_utils);
    free(fflag_output);
    return len;
}
