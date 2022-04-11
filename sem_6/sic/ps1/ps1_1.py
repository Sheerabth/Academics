from pydoc import plain
from string import ascii_lowercase


class KeywordCipher:
    def __init__(self, keyword) -> None:
        keyword = keyword.lower()
        self.enc_key = keyword
        for alphabet in ascii_lowercase:
            if alphabet not in keyword:
                self.enc_key += alphabet

        self.dec_key = ""
        for alphabet in ascii_lowercase:
            self.dec_key += ascii_lowercase[self.enc_key.index(alphabet)]

    def encrypt(self, plain_text):
        enc_text = ""
        plain_text = plain_text.lower()
        for alphabet in plain_text:
            enc_text += self.enc_key[ord(alphabet) - 97]

        return enc_text

    def decrypt(self, enc_text):
        dec_text = ""
        enc_text = enc_text.lower()
        for alphabet in enc_text:
            dec_text += self.dec_key[ord(alphabet) - 97]

        return dec_text


class ColumnarTransposition:
    def __init__(self) -> None:
        self.cipher = ""

    def clense(self, plain_text: str) -> str:
        clean_plain_text = ""
        for character in plain_text.lower():
            if character.isalpha():
                clean_plain_text += character

        return clean_plain_text

    def unique(self, plain_text: str) -> str:
        unique_plain_text = ""
        for character in plain_text:
            if character not in unique_plain_text:
                unique_plain_text += character

        return unique_plain_text

    def generate_cipher(self, plain_text: str) -> None:
        cleansed = self.unique(self.clense(plain_text))

        columnar_matrix = list()
        columnar_matrix.append(cleansed)
        alphabet_list = list()
        for index in range(26):
            if ascii_lowercase[index] not in cleansed:
                alphabet_list.append(ascii_lowercase[index])

            if len(alphabet_list) == len(cleansed) or index == 25:
                columnar_matrix.append(alphabet_list)
                alphabet_list = list()

        for j in range(len(cleansed)):
            for i in range(len(columnar_matrix)):
                if i == len(columnar_matrix) - 1 and j >= len(columnar_matrix[-1]):
                    break
                self.cipher += columnar_matrix[i][j]

    def encrypt(self, plain_text: str) -> str:
        cleansed = self.clense(plain_text)
        cipher_text = ""
        for character in plain_text.lower():
            if character in cleansed:
                cipher_text += self.cipher[ascii_lowercase.index(character)]
            else:
                cipher_text += character

        return cipher_text

    def decrypt(self, cipher_text: str) -> str:
        cleansed = self.clense(cipher_text)
        plain_text = ""
        for character in cipher_text.lower():
            if character in cleansed:
                plain_text += ascii_lowercase[self.cipher.index(character)]
            else:
                plain_text += character

        return plain_text


if __name__ == "__main__":
    cipher = ColumnarTransposition()
    plain_text = "CORNELL"
    cipher.generate_cipher(plain_text)
    plain_text = "FAR ABOVE CAYUGA’S WATERS"
    cipher_text = cipher.encrypt(plain_text)

    print("Columnar Transposition")
    print("Plain Text:", plain_text)
    print("Cipher Text:", cipher_text)
    print("Decrypted:", cipher.decrypt(cipher_text))

    plain_text = "SomeWord"
    cipher = KeywordCipher("keyword")
    cipher_text = cipher.encrypt(plain_text)

    print("Keyword Cipher")
    print("Plain Text:", plain_text)
    print("Cipher Text:", cipher_text)
    print("Decrypted:", cipher.decrypt(cipher_text))
