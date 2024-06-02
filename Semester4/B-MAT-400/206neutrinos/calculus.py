from math import sqrt


def calculate_deviation(x, a, n, input_, dev_result, gloubal, loop=True):
    if not loop:
        dev_result = sqrt(((((pow(x, 2) + pow(a, 2)) * (n - 1.0)) + pow(input_, 2)) / n) - pow((((a * (n - 1.0)) + input_) / n), 2))
        return None, dev_result
    else:
        dev_backup = dev_result
        dev_result = sqrt(((((pow(dev_result, 2) + pow(gloubal, 2)) * (n - 1.0)) + pow(input_, 2)) / n) - pow((((gloubal * (n - 1.0)) + input_) / n), 2))
        return dev_backup, dev_result


def calculate_arithmetic(gloubal, a, n, input_, loop=True):
    if not loop:
        gloubal = a
    gloubal_backup = gloubal
    gloubal = ((gloubal * (n - 1.0)) + input_) / n
    return gloubal, gloubal_backup


def calculate_root_mean_square(dev_backup, gloubal_backup, n, input_, a, sd, loop=True):
    if not loop:
        gloubal_backup_backup = sqrt((((pow(sd, 2) + pow(a, 2)) * (n - 1.0)) + pow(input_, 2)) / n)
        return gloubal_backup_backup
    return sqrt((((pow(dev_backup, 2) + pow(gloubal_backup, 2)) * (n - 1.0)) + pow(input_, 2)) / n)


def calculate_harmonic_mean(h, n, input_, gloubal_backup_backup_backup, loop=True):
    if not loop:
        gloubal_backup_backup_backup = h
    if n != 0 and h != 0:
        gloubal_backup_backup_backup = n / ((1.0 / gloubal_backup_backup_backup * (n - 1.0)) + (1.0 / input_))
        return float(gloubal_backup_backup_backup), gloubal_backup_backup_backup
    else:
        return "cannot compute harmonic"
