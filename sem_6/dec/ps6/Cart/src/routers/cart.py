from fastapi import APIRouter, Depends
from fastapi.responses import JSONResponse
from pymongo.database import Database
from typing import List

from src.db.database import PymongoWrapper
from src.middleware.auth import verify_access_token
from src.schemas.cart import CartProductSchema
from src.schemas.user import UserSchema
from src.services.cart import (
    add_user_cart_product,
    get_user_cart_products,
    edit_user_cart_product,
    delete_user_cart_product,
    checkout_user_cart,
)

router = APIRouter(
    default_response_class=JSONResponse, dependencies=[Depends(PymongoWrapper.get_db)]
)


@router.post("/", response_model=List[CartProductSchema])
def add_cart_product(
    cart_product: CartProductSchema,
    user: UserSchema = Depends(verify_access_token),
    db: Database = Depends(PymongoWrapper.get_db),
):
    return add_user_cart_product(db["user"], user.id, cart_product)


@router.get("/", response_model=List[CartProductSchema])
def get_cart_products(
    user: UserSchema = Depends(verify_access_token),
    db: Database = Depends(PymongoWrapper.get_db),
):
    return get_user_cart_products(db["user"], user.id)


@router.get("/checkout")
def checkout(
    user: UserSchema = Depends(verify_access_token),
    db: Database = Depends(PymongoWrapper.get_db),
):
    cart_total = checkout_user_cart(db["user"], db["product"], user.id)
    return {"Total": cart_total}


@router.patch("/", response_model=List[CartProductSchema])
def update_cart_product(
    cart_product: CartProductSchema,
    user: UserSchema = Depends(verify_access_token),
    db: Database = Depends(PymongoWrapper.get_db),
):
    return edit_user_cart_product(db["user"], user.id, cart_product)


@router.delete("/", response_model=List[CartProductSchema])
def delete_cart_product(
    product_id: str,
    user: UserSchema = Depends(verify_access_token),
    db: Database = Depends(PymongoWrapper.get_db),
):
    return delete_user_cart_product(db["user"], user.id, product_id)
