from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from src.routers import product, auth, cart

app = FastAPI()
app.add_middleware(CORSMiddleware, allow_origins="*", allow_methods="*")

app.include_router(product.router, tags=["product"], prefix="/product")
app.include_router(auth.router, tags=["auth"], prefix="/auth")
app.include_router(cart.router, tags=["cart"], prefix="/cart")
