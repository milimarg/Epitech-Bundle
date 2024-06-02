/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGRUSH2-florent.guittre
** File description:
** tests_float.c
*/

#include <criterion/criterion.h>
#include "../new.h"
#include "../float.h"

Test(Float, addition)
{
    Object *a = new(Float, 10.0f);
    Object *b = new(Float, 2.0f);
    Object *add = addition(a, b);
    Object *result = new(Float, 12.0f);
    char *str = NULL;

    cr_assert(eq(add, result));
    str = str(result);
    cr_assert_str_eq(str, "<Float (12.000000)>");

    delete(a);
    delete(b);
    delete(add);
    delete(result);
    free(str);
}

Test(Float, substraction)
{
    Object *a = new(Float, 10.0f);
    Object *b = new(Float, 2.0f);
    Object *sub = subtraction(a, b);
    Object *result = new(Float, 8.0f);

    cr_assert(eq(sub, result));
    cr_assert(gt(a, result));

    delete(a);
    delete(b);
    delete(sub);
    delete(result);
}

Test(Float, multiplication)
{
    Object *a = new(Float, 10.0f);
    Object *b = new(Float, 2.0f);
    Object *mul = multiplication(a, b);
    Object *result = new(Float, 20.0f);

    cr_assert(eq(mul, result));
    cr_assert(lt(a, result));

    delete(a);
    delete(b);
    delete(mul);
    delete(result);
}

Test(Float, division)
{
    Object *a = new(Float, 10.0f);
    Object *b = new(Float, 2.0f);
    Object *div = division(a, b);
    Object *result = new(Float, 5.0f);

    cr_assert(eq(div, result));

    delete(a);
    delete(b);
    delete(div);
    delete(result);
}
