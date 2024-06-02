from sys import argv


def parsing():
    argc = len(argv)
    if argc != 2:
        exit(84)
    try:
        a = float(argv[1])
    except:
        exit(84)
    if a < 0 or a > 2.5:
        exit(84)
    return a
