/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGRUSH2-florent.guittre
** File description:
** tests_char.c
*/

#include <criterion/criterion.h>
#include "../new.h"
#include "../char.h"

Test(Char, addition)
{
    Object *a = new(Char, 8);
    Object *b = new(Char, 2);
    Object *add = addition(a, b);
    Object *result = new(Char, 10);
    char *str = NULL;

    cr_assert(eq(add, result));
    str = str(result);
    cr_assert_str_eq(str, "<Char (\n)>");

    delete(a);
    delete(b);
    delete(add);
    delete(result);
    free(str);
}

Test(Char, substraction)
{
    Object *a = new(Char, 10);
    Object *b = new(Char, 2);
    Object *sub = subtraction(a, b);
    Object *result = new(Char, 8);

    cr_assert(eq(sub, result));
    cr_assert(gt(a, result));

    delete(a);
    delete(b);
    delete(sub);
    delete(result);
}

Test(Char, multiplication)
{
    Object *a = new(Char, 10);
    Object *b = new(Char, 2);
    Object *mul = multiplication(a, b);
    Object *result = new(Char, 20);

    cr_assert(eq(mul, result));
    cr_assert(lt(a, result));

    delete(a);
    delete(b);
    delete(mul);
    delete(result);
}

Test(Char, division)
{
    Object *a = new(Char, 10);
    Object *b = new(Char, 2);
    Object *div = division(a, b);
    Object *result = new(Char, 5);

    cr_assert(eq(div, result));

    delete(a);
    delete(b);
    delete(div);
    delete(result);
}
