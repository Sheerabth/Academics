from string import ascii_lowercase
from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
import uvicorn

from schema import UserSchema

app = FastAPI()
app.add_middleware(CORSMiddleware, allow_origins="*", allow_methods="*")

users = dict()

@app.post("/")
def register(credentials: UserSchema):
    users[credentials.username] = credentials.password
    return users[credentials.username]


@app.get("/")
def crack(username: str):
    for first_character in ascii_lowercase:
        for second_character in ascii_lowercase:
            for third_character in ascii_lowercase:
                for fourth_character in ascii_lowercase:
                    password = first_character + second_character + third_character + fourth_character
                    if users[username] == password:
                        return {"password": password}


if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000)
