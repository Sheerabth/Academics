from typing import Optional, List
from pydantic import BaseModel, Field

from src.schemas.cart import CartProductSchema


class UserBase(BaseModel):
    username: str


class UserCreateSchema(UserBase):
    password: str


class UserSchema(UserBase):
    id: str
    contents: Optional[List[CartProductSchema]] = Field(..., max_items=5)

    class Config:
        orm_mode = True
