if __name__ == "__main__":
    n = int(input("Please enter the number of elements in the set 1: "))
    set_1 = set()
    print("Please input the set")
    for _ in range(n):
        val = int(input())
        set_1.add(val)
    n = int(input("Please enter the number of elements in the set 2: "))
    set_2 = set()
    print("Please input the set")
    for _ in range(n):
        val = int(input())
        set_2.add(val)
    print(set_1.union(set_2))
    print(set_1.intersection(set_2))
    print(set_1.symmetric_difference(set_2))