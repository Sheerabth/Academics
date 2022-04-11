from typing import Optional

from fastapi import Depends
from fastapi.params import Cookie
from jose import jwt, JWTError
from pymongo.database import Database

from src.config import ACCESS_TOKEN_SECRET
from src.db.database import PymongoWrapper
from src.exceptions.api import InvalidCredentialsException, TokenExpiredException
from src.schemas.payload import PayloadSchema
from src.schemas.user import UserSchema, UserCreateSchema
from src.services.user import get_user


def verify_access_token(
    db: Database = Depends(PymongoWrapper.get_db),
    access_token: Optional[str] = Cookie(None),
) -> UserSchema:
    if access_token is None:
        raise TokenExpiredException

    try:
        payload = jwt.decode(access_token, ACCESS_TOKEN_SECRET, algorithms=["HS256"])
        username: str = payload.get("username")
        user_id: str = payload.get("id")
        if user_id is None:
            raise InvalidCredentialsException
        user = UserSchema(**payload)
    except JWTError:
        raise TokenExpiredException
    user = get_user(db["user"], user_id=user.id)
    return user
