##
## EPITECH PROJECT, 2022
## B-MAT-100-STG-1-1-104intersection-florent.guittre
## File description:
## display
##

def object(object_index, arg):
    if (object_index == 1):
        print(f"Sphere of radius {arg}")
    if (object_index == 2):
        print(f"Cylinder of radius {arg}")
    if (object_index == 3):
        print(f"Cone with a {arg} degree angle")

def description(xp, yp, zp, xv, yv, zv):
    print(f"Line passing through the point ({xp}, {yp}, {zp}) and parallel to the vector ({xv}, {yv}, {zv})")

def nb_intersection_found(nb):
    if (nb == -1):
        print("There is an infinite number of intersection points.")
    elif (nb == 0):
        print("No intersection point.")
    elif (nb == 1):
        print(f"{nb} intersection point:")
    else:
        print(f"{nb} intersection points:")

def intersection_coordinate(x, y, z):
    print(f"({x:.3f}, {y:.3f}, {z:.3f})")