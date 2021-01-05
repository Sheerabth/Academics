if __name__  == "__main__":
    dictionary  ={}
    num = int(input("Please enter the value: "))
    for i in range(num):
        dictionary[i+1] = (i+1)*(i+1)
    print("The dictionary is ")
    print(dictionary)
    