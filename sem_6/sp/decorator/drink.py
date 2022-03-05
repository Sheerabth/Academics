from abc import ABC, abstractmethod

from matplotlib.pyplot import cla

class Drink(ABC):

    @abstractmethod
    def name():
        pass

    @abstractmethod
    def cost():
        pass


class 