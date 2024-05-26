/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-corewar-florent.guittre
** File description:
** ft_and.c
*/

#include "../srcs/vm.h"

/*
** Instructions: Apply an & (bit-to-bit AND) over the first two arguments
** and store the result in a registry, which is the third argument.
** Opcode 0x06. Modifies the carry.
** T_REG | T_v.ind | T_DIR, T_REG | T_v.ind | T_DIR, T_REG
*/

static void    ft_and_5(t_env *e, t_cursor *cursor, t_var v)
{
    if (ZMASK(v.acb) == IDR) {
        v.r3 = e->a[MODA(cursor->index + 8)].hex;
        if (ft_is_reg(v.r3 - 1, v.r3 - 1, v.r3 - 1) && (v.carry = 1))
            cursor->reg[v.r3 - 1] = get_ind(e, cursor, 2) &
            get_dir(e, cursor, 4, 4);
        ft_update_cursor(e, cursor, 9);
    } else if (ZMASK(v.acb) == RDR) {
        v.r1 = e->a[MODA(cursor->index + 2)].hex;
        v.r3 = e->a[MODA(cursor->index + 7)].hex;
        cursor->reg[v.r3 - 1] = (ft_is_reg(v.r1 - 1, v.r3 - 1, v.r3 - 1) &&
        (v.carry = 1)) ? (cursor->reg[v.r1 - 1] & get_dir(e, cursor, 3, 4)) :
        cursor->reg[v.r3 - 1];
        ft_update_cursor(e, cursor, 8);
    }
    if (v.carry)
        cursor->carry = (!cursor->reg[v.r3 - 1]) ? 1 : 0;
}

static void ft_and_4(t_env *e, t_cursor *cursor, t_var v)
{
    if (ZMASK(v.acb) == DIR) {
        v.r3 = e->a[MODA(cursor->index + 8)].hex;
        if (ft_is_reg(v.r3 - 1, v.r3 - 1, v.r3 - 1) && (v.carry = 1))
            cursor->reg[v.r3 - 1] = get_dir(e, cursor, 2, 4) &
            get_ind(e, cursor, 6);
        ft_update_cursor(e, cursor, 9);
    } else if (ZMASK(v.acb) == IIR) {
        v.r3 = e->a[MODA(cursor->index + 6)].hex;
        cursor->reg[v.r3 - 1] = (ft_is_reg(v.r3 - 1, v.r3 - 1, v.r3 - 1) &&
        (v.carry = 1)) ? get_ind(e, cursor, 2) & get_ind(e, cursor, 4) :
        cursor->reg[v.r3 - 1];
        ft_update_cursor(e, cursor, 7);
    } else
        ft_and_5(e, cursor, v);
    if (v.carry)
        cursor->carry = (!cursor->reg[v.r3 - 1]) ? 1 : 0;
}

static void ft_and_3(t_env *e, t_cursor *cursor, t_var v)
{
    if (ZMASK(v.acb) == DRR) {
        v.r1 = e->a[MODA(cursor->index + 6)].hex;
        v.r3 = e->a[MODA(cursor->index + 7)].hex;
        if (ft_is_reg(v.r1 - 1, v.r3 - 1, v.r3 - 1) && (v.carry = 1))
            cursor->reg[v.r3 - 1] = cursor->reg[v.r1 - 1] &
            get_dir(e, cursor, 2, 4);
        ft_update_cursor(e, cursor, 8);
    } else if (ZMASK(v.acb) == DDR) {
        v.r3 = e->a[MODA(cursor->index + 10)].hex;
        cursor->reg[v.r3 - 1] = ((ft_is_reg(v.r3 - 1, v.r3 - 1, v.r3 - 1) &&
        (v.carry = 1))) ? get_dir(e, cursor, 2, 4) & get_dir(e, cursor, 6, 4) :
        cursor->reg[v.r3 - 1];
        ft_update_cursor(e, cursor, 11);
    } else
        ft_and_4(e, cursor, v);
    if (v.carry)
        cursor->carry = (!cursor->reg[v.r3 - 1]) ? 1 : 0;
}

static void ft_and_2(t_env *e, t_cursor *cursor, t_var v)
{
    if (ZMASK(v.acb) == RIR) {
        v.r1 = e->a[MODA(cursor->index + 2)].hex;
        v.r3 = e->a[MODA(cursor->index + 5)].hex;
        if (ft_is_reg(v.r1 - 1, v.r3 - 1, v.r3 - 1) && (v.carry = 1))
            cursor->reg[v.r3 - 1] = cursor->reg[v.r1 - 1] &
            get_ind(e, cursor, 3);
        ft_update_cursor(e, cursor, 6);
    } else if (ZMASK(v.acb) == IRR) {
        v.r1 = e->a[MODA(cursor->index + 4)].hex;
        v.r3 = e->a[MODA(cursor->index + 5)].hex;
        cursor->reg[v.r3 - 1] = ((ft_is_reg(v.r1 - 1, v.r3 - 1, v.r3 - 1) &&
        (v.carry = 1))) ? cursor->reg[v.r1 - 1] & get_ind(e, cursor, 2) :
        cursor->reg[v.r3 - 1];
        ft_update_cursor(e, cursor, 6);
    } else
        ft_and_3(e, cursor, v);
    if (v.carry)
        cursor->carry = (!cursor->reg[v.r3 - 1]) ? 1 : 0;
}

void ft_and(t_env *e, t_cursor *cursor)
{
    t_var v = {0};

    ft_init_v(e, cursor, &v);
    if (ZMASK(v.acb) == RRR) {
        v.r1 = e->a[MODA(cursor->index + 2)].hex;
        v.r2 = e->a[MODA(cursor->index + 3)].hex;
        v.r3 = e->a[MODA(cursor->index + 4)].hex;
        cursor->reg[v.r3 - 1] = ((ft_is_reg(v.r1 - 1, v.r2 - 1, v.r3 - 1) &&
        (v.carry = 1))) ? cursor->reg[v.r1 - 1] & cursor->reg[v.r2 - 1] :
        cursor->reg[v.r3 - 1];
        ft_update_cursor(e, cursor, 5);
    } else
        ft_and_2(e, cursor, v);
    if (v.carry)
        cursor->carry = (!cursor->reg[v.r3 - 1]) ? 1 : 0;
}
