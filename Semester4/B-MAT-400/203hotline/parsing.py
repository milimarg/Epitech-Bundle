from sys import argv


def parsing():
    argc = len(argv)
    ret = [0, 0]
    if argc < 2 or argc > 3:
        exit(84)
    if argc == 2:
        ret[0] = int(argv[1])
        if ret[0] <= 0:
            exit(84)
    if argc == 3:
        try:
            ret[0] = int(argv[1])
            ret[1] = int(argv[2])
        except:
            exit(84)
        if ret[0] <= 0 or ret[1] <= 0:
            exit(84)
    return ret, argc
