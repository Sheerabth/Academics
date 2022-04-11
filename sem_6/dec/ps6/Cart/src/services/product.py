from typing import List

from bson import ObjectId
from fastapi.encoders import jsonable_encoder
from pymongo.database import Collection

from src.db.database import PymongoWrapper
from src.schemas.product import ProductCreateSchema, ProductSchema, ProductUpdateSchema


def create_product_service(
    cart_collection: Collection, new_product: ProductCreateSchema
) -> ProductSchema:
    new_product = jsonable_encoder(new_product)
    new_product_id = cart_collection.insert_one(new_product).inserted_id
    inserted_product = PymongoWrapper.deserialize(
        cart_collection.find_one({"_id": new_product_id})
    )
    return ProductSchema(**inserted_product)


def update_product_service(
    cart_collection: Collection, modified_product: ProductUpdateSchema, product_id: str
) -> ProductSchema:
    modified_product = jsonable_encoder(modified_product)
    modified_product = {
        key: value for key, value in modified_product.items() if value is not None
    }
    updated_product = PymongoWrapper.deserialize(
        cart_collection.find_one_and_update(
            {"_id": ObjectId(product_id)}, modified_product
        )
    )
    return ProductSchema(**updated_product)


def get_products_service(cart_collection: Collection) -> List[ProductSchema]:
    products = cart_collection.find()
    products_list = [
        ProductSchema(**PymongoWrapper.deserialize(product)) for product in products
    ]
    return products_list


def get_product_service(cart_collection: Collection, product_id: str) -> ProductSchema:
    product = PymongoWrapper.deserialize(
        cart_collection.find_one({"_id": ObjectId(product_id)})
    )
    return ProductSchema(**product)


def delete_product_service(
    cart_collection: Collection, product_id: str
) -> ProductSchema:
    product = PymongoWrapper.deserialize(
        cart_collection.delete_one({"id": ObjectId(product_id)})
    )
    return ProductSchema(**product)
