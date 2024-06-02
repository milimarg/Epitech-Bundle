from math import comb


def display_indices(parsing, max_items, observed, forbidden_number):
    print("  x\t| ", end='')
    i = 0
    last_index = 0
    columns_number = 0
    while i < len(parsing) - 2:
        temp = 0
        can_count_column = False
        print(i, end='')
        temp = parsing[i]
        if temp < max_items:
            while temp < max_items and i < (max_items - 2):
                i += 1
                temp += parsing[i]
            if last_index != i:
                print(f"-{i}", end='')
                columns_number += 1
                can_count_column = True
                observed[i] = parsing[i - 1] + parsing[i]
                observed[observed.index(parsing[i - 1])] = forbidden_number
        else:
            if i < len(parsing) - 2 and \
                    parsing[i + 1] < max_items and \
                    parsing[i + 2] > parsing[i]:
                i += 1
                temp += parsing[i]
                observed[i] = parsing[i] + parsing[i - 1]
                observed[observed.index(parsing[i - 1])] = forbidden_number
                print(f"-{i}", end='')
                can_count_column = True
                columns_number += 1
        last_index = i
        print(f"\t| ", end='')
        i += 1
        if not can_count_column:
            columns_number += 1
    print(f"{i}+\t| Total")
    return columns_number + 1


def display_result(parsing, columns_number, max_items, samples):
    print(" Ox\t| ", end='')
    temp = 0
    i = 0
    while i < len(parsing):
        temp = parsing[i]
        if temp < max_items:
            while temp < max_items and i < (max_items - 2):
                i += 1
                temp += parsing[i]
        else:
            if i < len(parsing) - 2 and \
                    parsing[i + 1] < max_items and \
                    parsing[i + 2] > parsing[i]:
                i += 1
                temp += parsing[i]
        print(f"{temp}\t| ", end='')
        i += 1
    print(f"{samples}")


def display_theoretical(parsing, samples, acc, theoretical, max_items):
    for i in range(len(parsing)):
        theoretical.append((comb(samples, i) * samples) * pow(acc, i) * pow(1 - acc, samples - i))
    theoretical[8] = samples - sum(theoretical) + theoretical[-1]

    print(" Tx\t| ", end='')

    i = 0
    chi = 0
    while i < len(parsing):
        temp = parsing[i]
        temp2 = theoretical[i]
        if temp < max_items:
            while temp < max_items and i < (max_items - 2):
                i += 1
                temp += parsing[i]
                temp2 += theoretical[i]
        else:
            if i < len(parsing) - 2 and \
                    parsing[i + 1] < max_items and \
                    parsing[i + 2] > parsing[i]:
                i += 1
                temp += parsing[i]
                temp2 += theoretical[i]
        chi += pow(temp - temp2, 2) / temp2
        i += 1
        print(f"{temp2:.1f}\t| ", end='')
    print(f"{int(samples)}")
    return chi
