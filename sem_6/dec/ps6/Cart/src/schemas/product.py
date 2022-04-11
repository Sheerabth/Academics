from typing import Optional

from pydantic import BaseModel, Field


class ProductCreateSchema(BaseModel):
    product_name: str
    product_price: float = Field(..., gt=0)


class ProductSchema(ProductCreateSchema):
    id: str


class ProductUpdateSchema(BaseModel):
    product_name: Optional[str]
    product_price: Optional[float]
