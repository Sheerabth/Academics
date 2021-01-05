if __name__  == "__main__":
    string = input()
    index = int(input())
    char = input()
    print(string[:index] + char + string[index+1:])