#
# EPITECH PROJECT, 2023
# B-MAT-200-STG-2-1-106bombyx-florent.guittre
# File description:
# generation.py
#

def calc_next_gen(x_i, k):
    return k * x_i * ((1000 - x_i) / 1000)


def generation_mode_0(x_i, k):
    for i in range(1, 101):
        print(f"{i} {x_i:.2f}")
        x_i = calc_next_gen(x_i, k)
        if x_i < 0:
            x_i = 0


def generation_mode_1(x_i, i0, i1):
    shift = 1
    start = x_i
    while shift <= 4:
        x_i = start
        for i in range(int(start), int(i1) + 1):
            x_i = calc_next_gen(x_i, shift)
            if x_i < 0:
                x_i = 0
            if i >= i0:
                print(f"{shift:.2f} {x_i:.2f}")
        shift += 0.01
