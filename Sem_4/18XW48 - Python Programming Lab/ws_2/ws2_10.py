def get_digits(value):
    if(value > 1):
        return get_digits(int(value / 10)) + 1
    else:
        return 1

if __name__ == '__main__':
    value = int(input("Please enter the value: "))
    print(get_digits(value))