if __name__ == '__main__':
    sequence = [3, 6, 9, 12, 15, 21, 24]
    a = sequence
    c = a[3:5]
    b = a
    del a[3]
    del a[4]
    a[3:3] = c
    print(a)