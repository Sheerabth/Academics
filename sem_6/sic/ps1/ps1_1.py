from string import ascii_lowercase


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
