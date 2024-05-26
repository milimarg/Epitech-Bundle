##
## EPITECH PROJECT, 2023
## B-MAT-100-STG-1-1-105torus-florent.guittre
## File description:
## display
##

def display(x, precision):
    if (len(str(x)) >= precision + 2):
        print(f"x = {x:.{precision}f}")
    else:
        print(f"x = {x}")
