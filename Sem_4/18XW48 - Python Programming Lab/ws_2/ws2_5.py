def return_normalized_numbers(input_list):
    minimum, maximum = min(input_list), max(input_list)
    for i, val in enumerate(input_list):
        input_list[i] = (val-minimum) / (maximum-minimum)
    return input_list


if __name__ == "__main__":
    n = int(input("Please enter the number of elements in the list: "))
    input_list = []
    print("Please input the list")
    for _ in range(n):
        val = int(input())
        input_list.append(val)
    print("The normalized list is: ")
    print(return_normalized_numbers(input_list))