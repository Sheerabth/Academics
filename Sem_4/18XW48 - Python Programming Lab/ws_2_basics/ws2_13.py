if __name__ == "__main__":
    word_list = list("EVAPORATE")
    guessed_letters = []
    present_list = ['-' for _ in range(len(word_list))]
    print("Welcome to HANGMAN !!!!")
    while str(present_list) != str(word_list):
        guessed = input("Please enter the letter: ")
        if guessed in guessed_letters:
            print("The letter " + guessed + " is alredy guessed.")
            continue
        guessed_letters.append(guessed)
        indices = [index for index, val in enumerate(
            word_list) if val == guessed]
        if(len(indices) == 0):
            print("Sorry the guessed letter is not present in the list. " +
                  "The word is now: " + "".join(present_list))
        for index in indices:
            present_list[index] = guessed
        print("You guessed the correct letter !! " +
              "The word is now: " + "".join(present_list))
    print("Congrats you have guessed the word !!!!!")
