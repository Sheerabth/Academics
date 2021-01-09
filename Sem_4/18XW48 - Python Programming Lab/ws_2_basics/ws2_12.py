if __name__ == "__main__":
    n = int(input("Please enter the number of elements in the list: "))
    input_list = []
    print("Please input the list")
    for _ in range(n):
        val = int(input())
        input_list.append(val)
    even_list = [num for num in input_list if num&1 == 0]
    print(even_list)