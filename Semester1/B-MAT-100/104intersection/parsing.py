##
## EPITECH PROJECT, 2022
## B-MAT-100-STG-1-1-104intersection-florent.guittre
## File description:
## parsing
##

import sys

def get_args():
    argv = sys.argv
    argc = len(argv)
    if (argc != 9):
        sys.exit(84)
    opt = argv[1]
    xp = argv[2]
    yp = argv[3]
    zp = argv[4]
    xv = argv[5]
    yv = argv[6]
    zv = argv[7]
    p = argv[8]
    try:
        opt = int(opt)
        xp = int(xp)
        yp = int(yp)
        zp = int(zp)
        xv = int(xv)
        yv = int(yv)
        zv = int(zv)
        p = int(p)
    except:
        sys.exit(84)
    if (opt < 0 or opt > 3 or type(opt) != int):
        sys.exit(84)
    return (opt, xp, yp, zp, xv, yv, zv, p)
