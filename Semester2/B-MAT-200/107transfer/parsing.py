from sys import argv


def get_parsing():
    exp = []
    argc = len(argv)
    if argc == 1 or (argc - 1) % 2 == 1:
        exit(84)
    for i in range(1, argc):
        result = argv[i].split("*")
        for j in range(len(result)):
            try:
                result[j] = int(result[j])
            except ValueError:
                exit(84)
        exp.append(result)
    return exp
