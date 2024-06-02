/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGRUSH2-florent.guittre
** File description:
** tests_int.c
*/

#include <criterion/criterion.h>
#include "../new.h"
#include "../int.h"

Test(Int, addition)
{
    Object *a = new(Int, 10);
    Object *b = new(Int, 2);
    Object *add = addition(a, b);
    Object *result = new(Int, 12);
    char *str = NULL;

    cr_assert(eq(add, result));
    str = str(result);
    cr_assert_str_eq(str, "<Int (12)>");

    delete(a);
    delete(b);
    delete(add);
    delete(result);
    free(str);
}

Test(Int, substraction)
{
    Object *a = new(Int, 10);
    Object *b = new(Int, 2);
    Object *sub = subtraction(a, b);
    Object *result = new(Int, 8);

    cr_assert(eq(sub, result));
    cr_assert(gt(a, result));

    delete(a);
    delete(b);
    delete(sub);
    delete(result);
}

Test(Int, multiplication)
{
    Object *a = new(Int, 10);
    Object *b = new(Int, 2);
    Object *mul = multiplication(a, b);
    Object *result = new(Int, 20);

    cr_assert(eq(mul, result));
    cr_assert(lt(a, result));

    delete(a);
    delete(b);
    delete(mul);
    delete(result);
}

Test(Int, division)
{
    Object *a = new(Int, 10);
    Object *b = new(Int, 2);
    Object *div = division(a, b);
    Object *result = new(Int, 5);

    cr_assert(eq(div, result));

    delete(a);
    delete(b);
    delete(div);
    delete(result);
}
