from hashlib import sha256
from string import ascii_lowercase
from random import randint
from pprint import pprint

PASSWORD_SIZE = 4

random_hashes = list()

def reduce_hash(hashed_password: int, length: int) -> str:
    reduced_hash = ''
    for _ in range(length):
        reduced_hash += ascii_lowercase[hashed_password % 26]
        hashed_password = int(hashed_password / 26)
    return reduced_hash

def hash_password(password: str) -> int:
    return int((sha256(password.encode())).hexdigest(), 16)

def generate_rainbow_table(length: int, count: int, width: int):
    passwords = list()

    for _ in range(count):
        password = ''
        for _ in range(length):
            password += ascii_lowercase[randint(0, 25)]
        passwords.append(password)

    hashes = [hash_password(password) for password in passwords]
    print("Rainbow Table Contents:")
    pprint(passwords)
    pprint(hashes)

    for _ in range(width):
        reduced = [reduce_hash(hashed_password, length) for hashed_password in hashes]
        hashes = [hash_password(reduced_password) for reduced_password in reduced]
        random_hashes.extend(hashes)
        pprint(reduced)
        pprint(hashes)

    return passwords, hashes

def crack(hashed_input: int, passwords, hashes) -> str:
    hashed_iterator = hashed_input
    while hashed_iterator not in hashes:
        hashed_iterator = hash_password(reduce_hash(hashed_iterator, PASSWORD_SIZE))
    
    initial_password = passwords[hashes.index(hashed_iterator)]

    while hash_password(initial_password) != hashed_input:
        initial_password = reduce_hash(hash_password(initial_password), PASSWORD_SIZE)
    
    return initial_password


if __name__ == '__main__':
    passwords, hashes = generate_rainbow_table(PASSWORD_SIZE, 5, 6)
    random_hash = random_hashes[randint(0, len(random_hashes)-1)]
    print("Selected Random Hash:", random_hash)
    cracked = crack(random_hash, passwords, hashes)
    print("Cracked password:", cracked)