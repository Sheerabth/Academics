from abc import ABC, abstractmethod
from tkinter.messagebox import NO
from typing import TextIO


class Adaptee():
    def predictive_analysis(self, xml_weather_data: TextIO):
        # request sent with XML format


class Target(ABC):
    @abstractmethod
    def request(self):
        pass
    

class Adapter(Target):
    def __init__(self, adaptee: Adaptee):
        self.__adaptee = adaptee
    
    def get_predictive_analysis(self, json_weather_data: TextIO):
        xml_weather_data = None
        # xml_weather_data = json_to_xml(json_weather_data)
        self.__adaptee.predictiveAnalysisRequest(xml_weather_data)
