def get_cos(first_vector, second_vector):
    dot_product = 0
    sum_1 = 0
    sum_2 = 0
    
    if(len(first_vector) != len(second_vector) or len(first_vector) == 0 or len(second_vector) == 0):
        return -1
    
    for i in range(len(first_vector)):
        dot_product += float(first_vector[i]) * float(second_vector[i])
        sum_1 += float(first_vector[i]) ** 2
        sum_2 += float(second_vector[i]) ** 2

    return float(dot_product/((sum_1 ** 0.5)(sum_2 ** 0.5)))

 

if __name__ == "__main__":
    first_vector = tuple(input("Please enter the first vector: ").split(", "))
    second_vector = tuple(input("Please enter the second vector: ").split(", "))
    if get_cos(first_vector, second_vector) == -1:
        print("Please enter valid entries.")
    else:
        print(get_cos(first_vector, second_vector))