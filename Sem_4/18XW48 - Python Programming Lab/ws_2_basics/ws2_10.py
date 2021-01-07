if __name__ == "__main__":
    lines = []
    input_sentence = input("Please enter the sentence: ")
    lines = input_sentence.split(". ")
    sentemces = []
    for line in lines:
        sentemces.append(line.split(":"))
    print(sentemces)