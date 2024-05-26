/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_lld.c
*/

#include "../srcs/vm.h"

/*
** Instructions:
** Means long-load. Same as ld, but without % IDX_MOD.
** No % IDX_MOD
** Modify the carry
*/

static void ft_dr(t_env *e, t_cursor *cursor, int opc_ind)
{
    int value = get_bytes(e, cursor, opc_ind + 2);

    if (e->a[MODA(opc_ind + 2 + 4)].hex - 1 >= 1 &&
    e->a[MODA(opc_ind + 2 + 4)].hex - 1 <= REG_NUMBER) {
        cursor->reg[e->a[MODA(opc_ind + 2 + 4)].hex - 1] = value;
        cursor->carry = (value == 0);
    }
    ft_update_cursor(e, cursor, 7);
}

static void ft_ir(t_env *e, t_cursor *cursor, int opc_ind)
{
    unsigned short r = ((ZMASK(e->a[MODA(opc_ind + 2)].hex) << 8) |
    ZMASK(e->a[MODA(opc_ind + 3)].hex));
    int value = get_bytes(e, cursor, (short)r + opc_ind);

    if (e->a[MODA((opc_ind + 2 + 2))].hex - 1 >= 1 &&
    e->a[MODA(opc_ind + 2 + 2)].hex - 1 <= REG_NUMBER)
    cursor->reg[e->a[MODA(opc_ind + 2 + 2)].hex - 1] = value;
            cursor->carry = (value == 0);
    ft_update_cursor(e, cursor, 5);
}

void ft_lld(t_env *e, t_cursor *cursor)
{
    int opc_ind = cursor->index;
    char acb = e->a[MODA(opc_ind + 1)].hex;

    if (DR == ZMASK(acb))
        ft_dr(e, cursor, opc_ind);
    else if (IR == ZMASK(acb))
        ft_ir(e, cursor, opc_ind);
}
