from sys import argv


def get_parsing():
    argc = len(argv)
    if argc != 5:
        exit(84)

    for i in range(1, argc):
        try:
            argv[i] = float(argv[i])
            if argv[i] <= 0:
                exit(84)
        except:
            exit(84)
    return argv
