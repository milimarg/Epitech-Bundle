##
## EPITECH PROJECT, 2023
## B-MAT-100-STG-1-1-105torus-florent.guittre
## File description:
## secant
##

import function, display
from math import fabs

def run_secant(precision, a0, a1, a2, a3, a4):
    a = 0
    b = 1
    n = 0
    precision_under_zero = pow(10, -precision)
    while b - a > precision_under_zero:
        x = a - function.f(a, a0, a1, a2, a3, a4) * ((a - b) / (function.f(a, a0, a1, a2, a3, a4) - function.f(b, a0, a1, a2, a3, a4)))
        display.display(x, precision)
        fx = function.f(x, a0, a1, a2, a3, a4)
        if (fabs(fx) < precision_under_zero):
            return (x)
        elif (function.f(a, a0, a1, a2, a3, a4) * fx) < 0:
            b = x
        else:
            a = x
        n += 1
        if (n > 30):
            exit (0)
