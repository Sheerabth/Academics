from abc import ABC, abstractmethod

class Drink:
    @abstractmethod
    def name(self) -> str:
        pass

    @abstractmethod
    def cost(self) -> int:
        pass 


class Coffee:

    def name(self) -> str:
        return "Coffee"

    def cost(self) -> int:
        return 50


class Tea:

    def name(self) -> str:
        return "Tea"

    def cost(self) -> int:
        return 40
