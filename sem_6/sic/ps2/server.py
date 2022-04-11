from fastapi import FastAPI, HTTPException
from fastapi.middleware.cors import CORSMiddleware
import uvicorn

from schema import UserSchema

app = FastAPI()
app.add_middleware(CORSMiddleware, allow_origins="*", allow_methods="*")

users = dict()


@app.post("/register")
def register(credentials: UserSchema):
    users[credentials.username] = credentials.password
    return users[credentials.username]


@app.post("/login")
def login(credentials: UserSchema):
    if users[credentials.username] == credentials.password:
        return {"status_code": 200, "detail": users[credentials.username]}

    return HTTPException(400)


if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000)
