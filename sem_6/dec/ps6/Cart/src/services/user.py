from bson import ObjectId
from fastapi.encoders import jsonable_encoder
from pymongo.database import Collection

from src.exceptions.api import InvalidCredentialsException, UserExistsException
from src.schemas.user import UserCreateSchema, UserSchema
from src.db.database import PymongoWrapper


def create_user(
    user_collection: Collection, user_create: UserCreateSchema
) -> UserSchema:
    user_create = jsonable_encoder(user_create)
    new_user = user_collection.insert_one(user_create)
    created_user = PymongoWrapper.deserialize(
        user_collection.find_one({"_id": new_user.inserted_id})
    )
    return UserSchema(**created_user)


def get_user(user_collection: Collection, user_id: str) -> UserSchema:
    user = PymongoWrapper.deserialize(
        user_collection.find_one({"_id": ObjectId(user_id)})
    )
    if user is None:
        raise InvalidCredentialsException
    return UserSchema(**user)


def check_user(
    user_collection: Collection, user_create: UserCreateSchema
) -> UserSchema:
    user = PymongoWrapper.deserialize((user_collection.find_one(user_create.dict())))
    if user is None:
        raise InvalidCredentialsException
    return UserSchema(**user)


def check_user_existence(user_collection: Collection, username: str) -> None:
    user = PymongoWrapper.deserialize(user_collection.find_one({"username": username}))
    if user:
        raise UserExistsException
