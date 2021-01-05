def find_centered_averaeg(arr):
    maximum = max(arr)
    minimum = min(arr)
    sum = 0
    for i in range(len(arr)):
        if i != maximum and i != minimum:
            sum += i
    return sum/(len(arr)-2)

if __name__  == "__main__":
    n = int(input("Enter number of elements : ")) 
    arr= []
    for i in range(0, n): 
        ele = int(input()) 
        arr.append(ele)
    print("The centered average is " + str(find_centered_averaeg(arr)))
