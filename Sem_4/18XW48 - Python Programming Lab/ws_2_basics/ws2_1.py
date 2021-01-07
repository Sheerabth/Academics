def fun(sequence):
    sequence_list = list(set(sequence.split(" ")))
    sequence_list.sort()
    return " ".join(sequence_list)


if __name__ == "__main__":
    sequence = input("Please enter the string: ")
    print(fun(sequence))