if __name__  == "__main__":
    ans = []
    for i in range(2000, 3200):
        if i%7 == 0 and i%5 != 0:
            ans.append(i)
    string = ",".join(str(e) for e in ans)
    print(string)