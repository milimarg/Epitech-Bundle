#
# EPITECH PROJECT, 2023
# B-MAT-200-STG-2-1-106bombyx-florent.guittre
# File description:
# parsing.py
#

import sys


def get_parsing():
    argv = sys.argv
    argc = len(argv)
    if argc < 3 or argc > 4:
        exit(84)
    try:
        for i in range(1, argc):
            argv[i] = float(argv[i])
    except ValueError:
        exit(84)
    mode_nb = argc == 3
    n = argv[1]
    if n < 0:
        exit(84)
    if mode_nb:
        k = argv[2]
        if k < 1 or k > 4:
            exit(84)
        return mode_nb, n, k
    else:
        i0 = argv[2]
        i1 = argv[3]
        if i0 > i1:
            exit(84)
        return mode_nb, n, [i0, i1]
