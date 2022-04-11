from typing import Optional
import logging

from fastapi import APIRouter, Depends, Response, Cookie
from fastapi.responses import JSONResponse
from pymongo.database import Database
import bcrypt

from src.db.database import PymongoWrapper
from src.middleware.auth import verify_access_token
from src.middleware.jwt import create_access_token
from src.schemas.user import UserCreateSchema, UserSchema
from src.services.user import check_user, create_user, get_user, check_user_existence

router = APIRouter(default_response_class=JSONResponse)

SALT = b"$2b$12$4ct/tWTnhf4oXmfA/4Fun."


@router.post("/login")
def login(
    response: Response,
    form_data: UserCreateSchema,
    db: Database = Depends(PymongoWrapper.get_db),
):

    form_data.password = bcrypt.hashpw(
        (form_data.password).encode("utf-8"), SALT
    ).decode("utf-8")
    user = check_user(db["user"], form_data)

    access_token = create_access_token(data=user.dict())
    response.set_cookie(key="access_token", value=access_token)

    return {"user_id": user.id}


@router.post("/register")
def register(
    response: Response,
    form_data: UserCreateSchema,
    db: Database = Depends(PymongoWrapper.get_db),
):
    form_data.password = bcrypt.hashpw(
        (form_data.password).encode("utf-8"), SALT
    ).decode("utf-8")
    check_user_existence(db["user"], form_data.username)

    user = create_user(db["user"], form_data)
    access_token = create_access_token(data=user.dict())
    response.set_cookie(key="access_token", value=access_token)
    return {"user_id": user.id}


@router.get("/logout")
def logout(
    refresh_token: Optional[str] = Cookie(None),
    user: UserSchema = Depends(verify_access_token),
):
    pass
