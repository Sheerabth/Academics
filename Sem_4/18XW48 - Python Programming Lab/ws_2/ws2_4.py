if __name__ == "__main__":

    triplets = set() 
    for i in range(1, 100):
        for j in range(1, 100):
            for k in range(1, 100):
                if i**2 + j**2 == k**2:
                    someSet = frozenset((i, j, k))
                    triplets.add(someSet)
    for (i, j, k) in triplets:
        print(i, j, k)