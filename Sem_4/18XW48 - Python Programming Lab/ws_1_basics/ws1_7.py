def isPanagram(sentence):
    alphabet =  [False for i in range(26)]
    sentence = sentence.lower()
    for i in sentence:
        if i !=  " ":
            alphabet[ord(i)-97] = True
    for val in alphabet:
        if val == False:
            return False
    return True

if __name__  == "__main__":
    
    string = input("Enter the string: ")
    if isPanagram(string):
        print("It is a panagram")
    else:
        print("It is not a panagram")
