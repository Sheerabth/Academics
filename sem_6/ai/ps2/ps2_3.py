def find_relation(A, B):
    result = list()
    for value1 in A:
        row = list()
        for value2 in B:
            row.append(min(value1, value2))
        result.append(row)

    return result

def max_min(R, S):
    result = list()
    for i in range(len(R)):
        row = list()
        for j in range(len(S[0])):
            temp_list = list()
            for k in range(len(S)):
                temp_list.append(min(R[i][k], S[k][j]))
            row.append(max(temp_list))
        result.append(row)
    
    return result

if __name__ == "__main__":
    A = [1, 0.4, 0.6, 0.2]
    B = [0, 0.2, 0.2, 0.8]
    C = [0.5, 0.6, 0.1, 0.9]
    R = find_relation(A, B)
    S = find_relation(B, C)
    print(max_min(R, S))