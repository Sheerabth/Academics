def caesar(data, shift):
    data_list  =list(data)
    result = []

    for char in data_list:
        ascii_value = ord(char)
        shift = shift % 26
        if char.isalpha():
            ascii_value += shift
            if (ascii_value > 90 and ascii_value < 97) or (ascii_value > 122):
                ascii_value -= 26
        result.append(chr(ascii_value))
    return "".join(result)

if __name__ == "__main__":
    f = open("file-1.txt", "r")
    data =  f.read()
    f.close()
    result = caesar(data, 400)
    f = open("file-2.txt", "a")
    f.write(result)
    f.close()

