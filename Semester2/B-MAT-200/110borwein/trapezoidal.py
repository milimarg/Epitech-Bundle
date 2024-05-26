from math import pi
from calc_interval import calc_integral_trapezoidal


def calc_trapezoidal(n, start, end, shift):
    result = []
    while start < end:
        result.append(calc_integral_trapezoidal(start, start + shift, n))
        start += shift
    i0 = sum(result)
    diff = abs(i0 - (pi / 2))
    diff = "{:.10f}".format(diff)
    print("\nTrapezoidal:")
    print(f"I{n} = {i0:.10f}")
    print(f"diff = {diff}")
