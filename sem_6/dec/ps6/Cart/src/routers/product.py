from fastapi import APIRouter, Depends
from fastapi.responses import JSONResponse
from pymongo.database import Database
from typing import List

from src.db.database import PymongoWrapper
from src.schemas.product import ProductSchema, ProductCreateSchema, ProductUpdateSchema
from src.services.product import (
    create_product_service,
    update_product_service,
    get_products_service,
    get_product_service,
    delete_product_service,
)

router = APIRouter(
    default_response_class=JSONResponse, dependencies=[Depends(PymongoWrapper.get_db)]
)


@router.post("/", response_model=ProductSchema)
def create_product(
    product: ProductCreateSchema, db: Database = Depends(PymongoWrapper.get_db)
):
    return create_product_service(db["product"], product)


@router.get("/", response_model=List[ProductSchema])
def get_products(db: Database = Depends(PymongoWrapper.get_db)):
    return get_products_service(db["product"])


@router.get("/{product_id}", response_model=ProductSchema)
def get_product(product_id: str, db: Database = Depends(PymongoWrapper.get_db)):
    return get_product_service(db["product"], product_id)


@router.patch("/{product_id}", response_model=ProductSchema)
def update_product(
    product_id: str,
    product: ProductUpdateSchema,
    db: Database = Depends(PymongoWrapper.get_db),
):
    return update_product_service(db["product"], product, product_id)


@router.delete("/{product_id}", response_model=ProductSchema)
def delete_product(product_id: str, db: Database = Depends(PymongoWrapper.get_db)):
    delete_product_service(db["product"], product_id)
