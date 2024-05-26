def create_identity_matrix(matrix_size):
    matrix = []
    for i in range(matrix_size):
        child = []
        for j in range(matrix_size):
            child.append((i == j))
        matrix.append(child)
    return matrix


def create_a_matrix(matrix_size, matrix):
    result = []
    k = 0
    for i in range(matrix_size):
        child = []
        for j in range(matrix_size):
            child.append(matrix[k])
            k += 1
        result.append(child)
    return result


def copy_matrix(matrix):
    return [new_matrix[:] for new_matrix in matrix]


def operator_matrix(matrix1, matrix2, operator):
    result = []
    for i in range(len(matrix1)):
        result_child = []
        for j in range(len(matrix1[0])):
            if operator == "+":
                temp = matrix1[i][j] + matrix2[i][j]
            elif operator == "-":
                temp = matrix2[i][j] - matrix1[i][j]
            else:
                temp = 0
                element = 0
                for k in range(len(matrix1[0])):
                    temp = matrix1[i][k] * matrix2[k][j]
                    element += int(temp)
            if operator == "*":
                result_child.append(element)
            else:
                result_child.append(temp)
        result.append(result_child)
    return result


def divide_matrix(matrix, factorial_result):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            matrix[i][j] /= factorial_result
    return matrix


def display_matrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if j == len(matrix[0]) - 1:
                print(f"{matrix[i][j]:.2f}", end="\n")
            else:
                print(f"{matrix[i][j]:.2f}", end="\t")
