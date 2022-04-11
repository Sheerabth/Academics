from drink import Drink
from abc import abstractmethod


class DrinkDecorator(Drink):
    def __init__(self, drink: Drink) -> None:
        self.drink = drink

    @abstractmethod
    def name(self) -> str:
        pass

    @abstractmethod
    def cost(self) -> int:
        pass


class CocoaPaste(DrinkDecorator):
    def name(self) -> str:
        return self.drink.name() + " with Cocoa Paste"

    def cost(self) -> int:
        return self.drink.cost() + 5


class Caramel(DrinkDecorator):
    def name(self) -> str:
        return self.drink.name() + " with Caramel"

    def cost(self) -> int:
        return self.drink.cost() + 10


class Milk(DrinkDecorator):
    def name(self) -> str:
        return self.drink.name() + " with milk"

    def cost(self) -> int:
        return self.drink.cost() + 15


class FizzyWater(DrinkDecorator):
    def name(self) -> str:
        return self.drink.name() + " Fizzy Water"

    def cost(self) -> int:
        return self.drink.cost() + 10
