import requests
from string import ascii_lowercase
from time import time


URL = "http://0.0.0.0:8000/"


def register(username, password):
    body = {"username": username, "password": password}
    return requests.post(URL + "register", json=body).json()


def crack(username):
    for first_character in ascii_lowercase:
        for second_character in ascii_lowercase:
            for third_character in ascii_lowercase:
                for fourth_character in ascii_lowercase:
                    password = (
                        first_character
                        + second_character
                        + third_character
                        + fourth_character
                    )
                    body = {"username": username, "password": password}
                    reseponse = requests.post(URL + "login", json=body).json()
                    if reseponse["status_code"] == 200:
                        return reseponse


if __name__ == "__main__":
    start_time = time()
    print(register("sheeru", "zzzz"))
    print(crack("sheeru"))
    print(time() - start_time, " seconds")
