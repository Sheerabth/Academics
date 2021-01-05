if __name__  == "__main__":
    terms = input("Please enter the number of websites: ")
    sites = []
    for i in range(int(terms)):
        sites.append(input())
    for i in range(int(terms)):
        print(sites[i].split(".")[2])
