def caesar(self, data):
        data_list = list(data)
        result = []
        for char in data_list:
            ascii_value = char
            if 65 <= char <= 91 or 97 <= char <= 122 :
                ascii_value -= self.shift
                if ascii_value < 65 or ascii_value < 97:
                    ascii_value += 26
            result.append(chr(ascii_value))
        return "".join(result)



if __name__ == "__main__":
    f = open("file-1.txt", "r")
    data =  f.read()
    f.close()
    result = caesar(data, 1)
    f = open("file-2.txt", "a")
    f.write(result)
    f.close()

