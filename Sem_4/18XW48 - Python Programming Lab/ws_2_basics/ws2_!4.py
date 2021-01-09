def get_set(input_list):
    return set(input_list)

if __name__ == "__main__":
    n = int(input("Please enter the number of elements in the list: "))
    input_list = []
    print("Please input the list")
    for _ in range(n):
        val = int(input())
        input_list.append(val)
    print(get_set(input_list))
    