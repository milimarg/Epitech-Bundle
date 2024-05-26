from math import factorial
from matrices import operator_matrix, divide_matrix, copy_matrix


def calc_exp(a, i, is_h, tolerance):
    backup_item = []
    backup_item2 = []
    result = operator_matrix(copy_matrix(i), copy_matrix(a), "+")
    result2 = [[1]]
    n = 2
    factorial_result = 1
    while not result2[0][0] == 0:
        factorial_result *= n
        if n == 2:
            backup_item = operator_matrix(a, a, "*")
        else:
            backup_item = operator_matrix(a, backup_item, "*")
        backup_item2 = divide_matrix(copy_matrix(backup_item), factorial_result)
        result2 = copy_matrix(result)
        result = operator_matrix(backup_item2, result, "+")
        result2[0][0] -= result[0][0]
        n += 1
    return result


def calc_cos(a, i, is_h, tolerance):
    backup_item = []
    backup_item2 = []
    result = copy_matrix(i)
    result2 = [[1]]
    n = 2
    is_plus = is_h
    factorial_result = 1
    while not result2[0][0] == 0:
        factorial_result = factorial(n)
        if n == 2:
            backup_item = operator_matrix(a, a, "*")
        else:
            backup_item = operator_matrix(a, backup_item, "*")
            backup_item = operator_matrix(a, backup_item, "*")
        backup_item2 = divide_matrix(copy_matrix(backup_item), factorial_result)
        result2 = copy_matrix(result)
        if is_plus:
            result = operator_matrix(backup_item2, result, "+")
        else:
            result = operator_matrix(backup_item2, result, "-")
        if not is_h:
            is_plus = not is_plus
        result2[0][0] -= result[0][0]
        n += 2
    return result


def calc_sin(a, i, is_h, tolerance):
    backup_item = []
    backup_item2 = []
    result = copy_matrix(a)
    result2 = [[1]]
    n = 3
    is_plus = is_h
    factorial_result = 1
    while not result2[0][0] == 0:
        factorial_result = factorial(n)
        if n == 3:
            backup_item = operator_matrix(a, result, "*")
            backup_item = operator_matrix(a, backup_item, "*")
        else:
            backup_item = operator_matrix(a, backup_item, "*")
            backup_item = operator_matrix(a, backup_item, "*")
        backup_item2 = divide_matrix(copy_matrix(backup_item), factorial_result)
        result2 = copy_matrix(result)
        if is_plus:
            result = operator_matrix(backup_item2, result, "+")
        else:
            result = operator_matrix(backup_item2, result, "-")
        if not is_h:
            is_plus = not is_plus
        result2[0][0] -= result[0][0]
        n += 2
    return result
