import numpy as np

def build_matrix(rows, cols):
    matrix = []

    for _ in range(0, rows):
        matrix.append([0 for c in range(0, cols)])

    return matrix

def check_if_symmetric(np_array):
    return (np_array == np.transpose(matrix)).all()

def check_if_orthogonal(np_array): 
    return (np.identity(np.size(np_array, 0)) == np.dot(np_array, np.transpose(matrix))).all()

if __name__ == '__main__':
    print("Please enter the number of rows and columns: ")
    rows = int(input())
    matrix = build_matrix(rows, rows)
    for i in range(rows):
        for j in range(rows):
            matrix[i][j] = int(input())
    np_array = np.array(matrix)
    if check_if_symmetric(np_array):
        print("symmetric")
    if check_if_orthogonal(np_array):
        print("orthogonal")