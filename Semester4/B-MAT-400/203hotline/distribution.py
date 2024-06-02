from math import comb, e, factorial
from time import time


def calculate_binomial(n, k, p):
    return comb(n, k) * pow(p, k) * pow(1 - p, (n - k))


def calculate_poisson(n, k, p):
    magic = (n * p)
    return ((e ** -magic) * (magic ** k)) / factorial(k)


def distribution(seconds, time1, is_poisson):
    print(f"{'Poisson' if is_poisson else 'Binomial'} distribution:")
    value = seconds / (8 * 3600)
    overload = 0
    for i in range(51):
        if not is_poisson:
            result = calculate_binomial(3500, i, value)
        else:
            result = calculate_poisson(3500, i, value)
        if i < 26:
            overload += result
        print(f"{i} -> {result:.3f}", end='')
        if (i + 1) % 5 == 0 or i == 50:
            print()
        else:
            print("", end='\t')
    print(f"Overload: {((1 - overload) * 100):.1f}%")
    time2 = time()
    print(f"Computation time: {((time2 - time1) * 100):.2f} ms")
