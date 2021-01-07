def find_maximum(input_list):
    maximum = input_list[0]
    for i in input_list:
        if i > maximum:
            maximum = i
    return maximum

def find_minimum(input_list):
    minimum = input_list[0]
    for i in input_list:
        if i < minimum:
            minimum = i
    return minimum

if __name__ == "__main__":
    n = int(input("Please enter the number of elements in the list: "))
    input_list = []
    print("Please input the list")
    for _ in range(n):
        val = int(input())
        input_list.append(val)
    print("The maximum in the list is: " + str(find_maximum(input_list)))
    print("The minimum in the list is: " + str(find_minimum(input_list)))
