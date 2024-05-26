##
## EPITECH PROJECT, 2022
## 102architect
## File description:
## move_manager
##

import display
import matrice
import geometry

def x_y_calculation(x, y, tx, ty, element, matrix):
    if (element == "-t"):
        matrix = matrice.convert_matrix_translation(matrix, tx, ty)
        new_tx, new_ty = geometry.translation(tx, ty, x, y)
    if (element == "-z"):
        matrix = matrice.convert_matrix_scaling(matrix, tx, ty)
        new_tx, new_ty = geometry.scaling(tx, ty, x, y)
    display.display_desc_of_move(element, tx, ty, 0)
    display.display_matrix(matrix)
    display.display_result_of_move(x, y, new_tx, new_ty)
    return (new_tx, new_ty)

def angle_calculation(x, y, angle, element, matrix):
    if (element == "-r"):
        matrix = matrice.convert_matrix_rotation(matrix, angle)
        new_tx, new_ty = geometry.rotation(x, y, matrix)
    if (element == "-s"):
        matrix = matrice.convert_matrix_reflection(matrix, angle)
        new_tx, new_ty = geometry.reflection(angle, x, y)
    display.display_desc_of_move(element, 0, 0, angle)
    display.display_matrix(matrix)
    display.display_result_of_move(x, y, new_tx, new_ty)
    return (new_tx, new_ty)
