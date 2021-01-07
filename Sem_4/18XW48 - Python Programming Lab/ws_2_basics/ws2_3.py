def find_intersection(list_1, list_2):
    resultant = []
    for x in list_2:
        if x in list_1:
            resultant.append(x)
    return resultant

if __name__ == "__main__":
    list_1 = [1,3,6,78,35,55]
    list_2 = [12,24,35,24,88,120,155]
    print(find_intersection(list_1, list_2))