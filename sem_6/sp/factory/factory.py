from abc import ABC, abstractmethod
from services import Service, AWS, Azure


class ServicesFactory(ABC):
    @abstractmethod
    def get_service(self) -> Service:
        pass
	
	
class AWSFactory(ServicesFactory):	
    def get_service(self) -> Service:
        return AWS()
	

class AzureFactory(ServicesFactory):
    def get_service(self) -> Service:
        return Azure()
