from threading import Lock
from typing import Union

from bson import ObjectId
from pymongo import MongoClient
from pymongo.database import Database
from src.config import (
    DATABASE_HOST,
    DATABASE_PORT,
    DATABASE_USER,
    DATABASE_PASSWORD,
    DATABASE_NAME,
)


class PymongoWrapper:
    __client = None
    __lock = Lock()

    @classmethod
    def get_db(cls) -> Database:
        if cls.__client is None:
            cls.__lock.acquire()

            if cls.__client is None:
                cls.__client = MongoClient(
                    f"mongodb://{DATABASE_USER}:{DATABASE_PASSWORD}@{DATABASE_HOST}:{DATABASE_PORT}"
                )

            cls.__lock.release()
        return cls.__client[DATABASE_NAME]

    @classmethod
    def deserialize(cls, result: dict) -> Union[None, dict]:
        if result is None or "_id" not in result:
            return None
        result["id"] = str(result["_id"])
        result.pop("_id")
        return result

    @classmethod
    def serialize(cls, result: dict) -> Union[None, dict]:
        if result is None or "id" not in result:
            return None
        result["_id"] = ObjectId(result["id"])
        result.pop("id")
        return result
