##
## EPITECH PROJECT, 2023
## B-MAT-100-STG-1-1-105torus-florent.guittre
## File description:
## bisection
##

import function, display

def run_bisection(precision, a0, a1, a2, a3, a4):
    a, b, n = 0, 1, 0
    precision_under_zero = pow(10, -precision)
    while b - a > precision_under_zero:
        x = (a + b) / 2
        if (function.f(a, a0, a1, a2, a3, a4) * function.f(x, a0, a1, a2, a3, a4)) > 0:
            a = x
        else:
            b = x
        display.display(x, precision)
    n += 1
    if (n > 30):
        exit(0)
