from drink import Coffee, Tea
from drink_decorator import CocoaPaste, Caramel, Milk, FizzyWater

if __name__ == "__main__":
    coffee = Coffee()
    coffee_with_toppings = CocoaPaste(Milk(coffee))

    tea = Tea()
    tea_with_toppings = FizzyWater(Caramel(Milk(tea)))

    print(coffee_with_toppings.name(), coffee_with_toppings.cost())
    print(tea_with_toppings.name(), tea_with_toppings.cost())
