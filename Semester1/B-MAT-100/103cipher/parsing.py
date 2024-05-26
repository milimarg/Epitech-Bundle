##
## EPITECH PROJECT, 2022
## B-MAT-100-STG-1-1-103cipher-florent.guittre
## File description:
## parsing
##

import sys

def get_arguments():
    argv = sys.argv
    argc = len(argv)
    if (argc != 4):
        sys.exit(84)
    message = argv[1]
    key = argv[2]
    flag = argv[3]
    if (len(key) > 9):
        sys.exit(84)
    try:
        flag = int(flag)
    except:
        sys.exit(84)
    if (flag != 0 and flag != 1):
        sys.exit(84)
    return (message, key, flag)
