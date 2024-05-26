from sys import argv

def get_parsing():
    argc = len(argv)
    if argc != 2:
        exit(84)
    try:
        argv[1] = int(argv[1])
    except ValueError:
        exit(84)
    if argv[1] < 0:
        exit(84)
    return argv[1]
