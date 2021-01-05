def is_keprekar(num):
    square = num * num
    length = len(str(num))
    square_str = str(square)
    right = int(square_str[-1*length:])
    left = int(square_str[:-1*length])
    if right+left == num:
        return True
    else:
        return False


if __name__  == "__main__":
    num = int(input("Please enter the number: "))
    if is_keprekar(num):
        print("This is a keprekar number")
    else:
        print("This is not a keprekar number")