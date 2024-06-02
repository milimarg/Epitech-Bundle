from sys import argv


def parse():
    argc = len(argv)
    if argc != 10:
        exit(84)
    for i in range(1, len(argv)):
        try:
            argv[i] = int(argv[i])
            if argv[i] <= 0:
                exit(84)
        except:
            exit(84)
    return argv[1:]
