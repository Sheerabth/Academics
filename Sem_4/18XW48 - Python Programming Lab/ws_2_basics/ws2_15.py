import string
import random

def get_random_password(printable_list):
    
    password = ""
    for _ in range(9):
        password += printable_list[random.randint(0, len(printable_list)-1)]
    return password

if __name__ == "__main__":
    printable_list = list(string.printable)
    for _ in range(6):
        printable_list.pop()
    print("The generarted password is " + get_random_password(printable_list))