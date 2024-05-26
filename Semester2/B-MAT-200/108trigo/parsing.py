from sys import argv
from math import sqrt


def get_parsing(funcs):
    argc = len(argv)
    items_nb = argc - 2
    if argc < 3 or sqrt(items_nb) % 1 != 0:
        exit(84)
    if argv[1] not in funcs:
        exit(84)
    for i in range(2, argc):
        try:
            argv[i] = int(argv[i])
        except ValueError:
            exit(84)
    return argv, items_nb
