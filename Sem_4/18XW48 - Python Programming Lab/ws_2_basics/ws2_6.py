if __name__ == "__main__":
    n = int(input("Please enter the number of elements in the set: "))
    input_set = set()
    print("Please input the set")
    for _ in range(n):
        val = int(input())
        input_set.add(val)
    input_set.clear()
    print(input_set)