def maximum_by_recursion(input_list):
    if (len(input_list) == 1):
        return input_list[0]
    else:
        present_maximum = maximum_by_recursion(input_list[1:])
        if(present_maximum < input_list[0]):
            return input_list[0]
        else:
            return present_maximum

def test(input_list):
    return input_list[1:]

if __name__ == "__main__":
    n = int(input("Please enter the number of elements in the list: "))
    input_list = []
    print("Please input the list")
    for _ in range(n):
        input_list.append(int(input()))
    # print(test(input_list))
    print("The maximum in the list is " + str(maximum_by_recursion(input_list)))
