import numpy as np


def build_matrix(rows, cols):
    matrix = []

    for _ in range(0, rows):
        matrix.append([0 for c in range(0, cols)])

    return matrix



if __name__ == '__main__':
    print("Please enter the number of rows and columns: ")
    rows = int(input())
    cols = int(input())
    matrix = build_matrix(rows, cols)
    for i in range(rows):
        for j in range(cols):
            matrix[i][j] = int(input())
    np_array = np.array(matrix)
    print(np.linalg.inv(np_array))
