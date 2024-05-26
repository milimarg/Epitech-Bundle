##
## EPITECH PROJECT, 2022
## B-MAT-100-STG-1-1-104intersection-florent.guittre
## File description:
## calculus
##

from math import sqrt

def resolve(a, b ,c):
    delta = b**2 - 4 * a * c
    if delta > 0:
        x1 = (-b + sqrt(delta)) / (2 * a)
        x2 = (-b - sqrt(delta)) / (2 * a)
        return float(x1), float(x2)
    elif delta == 0:
        if a != 0:
            x1 = -b / (2 * a)
            return float(x1), "nosol"
        else:
            return "nosol", "infinity"
    else:
        return "nosol", "nosol"