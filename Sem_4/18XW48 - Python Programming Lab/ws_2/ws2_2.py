def get_euclidean_distance(first_point, second_point):
    sum = 0
    if(len(first_point) != len(second_point) or len(first_point) == 0 or len(second_point) == 0):
        return -1
    for i in range(len(first_point)):
        sum += (int(first_point[i])-int(second_point[i])) ** 2
    return sum ** 0.5


if __name__ == "__main__":
    first_point = tuple(input("Please enter the first point: ").split(", "))
    second_point = tuple(input("Please enter the second point: ").split(", "))
    # first_point = tuple(first_point.split(", "))
    if get_euclidean_distance(first_point, second_point) == -1:
        print("Please enter valid entries.")
    else:
        print(get_euclidean_distance(first_point, second_point))