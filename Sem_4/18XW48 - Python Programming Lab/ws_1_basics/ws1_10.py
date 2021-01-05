def has22(arr):
    for i in range(len(arr) - 1):
        if(arr[i] == 2 and arr[i + 1] == 2):
            return True
    return False

if __name__  == "__main__":
    n = int(input("Enter number of elements : ")) 
    arr= []
    for i in range(0, n): 
        ele = int(input()) 
        arr.append(ele)
    if has22(arr):
        print("It has 22")
    else:
        print("It dosent have 22")