##
## EPITECH PROJECT, 2022
## B-MAT-100-STG-1-1-104intersection-florent.guittre
## File description:
## intersection
##

from math import tan, radians

def get_point(xp, yp, zp, xv, yv, zv, t):
    x = xp + t * xv
    y = yp + t * yv
    z = zp + t * zv
    return (x, y, z)

def calc_sphere(xp, yp, zp, xv, yv, zv, p):
    a = xv**2 + yv**2 + zv**2
    b = 2*xp*xv + 2*yp*yv + 2*zp*zv
    c = xp**2 + yp**2 + zp**2 - p**2
    return a, b, c

def calc_cylinder(xp, yp, xv, yv, p):
    a = xv**2 + yv**2
    b = 2 * xp * xv + 2 * yp * yv
    c = xp**2 + yp**2 - p**2
    return a, b, c

def calc_cone(xp, yp, zp, xv, yv, zv, p):
    a = xv**2 + yv**2 - (tan(radians(p)) * zv)**2
    b = 2 * xp * xv + 2 * yp * yv - (2 * tan(radians(p)) * zp * tan(radians(p)) * zv)
    c = xp**2 + yp**2 - (tan(radians(p)) * zp)**2
    return a, b, c