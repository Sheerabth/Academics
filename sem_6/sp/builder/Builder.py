from abc import ABC, abstractmethod


class Builder(ABC):
    @abstractmethod
    def add_header(self):
        pass

    @abstractmethod
    def add_mean(self, value):
        pass

    @abstractmethod
    def add_min(self, value):
        pass

    @abstractmethod
    def add_max(self, value):
        pass

    @abstractmethod
    def add_footer(self):
        pass

    def build(self):
        return ""
