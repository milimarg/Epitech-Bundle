/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** tests_MUL_DIV.c
*/

#include <stdio.h>
#include <criterion/criterion.h>

void mul_div_long(int a, int b, int *mul, int *div);
void mul_div_short(int *a, int *b);

Test(mul_div_long, main_test)
{
    int a = 13;
    int b = 4;
    int mul = 0;
    int div = 0;
    mul_div_long(a, b, &mul, &div);
    cr_assert_eq(mul, 52);
    cr_assert_eq(div, 3);
}

Test(mul_div_long, input_is_null)
{
    int a = 13;
    int b = 4;
    int mul_res = -1;
    int div_res = -1;

    mul_div_long(a, b, NULL, NULL);
    cr_assert_eq(mul_res, -1);
    cr_assert_eq(div_res, -1);
}

Test(mul_div_long, divide_by_zero)
{
    int a = 13;
    int b = 0;
    int mul = 0;
    int div = 0;
    mul_div_long(a, b, &mul, &div);
    cr_assert_eq(mul, 0);
    cr_assert_eq(div, 42);
}

Test(mul_div_short, main_test)
{
    int a = 12;
    int b = 0;
    int mul_res = a;
    int div_res = b;
    mul_div_short(&mul_res, &div_res);
    cr_assert_eq(mul_res, 0);
    cr_assert_eq(div_res, 42);
}

Test(mul_div_short, input_is_null)
{
    int mul_res = -1;
    int div_res = -1;

    mul_div_short(NULL, NULL);
    cr_assert_eq(mul_res, -1);
    cr_assert_eq(div_res, -1);
}
