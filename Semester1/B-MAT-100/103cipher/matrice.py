##
# EPITECH PROJECT, 2022
# B-MAT-100-STG-1-1-103cipher-florent.guittre
# File description:
# matrice
##

import sys

def fill_key_buffer(key, key_len):
    buffer = []
    buffer_inside = []
    shift_key = 0
    range_v = 0
    if (key_len <= 4 or (key_len <= 9 and key_len > 4)):
        if (key_len <= 4):
            range_v = 2
        if (key_len <= 9 and key_len > 4):
            range_v = 3
        for i in range(range_v):
            for j in range(range_v):
                try:
                    buffer_inside.append(ord(key[shift_key]))
                    shift_key += 1
                except IndexError:
                    buffer_inside.append(0)
            buffer.append(buffer_inside)
            buffer_inside = []
        return (buffer)
    return (-84)

def fill_message_buffer(message, message_len, key_len, flag):
    buffer = []
    buffer_inside = []
    shift_key = 0
    temp = 0
    range_v = int(message_len / key_len)
    if (message_len % 2 == 1):
        range_v += 1
    while (temp < message_len):
        for j in range(key_len):
            try:
                if (flag == 0):
                    buffer_inside.append(ord(message[shift_key]))
                else:
                    buffer_inside.append(message[shift_key])
                shift_key += 1
            except IndexError:
                buffer_inside.append(0)
        buffer.append(buffer_inside)
        buffer_inside = []
        temp += key_len
    return (buffer)

def multiply_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            element = 0
            temp = 0
            for k in range(len(matrix1[0])):
                temp = matrix1[i][k] * matrix2[k][j]
                temp += 0.1
                if (temp - 0.5 < int(temp)):
                    element += temp
                else:
                    element += int(temp) + 1
            result.append(element)
    return (result)

def invert_matrix(matrix):
    if len(matrix) == 2:
        a = matrix[0][0]
        b = matrix[0][1]
        c = matrix[1][0]
        d = matrix[1][1]
        det = a * d - b * c
        if (det == 0):
            sys.exit(84)
        matrix[0][0] = d
        matrix[0][1] = -b
        matrix[1][0] = -c
        matrix[1][1] = a
        for i in range(2):
            for j in range(2):
                matrix[i][j] = (1 / det) * matrix[i][j]
    if len(matrix) == 3:
        a = matrix[0][0]
        b = matrix[0][1]
        c = matrix[0][2]
        d = matrix[1][0]
        e = matrix[1][1]
        f = matrix[1][2]
        g = matrix[2][0]
        h = matrix[2][1]
        i = matrix[2][2]
        det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g)
        if (det == 0):
            sys.exit(84)
        matrix[0][0] = e * i - f * h
        matrix[0][1] = c * h - b * i
        matrix[0][2] = b * f - c * e
        matrix[1][0] = f * g - d * i
        matrix[1][1] = a * i - c * g
        matrix[1][2] = c * d - a * f
        matrix[2][0] = d * h - e * g
        matrix[2][1] = b * g - a * h
        matrix[2][2] = a * e - b * d
        for i in range(3):
            for j in range(3):
                matrix[i][j] = (1 / det) * matrix[i][j]
    return (matrix)
