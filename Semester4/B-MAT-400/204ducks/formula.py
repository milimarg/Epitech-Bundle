from math import exp, sqrt


def run_formula(a, t, z):
    if z == 0:
        return -a * exp(-t) - (4 - 3 * a) / 2 * exp(-2 * t) - (2 * a - 4) / 4 * exp(-4 * t)
    return a * exp(-t) + (4 - 3 * a) * exp(-2 * t) + (2 * a - 4) * exp(-4 * t)


def calculate_average_return_time(a):
    result = 0
    t: float = 0

    while t < 10:
        result += run_formula(a, t, 1) * t / 1000
        t += 0.001
    return result


def calculate_when_do_ducks_come_back(a, percent, start):
    t: float = 0

    while t < 1000:
        if run_formula(a, t / 60, 0) - run_formula(a, start, 0) >= percent:
            return t
        t += 0.001


def calculate_standard_deviation(a, average_time, start):
    result = 0
    t: float = 0

    while t < 100:
        result += ((t - average_time) ** 2) * run_formula(a, t, 1) / 1000
        t += 0.001
    return sqrt(result)
