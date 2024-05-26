##
## EPITECH PROJECT, 2022
## B-MAT-100-STG-1-1-105torus-florent.guittre
## File description:
## parsing
##

import sys

def get_args():
    argv = sys.argv
    argc = len(argv)
    if (argc != 8):
        sys.exit(84)
    try:
        opt = int(argv[1])
        a0 = int(argv[2])
        a1 = int(argv[3])
        a2 = int(argv[4])
        a3 = int(argv[5])
        a4 = int(argv[6])
        n = int(argv[7])
    except:
        sys.exit(84)
    if (opt < 1 or opt > 3):
        sys.exit(84)
    if (n < 0):
        sys.exit(84)
    return (opt, a0, a1, a2, a3, a4, n)
