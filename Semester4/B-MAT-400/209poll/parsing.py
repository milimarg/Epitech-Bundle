from sys import argv


def parse():
    argc = len(argv)
    if argc != 4:
        exit(84)
    try:
        argv[1] = int(argv[1])
        argv[2] = int(argv[2])
        argv[3] = float(argv[3])
        for i in range(1, argc):
            if argv[i] <= 0:
                exit(84)
        if argv[3] > 100:
            exit(84)
    except:
        exit(84)
    return argv[1:]
