def encode(string):
    present = string[0]
    count = 0
    encoded_string = ""
    for char in string:
        if char == present:
            count += 1
        else:
            encoded_string += str(count) + present
            present = char
            count = 1
    encoded_string += str(count) + present
    return encoded_string

if __name__  == "__main__":
    string = input("Please enter the string: ")
    print(encode(string))