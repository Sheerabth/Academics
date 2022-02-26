def decrypt(enc, key):
    if enc - key < 32:
        return enc - key + 95

    return enc - key


def decrypt_text(enc_text, key):
    decrypted_text = ""
    for char in enc_text:
        decrypted_text += chr(decrypt(ord(char), key))
        
    return decrypted_text

for key in range(1, 101):
    print(decrypt_text("Ro$", key))