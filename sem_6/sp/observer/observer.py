from abc import ABC, abstractmethod


class Observer(ABC):
    @abstractmethod
    def update(self) -> None:
        pass


class SmartPhone(Observer):
    def update(self, subject) -> None:
        temperature = subject.get_temperature()
        print("Temperature Update:", temperature)
