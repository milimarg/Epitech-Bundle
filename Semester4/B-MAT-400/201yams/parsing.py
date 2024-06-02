from sys import argv

if len(argv) != 7:
    exit(84)


def parsing():
    values = argv[1:6]
    case = argv[6]
    for i in range(len(values)):
        try:
            values[i] = int(values[i])
            if values[i] < 0 or values[i] > 6:
                exit(84)
        except ValueError:
            exit(84)
    case_split = case.split("_")
    if len(case_split) < 2 or len(case_split) > 3:
        exit(84)
    try:
        case_split[1] = int(case_split[1])
        if len(case_split) == 3:
            case_split[2] = int(case_split[2])
    except ValueError:
        exit(84)
    case_name = case_split[0]
    if case_name == "full" and len(case_split) != 3 or \
            case_name != "full" and len(case_split) == 3:
        exit(84)
    return values, case_name, case_split[1], case_split[2] if len(case_split) == 3 else None
