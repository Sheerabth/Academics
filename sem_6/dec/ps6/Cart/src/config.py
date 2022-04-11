from os import environ
from dotenv import load_dotenv

load_dotenv()

# Database Config
DATABASE_HOST = environ.get("DATABASE_HOST")
DATABASE_PORT = int(environ.get("DATABASE_PORT"))
DATABASE_NAME = environ.get("DATABASE_NAME")
DATABASE_USER = environ.get("DATABASE_USER")
DATABASE_PASSWORD = environ.get("DATABASE_PASSWORD")

# Token
ACCESS_TOKEN_SECRET = environ.get("ACCESS_TOKEN_SECRET")
ACCESS_TOKEN_EXPIRE_MINUTES = int(environ.get("ACCESS_TOKEN_EXPIRE_MINUTES"))
