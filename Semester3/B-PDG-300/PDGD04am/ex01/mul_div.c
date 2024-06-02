/*
** EPITECH PROJECT, 2024
** B-PDG-300-STG-3-1-PDGD04am-florent.guittre
** File description:
** mul_div.c
*/

#include <stddef.h>

void mul_div_long(int a, int b, int *mul, int *div)
{
    if (mul == NULL || div == NULL) {
        return;
    }
    *mul = a * b;
    *div = b == 0 ? 42 : a / b;
}

void mul_div_short(int *a, int *b)
{
    int mul = 0;
    int div = 0;

    if (a == NULL || b == NULL) {
        return;
    }
    mul = *a * *b;
    div = *b == 0 ? 42 : *a / *b;
    *a = mul;
    *b = div;
}
