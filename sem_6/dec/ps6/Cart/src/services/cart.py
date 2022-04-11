from typing import List

from bson import ObjectId
from fastapi.encoders import jsonable_encoder
from pymongo.database import Collection

from src.db.database import PymongoWrapper
from src.schemas.cart import CartProductSchema
from src.services.user import get_user
from src.services.product import get_product_service
from src.exceptions.api import InvalidRequestException


def get_user_cart_products(
    user_collection: Collection, user_id: str
) -> List[CartProductSchema]:
    user = get_user(user_collection, user_id)
    return user.contents


def add_user_cart_product(
    user_collection: Collection, user_id: str, cart_product: CartProductSchema
) -> List[CartProductSchema]:
    cart_product = jsonable_encoder(cart_product)
    user_with_cart_products = PymongoWrapper.deserialize(
        user_collection.find_one(
            {
                "_id": ObjectId(user_id),
                "contents.product_id": cart_product["product_id"],
            }
        )
    )
    if user_with_cart_products is not None:
        existing_cart_product = [
            product
            for product in user_with_cart_products["contents"]
            if product["product_id"] == cart_product["product_id"]
        ][0]
        user_collection.find_one_and_update(
            {
                "_id": ObjectId(user_id),
                "contents.product_id": cart_product["product_id"],
            },
            {
                "$set": {
                    "contents.$.quantity": existing_cart_product["quantity"]
                    + cart_product["quantity"]
                }
            },
        )
    else:
        cart = get_user_cart_products(user_collection, user_id)
        if len(cart) == 5:
            raise InvalidRequestException("Maximum cart size reached")
        user_collection.find_one_and_update(
            {"_id": ObjectId(user_id)}, {"$push": {"contents": cart_product}}
        )
    return get_user_cart_products(user_collection, user_id)


def edit_user_cart_product(
    user_collection: Collection, user_id: str, cart_product: CartProductSchema
) -> List[CartProductSchema]:
    cart_product = jsonable_encoder(cart_product)
    user_with_cart_products = PymongoWrapper.deserialize(
        user_collection.find_one(
            {
                "_id": ObjectId(user_id),
                "contents.product_id": cart_product["product_id"],
            }
        )
    )
    if user_with_cart_products is not None:
        user_collection.find_one_and_update(
            {
                "_id": ObjectId(user_id),
                "contents.product_id": cart_product["product_id"],
            },
            {"$set": {"contents.$.quantity": cart_product["quantity"]}},
        )
    else:
        cart = get_user_cart_products(user_collection, user_id)
        if len(cart) == 5:
            raise InvalidRequestException("Maximum cart size reached")
        user_collection.find_one_and_update(
            {"_id": ObjectId(user_id)}, {"$push": {"contents": cart_product}}
        )
    return get_user_cart_products(user_collection, user_id)


def checkout_user_cart(
    user_collection: Collection, product_collection: Collection, user_id: str
) -> float:
    cart_products = get_user_cart_products(user_collection, user_id)
    total = 0
    for cart_product in cart_products:
        product = get_product_service(product_collection, cart_product.product_id)
        total += cart_product.quantity * product.product_price
    return total


def delete_user_cart_product(
    user_collection: Collection, user_id: str, product_id: str
) -> List[CartProductSchema]:
    user_collection.update_one(
        {"_id": ObjectId(user_id)},
        {"$pull": {"contents": {"product_id": {"$eq": product_id}}}},
    )
    return get_user_cart_products(user_collection, user_id)
