def print_frequency(input_string):
    input_set = set(input_string)
    for char in input_set:
        print(char + ": " + str(input_string.count(char)))

if __name__ == "__main__":
    input_string = input("Please enter the string: ")
    print_frequency(input_string)