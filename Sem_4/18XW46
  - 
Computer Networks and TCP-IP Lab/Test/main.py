from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes


def encrypt_and_store(_data, file_name):
    _key = get_random_bytes(32)
    cipher = AES.new(_key, AES.MODE_EAX)
    decoded_data = cipher.encrypt(_data)
    file_out = open(file_name, "wb")
    [file_out.write(x) for x in (cipher.nonce, decoded_data)]
    file_out.close()
    return _key


def decrypt_and_display(key_, file_name):
    file_in = open(file_name, "rb")
    nonce, ciphertext = [file_in.read(x) for x in (16, -1)]

    cipher = AES.new(key_, AES.MODE_EAX, nonce)
    decrypted_data = cipher.decrypt(ciphertext)
    return decrypted_data


if __name__ == '__main__':
    with open('input.txt') as f:
        data = f.read().encode("utf-8")

    file = 'output.txt'

    key = encrypt_and_store(data, file)
    data = decrypt_and_display(key, file)

    plain_data = data.decode("utf-8")
    print(plain_data)