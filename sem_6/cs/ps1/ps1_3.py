def decrypt(enc, key):
    if enc > 126 - key:
        return enc - key + 95

    return enc - key


def decrypt_text(enc_text, key):
    decrypted_text = ""
    for char in enc_text:
        print(chr(decrypt(ord(char), key)))
        
# print(decrypt_text("Ro$", 10))