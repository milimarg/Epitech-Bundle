from math import sqrt


def calculate_variance(p, s_size, p_size):
    return (((p * (100 - p)) / 10000) / s_size) * ((p_size - s_size) / (p_size - 1))


def calculate_95_confidence(variance):
    if variance <= 0:
        exit(84)
    return 2 * 1.96 * sqrt(variance)


def calculate_98_confidence(variance):
    if variance <= 0:
        exit(84)
    return 2 * 2.58 * sqrt(variance)


def clamp(percentage):
    if percentage < 0:
        return 0
    if percentage > 100:
        return 100
    return percentage
