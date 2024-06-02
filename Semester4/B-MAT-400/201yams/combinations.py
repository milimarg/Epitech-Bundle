from collections import Counter
from math import comb, factorial


def simulate_pair(values, combination_number, sec_combination_number):
    n = 5 - Counter(values)[combination_number]
    probability = 0

    for x in range(2 - Counter(values)[combination_number], 5 - Counter(values)[combination_number] + 1):
        probability += comb(n, x) * (1 / 6) ** x * (1 - (1 / 6)) ** (n - x)
    return f"Chances to get a {combination_number} pair: {(probability * 100):.2f}%"


def simulate_three(values, combination_number, sec_combination_number):
    n = 5 - Counter(values)[combination_number]
    probability = 0

    for x in range(3 - Counter(values)[combination_number], 5 - Counter(values)[combination_number] + 1):
        probability += comb(n, x) * (1 / 6) ** x * (1 - (1 / 6)) ** (n - x)
    return f"Chances to get a {combination_number} three-of-a-kind: {(probability * 100):.2f}%"


def simulate_four(values, combination_number, sec_combination_number):
    n = 5 - Counter(values)[combination_number]
    probability = 0

    for x in range(4 - Counter(values)[combination_number], 5 - Counter(values)[combination_number] + 1):
        probability += comb(n, x) * (1 / 6) ** x * (1 - (1 / 6)) ** (n - x)
    return f"Chances to get a {combination_number} four-of-a-kind: {(probability * 100):.2f}%"


def simulate_full(values, combination_number, sec_combination_number):
    first = abs(3 - Counter(values)[combination_number])
    second = abs(2 - Counter(values)[sec_combination_number])
    if first == 0 and second == 0:
        return f"Chances to get a {combination_number} full of {sec_combination_number}: 100.00%"

    probability = comb(first + second, first) * (1 / 6) ** first * (1 / 6) ** second

    return f"Chances to get a {combination_number} full of {sec_combination_number}: {(probability * 100):.2f}%"


def simulate_straight(values, combination_number, sec_combination_number):
    if combination_number < 5 or combination_number > 6:
        exit(84)
    liste = [1, 2, 3, 4, 5, 6]
    a_relancee = 0
    liste_values = Counter(values)
    if combination_number == 5:
        liste.pop()
        a_relancee += liste_values[6]
        for i in liste_values:
            if liste_values[i] > 1:
                a_relancee += liste_values[i] - 1
    else:
        liste.pop(0)
        a_relancee += liste_values[1]
        for i in liste_values:
            if liste_values[i] > 1:
                a_relancee += liste_values[i] - 1

    probability = factorial(a_relancee) / (6 ** a_relancee)

    return f"Chances to get a {combination_number} straight: {(probability * 100):.2f}%"


def simulate_yams(values, combination_number, sec_combination_number):
    probability = 1 / (6 ** (5 - Counter(values)[combination_number]))
    return f"Chances to get a {combination_number} yams: {(probability * 100):.2f}%"
