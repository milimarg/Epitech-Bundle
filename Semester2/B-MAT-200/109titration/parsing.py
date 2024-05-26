from sys import argv
import os


def get_parsing():
    argc = len(argv)
    if argc != 2:
        exit(84)
    try:
        f = open(argv[1], "r")
    except (PermissionError, FileNotFoundError):
        exit(84)
    if os.stat(argv[1]).st_size == 0:
        exit(84)
    result = f.read().split("\n")
    for i in range(len(result)):
        if result[i] == '':
            result.pop(i)
    for i in range(len(result)):
        result[i] = result[i].split(";")
        for j in range(len(result[i])):
            try:
                result[i][j] = float(result[i][j])
                if result[i][j] < 0 or (j == 1 and result[i][j] > 14):
                    exit(84)
            except ValueError:
                exit(84)
    f.close()
    return result
