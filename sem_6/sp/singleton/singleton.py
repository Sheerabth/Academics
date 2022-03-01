from __future__ import annotations
from threading import Lock


class Database:
    __unique_instance = None
    __lock = Lock()

    # private constructor
    def __init__(self) -> None:
        pass

    @classmethod
    def get_instance(cls) -> Database:
        if cls.__unique_instance is None:
            cls.__lock.acquire()

            if cls.__unique_instance is None:
                cls.__unique_instance = Database()

            cls.__lock.release()

        return cls.__unique_instance
