from abc import ABC, abstractmethod
from observer import Observer


class Subject(ABC):
    @abstractmethod
    def register_observer(self, observer: Observer) -> None:
        pass

    @abstractmethod
    def remove_observer(self, observer: Observer) -> None:
        pass

    @abstractmethod
    def notify_observers(self) -> None:
        pass


class TemperatureSensor(Subject):
    def __init__(self):
        self.observers = set()

    def register_observer(self, observer: Observer) -> None:
        self.observers.add(observer)

    def remove_observer(self, observer: Observer) -> None:
        self.observers.remove(observer)

    def notify_observers(self) -> None:
        for observer in self.observers:
            observer.update(self)

    def get_temperature(self) -> float:
        # get temperature from temperature sensor
        temperature = 31
        return temperature
