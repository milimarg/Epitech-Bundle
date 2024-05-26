from math import pi
from calc_interval import calc_interval_midpoint


def calc_midpoint(n, start, end, shift):
    result = []
    while start < end:
        result.append(calc_interval_midpoint(start, start + shift, n))
        start += shift
    i0 = sum(result)
    diff = abs(i0 - (pi / 2))
    diff = "{:.10f}".format(diff)
    print("Midpoint:")
    print(f"I{n} = {i0:.10f}")
    print(f"diff = {diff}")
