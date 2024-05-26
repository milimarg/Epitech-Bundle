##
## EPITECH PROJECT, 2022
## 102architect
## File description:
## display.py
##

def display_desc_of_move(move_shortcut, tx, ty, angle):
    if (move_shortcut == "-t"):
        print(f"Translation along vector ({tx}, {ty})")
    if (move_shortcut == "-z"):
        print(f"Scaling by factors {tx} and {ty}")
    if (move_shortcut == "-r"):
        print(f"Rotation by a {angle} degree angle")
    if (move_shortcut == "-s"):
        print(f"Reflection over an axis with an inclination angle of {angle} degrees")

def display_result_of_move(x, y, result_x, result_y):
    print(f"({x:.2f}, {y:.2f}) => ({result_x:.2f}, {result_y:.2f})")

def display_matrix(matrix):
    for i in range(1, 10):
        print(f"{matrix[i - 1]:.2f}", end='')
        if (i == 3 or i == 6 or i == 9):
            print("")
        else:
            print("    ", end='')
