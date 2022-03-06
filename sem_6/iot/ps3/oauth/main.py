import json
import urllib.parse

import requests
from fastapi import FastAPI, Depends
from starlette.responses import RedirectResponse

from config import TOKEN_FILE_PATH, CLIENT_SECRET_PATH

app = FastAPI()


def get_credentials() -> dict:
    with open(CLIENT_SECRET_PATH) as credentials_file:
        credentials = json.load(credentials_file)
    return credentials


def get_access_token() -> str:
    with open(TOKEN_FILE_PATH, "r") as token_file:
        token = json.load(token_file)
    return token["access_token"]


def get_id_token() -> str:
    with open(TOKEN_FILE_PATH, "r") as token_file:
        token = json.load(token_file)
    return token["id_token"]


@app.get("/login")
def login(credentials: dict = Depends(get_credentials)):
    params = {
        "client_id": credentials["web"]["client_id"],
        "scope": "openid profile",
        "response_type": "code",
        "redirect_uri": "http://127.0.0.1:8000/callback",
        "nonce": "raz",
    }
    url = "https://accounts.google.com/o/oauth2/v2/auth?" + urllib.parse.urlencode(params)
    return RedirectResponse(url)


@app.get("/callback")
def google_callback(code: str, credentials: dict = Depends(get_credentials)):
    body = {
        "code": code,
        "client_id": credentials["web"]["client_id"],
        "client_secret": credentials["web"]["client_secret"],
        "redirect_uri": "http://127.0.0.1:8000/callback",
        "grant_type": "authorization_code"
    }
    response = requests.post("https://oauth2.googleapis.com/token", data=body).json()
    with open("token.json", 'w') as token_file:
        token_file.write(json.dumps(response, indent = 6))

    return response


@app.get("/get_token_info")
def get_token_info(id_token: str = Depends(get_id_token)):
    params = {
        "id_token": id_token
    }
    return requests.get("https://oauth2.googleapis.com/tokeninfo", params=params).json()


@app.get("/get_user_info")
def get_user_info(access_token: str = Depends(get_access_token)):
    headers = {
        "Authorization": "Bearer " + access_token,
    }
    return requests.get("https://www.googleapis.com/oauth2/v1/userinfo?alt=json", headers=headers).json()


@app.get("/logout")
def logout(access_token: str = Depends(get_access_token)):
    params = {
        "token": access_token
    }
    headers = {
        "content-type": "application/x-www-form-urlencoded"
    }
    return requests.post("https://oauth2.googleapis.com/revoke", params=params, headers=headers).json()
