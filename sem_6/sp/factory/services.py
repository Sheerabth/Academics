from abc import ABC, abstractmethod


class Service(ABC):
    @abstractmethod
    def setup(self):
        pass


class AWS(Service):
    # Methods to initialize the service
    def setup(self):
        # setup specific to AWS
        print("Setup for aws services")


class Azure(Service):
    # Methods to initialize the service
    def setup(self):
        # setup specific to Azure
        print("Setup for azure services")
