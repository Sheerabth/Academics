import math

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


if __name__ == "__main__":
    affine_cipher = AffineCipher(5, 8)
    encrypted = affine_cipher.decrypt("WZU SAAL")
    print(encrypted)