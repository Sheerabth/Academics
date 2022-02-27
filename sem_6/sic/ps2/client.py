import requests

URL = "http://127.0.0.1:8000/"

def register(username, password):
    body={
        "username": username,
        "password": password
    }
    return requests.post(URL, json=body).json()

def crack(username):
    query_params = {
        "username": username
    }
    return requests.get(URL, params=query_params).json()


if __name__ == "__main__":
    print(register("sheeru", "pass"))
    print(crack("sheeru"))