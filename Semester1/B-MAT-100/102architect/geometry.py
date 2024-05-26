##
## EPITECH PROJECT, 2022
## 102architect
## File description:
## geometry.py
##

import matrice

def translation(tx, ty, x, y):
    tx += x
    ty += y
    return (tx, ty)

def scaling(tx, ty, x, y):
    x *= tx
    y *= ty
    return (x, y)

def rotation(x, y, matrix1):
    matrix2 = [x, y, 1]
    n = len(matrix1)
    p = len(matrix2)
    m = 3
    result = [[0] * n for _ in range(m)]
    for i in range(p):
        for j in range(m):
            r_ij = 0
            for k in range(p):
                r_ij += matrice.access_matrix(matrix1, i, k, 3) * matrice.access_matrix(matrix2, k, j, 1)
            result[i][j] = r_ij
    new_x = result[1][0] / result[1][2]
    new_y = result[1][1] / result[1][2]
    return (new_y, new_x)

def reflection(angle, x, y):
    new_tx = 0
    new_ty = 0
    return (new_tx, new_ty)
