from dotenv import load_dotenv
from os import environ

load_dotenv(".env")

CLIENT_SECRET_PATH = environ.get("CLIENT_SECRET_PATH")
TOKEN_FILE_PATH = environ.get("TOKEN_FILE_PATH")
