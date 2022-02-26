from string import ascii_lowercase

class affine_cipher:
    def __init__(self, a, b) -> None:
        self.a = a
        self.b = b

    def encrypt(self, plain_text):
        enc_text = ""
        for character in plain_text:
            is_upper = False
            if character.isupper():
                is_lower = True

            result = self.a*(ord(character.lower()) - 97) + self.b

            if is_upper:
                enc_text += chr(result).upper()
            else:
                enc_text += chr(result)
        return enc_text

    def decrypt(self, enc_text):
        pass

class keyword_cipher:
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

class columnar_transposition:
    def __init__(self) -> None:
        pass
        