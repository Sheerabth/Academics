from pydantic import BaseModel, validator

class UserSchema(BaseModel):
    username: str
    password: str

    @validator('password')
    def password_validator(cls, password):
        if not password.isalpha() or not password.islower() or len(password) != 4:
            raise ValueError("Passwords should be 4 lowercase letters")
        
        return password