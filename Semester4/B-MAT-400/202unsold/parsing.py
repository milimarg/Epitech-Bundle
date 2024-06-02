from sys import argv


def parser():
    if len(argv) != 3:
        exit(84)
    try:
        a = int(argv[1])
        b = int(argv[2])
    except:
        exit(84)
    if a <= 50 or b <= 50:
        exit(84)
    return a, b
