/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_st.c
*/

#include "../srcs/vm.h"

/*
** Instructions:
** Take a registry and a registry or an indirect and store the value of the
** registry toward a second argument. Its opcode is 0x03. For example, st r1, 42
** store the value of r1 at the address (PC + (42 % IDX_MOD))
*/

static int get_short(t_env *e, int r)
{
    unsigned short ret = 0;

    ret = ((ZMASK(e->a[MODA(r)].hex) << 8) | ZMASK(e->a[MODA(r + 1)].hex));
    return ((short)ret);
}

static void ft_ri(t_env *e, t_cursor *cursor, int p1, int p2)
{
    int v = 0;
    int i = -1;

    p2 = (get_short(e, cursor->index + 3));
    p2 = MODX(p2);
    while ((i > 0 || ft_is_reg(p1 - 1, 0, 0)) && ++i < 4) {
        v = cursor->index + p2 + i;
        e->a[MODA((v))].hex = (cursor->reg[p1 - 1] >> (8 * (3 - i))) & 0xff;
        e->a[MODA((v))].color = cursor->color - 6;
        e->a[MODA((v))].prevcolor = cursor->color - 6;
        e->a[MODA((v))].new_color_count = 50;
    }
    ft_update_cursor(e, cursor, 5);
}

void ft_st(t_env *e, t_cursor *cursor)
{
    char acb = e->a[MODA(cursor->index + 1)].hex;
    int p1 = e->a[MODA(cursor->index + 2)].hex;
    short p2 = 0;

    if (RR == ZMASK(acb)) {
        p2 = e->a[MODA(cursor->index + 3)].hex;
        if (ft_is_reg(p1 - 1, p2 - 1, 0))
            cursor->reg[p2 - 1] = cursor->reg[p1 - 1];
        ft_update_cursor(e, cursor, 4);
    } else if (RI == ZMASK(acb))
        ft_ri(e, cursor, p1, p2);
}
