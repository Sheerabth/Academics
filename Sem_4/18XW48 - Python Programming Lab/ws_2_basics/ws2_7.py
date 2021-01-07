
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
    if set_1 == set_2:
        print("The two sets A and B are equal")
    else:
        B1 = set_2-set_1
        B2 = set_1-set_2
        print(B1)
        print(B2)
    