##
## EPITECH PROJECT, 2022
## 102architect
## File description:
## matrice.py
##

from math import cos, sin, radians

def access_matrix (data, i, j, line_nb):
    return (data[(line_nb - 1) * i + j])

def convert_matrix_translation(matrix, tx, ty):
    matrix[2] = tx
    matrix[5] = ty
    return (matrix)

def convert_matrix_scaling(matrix, tx, ty):
    matrix[0] = tx
    matrix[4] = ty
    return (matrix)

def convert_matrix_rotation(matrix, angle):
    matrix[0] = cos(radians(angle))
    matrix[1] = -sin(radians(angle))
    matrix[3] = sin(radians(angle))
    matrix[4] = cos(radians(angle))
    return (matrix)

def convert_matrix_reflection(matrix, angle):
    matrix[0] = cos(radians(2 * angle))
    matrix[1] = sin(radians(2 * angle))
    matrix[3] = sin(radians(2 * angle))
    matrix[4] = -cos(radians(2 * angle))
    return (matrix)
