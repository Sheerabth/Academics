from email.encoders import encode_quopri
from http.cookiejar import CookieJar
import math
from string import ascii_lowercase

class AffineCipher:
    def __init__(self, a, b) -> None:
        self.a = a
        self.b = b

    def encrypt(self, plain_text):
        enc_text = ""
        for character in plain_text:
            if not character.isalpha():
                enc_text += character
                continue

            result = ((self.a*(ord(character.lower()) - 97) + self.b) % 26) + 97

            if character.isupper():
                enc_text += chr(result).upper()
            else:
                enc_text += chr(result)

        return enc_text

    def decrypt(self, enc_text):
        dec_text = ""
        for character in enc_text:
            if not character.isalpha():
                dec_text += character
                continue

            result = int((math.pow(self.a, -1)*(ord(character.lower()) - 97)) % 26) + 97
            print(result)

            if character.isupper():
                dec_text += chr(result).upper()
            
            else:
                dec_text += chr(result)

        return dec_text

class KeywordCipher:
    def __init__(self, keyword) -> None:
        keyword = keyword.lower()
        self.enc_key = keyword
        for alphabet in ascii_lowercase:
            if alphabet not in keyword:
                self.enc_key += alphabet

        self.dec_key = ""
        for index in range(len(ascii_lowercase)):
            self.dec_key += self.enc_key[index]

    def encrypt(self, plain_text):
        enc_text = ""
        plain_text = plain_text.lower()
        for alphabet in plain_text:
            enc_text += self.enc_key[ord(alphabet)-97]

        return enc_text

    def decrypt(self, enc_text):
        dec_text = ""
        plain_text = dec_text.lower()
        for alphabet in dec_text:
            dec_text += self.dec_key[ord(alphabet)-97]

        return dec_text

class ColumnarTransposition:
    def __init__(self) -> None:
        pass
        

if __name__ == "__main__":
    affine_cipher = AffineCipher(5, 8)
    encrypted = affine_cipher.decrypt("WZU SAAL")
    print(encrypted)
