def findMaximum(arr):
    min = -99999999999999
    for i in arr:
        if i > min:
            min = i
    return min


def findSecondMaximum(arr, maximum):
    second_max = -99999999999999
    for i in arr:
        if i > second_max and i != maximum:
            second_max = i
    return second_max


if __name__ == '__main__':
    n = int(input())
    arr = [int(x) for x in  input().split(" ")]
    #print(arr)
    maximum = findMaximum(arr)
    print(findSecondMaximum(arr, maximum))
