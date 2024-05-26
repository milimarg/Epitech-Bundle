from math import sin


def calc_f(x, n):
    k = 0
    result = 1
    for i in range(k, n + 1):
        try:
            result *= (sin(x / (2 * i + 1))) / (x / (2 * i + 1))
        except ZeroDivisionError:
            result *= 1
    return result


def calc_interval_midpoint(a, b, n):
    return (b - a) * calc_f(((a + b) / 2), n)


def calc_integral_trapezoidal(a, b, n):
    return ((b - a) / 2) * (calc_f(a, n) + calc_f(b, n))


def calc_integral_simpson(a, b, n):
    return ((b - a) / 6) * (calc_f(a, n) + (4 * calc_f((a + b) / 2, n)) + calc_f(b, n))
