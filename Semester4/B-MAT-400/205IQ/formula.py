from math import sqrt, pi, e


def calculate_formula(u, s, x):
    return (1 / (s * sqrt(2 * pi))) * e ** -(pow(x - u, 2) / (2 * pow(s, 2)))


def run_iq_calculator(liste, iq1, iq2, verbose=False):
    result = []
    temp_iq1 = iq1

    while temp_iq1 <= iq2:
        result.append(calculate_formula(liste[0], liste[1], temp_iq1))
        if len(liste) == 2:
            print(f"{temp_iq1} {result[-1]:.5f}")
            temp_iq1 += 1
        else:
            temp_iq1 += 0.001
    value = sum(result)
    if len(liste) == 3:
        print(f"{(value / 10):.1f}% of people have an IQ inferior to {int(iq2)}")
    if len(liste) == 4:
        print(f"{(value / 10):.1f}% of people have an IQ between {int(iq1)} and {int(iq2)}")
