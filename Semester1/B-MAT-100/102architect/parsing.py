##
## EPITECH PROJECT, 2022
## 102architect
## File description:
## parsing.py
##

import sys

def check_number_of_arguments(argc, argv, args_list, args_arg_nb):
    args_nb = 0
    moves_nb = 0
    for i in range(argc):
        for j in range(len(args_list)):
            if (argv[i] == args_list[j]):
                moves_nb += 1
                args_nb += args_arg_nb[j]
    if (argc != args_nb + moves_nb + 3):
        sys.exit(84)

def check_if_number_coordinate(x, y):
    try:
        x = int(x)
        y = int(y)
    except:
        sys.exit(84)
    return (x, y)

def check_if_number_angle(angle):
    try:
        angle = int(angle)
    except:
        sys.exit(84)
    return (angle)
