##
## EPITECH PROJECT, 2023
## B-MAT-100-STG-1-1-105torus-florent.guittre
## File description:
## function
##

def f(x, a0, a1, a2, a3, a4):
    return (a4 * x**4 + a3 * x**3 + a2 * x**2 + a1 * x + a0)

def f_prime(x, a0, a1, a2, a3, a4):
    return (4*a4*x**3 + 3*a3*x**2 + 2*a2*x + a1)
