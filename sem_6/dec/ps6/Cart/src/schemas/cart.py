from pydantic import BaseModel, Field


class CartProductSchema(BaseModel):
    product_id: str
    quantity: int = Field(..., gt=0)

    class Config:
        orm_mode = True
