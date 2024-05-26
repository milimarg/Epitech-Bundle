##
## EPITECH PROJECT, 2023
## B-MAT-100-STG-1-1-105torus-florent.guittre
## File description:
## newton
##

import function, display
from math import fabs

def run_newton(precision, a0, a1, a2, a3, a4):
    a = 0.5
    b = 1
    n = 0
    last_value = 0.0
    precision_under_zero = pow(10, -precision)
    x = a
    while x > precision_under_zero:
        display.display(x, precision)
        x = x - (function.f(x, a0, a1, a2, a3, a4) / function.f_prime(x, a0, a1, a2, a3, a4))
        if (fabs(last_value - x) < precision_under_zero):
            exit (0)
        last_value = x
        n += 1
        if (n > 30):
            exit (0)
