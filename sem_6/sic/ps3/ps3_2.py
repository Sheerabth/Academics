import rsa

if __name__ == "__main__":
    (public_key, private_key) = rsa.newkeys(128)
    e = public_key.e
    n = public_key.n
    d = private_key.d

    plain_text = 125457906

    print("Plain Text:", plain_text)

    C = pow(plain_text, e, n)

    X = C * pow(2, e, n)

    Y = pow(X, d, n)

    decrypted = (Y * pow(2, -1, n)) % n

    print("C:", C)
    print("X:", X)
    print("Y:", Y)

    print("Decrypted:", decrypted)
