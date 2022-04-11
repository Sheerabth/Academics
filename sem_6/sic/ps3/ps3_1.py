import rsa

if __name__ == "__main__":
    (public_key, private_key) = rsa.newkeys(16)
    e = public_key.e
    n = public_key.n
    message = 1234
    plain_text = message
    cipher_text = -1
    iteration = 0

    while cipher_text != message:
        iteration += 1
        cipher_text = (plain_text**e) % n
        plain_text = cipher_text
        print("Iteration:", iteration, "cipher text:", cipher_text)

    print("Cipher Text:", cipher_text, "Plain Text:", plain_text)
