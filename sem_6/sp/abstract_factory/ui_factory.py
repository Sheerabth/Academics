from popup import Popup, LinuxPopup, MacPopup, WindowsPopup
from notification import Notification, LinuxNotification, WindowsNotification, MacNotification
from abc import ABC, abstractmethod

class UIFactory(ABC):
    @abstractmethod
    def get_popup(self):
        pass

    @abstractmethod
    def get_notification(self):
        pass
    
  
class LinuxUIFacatory(UIFactory):
    def get_popup(self) -> Popup:
        return LinuxPopup()
  
    def get_notification(self) -> Notification:
        return LinuxNotification()
  
  
class MacUIFactory(UIFactory):
    def get_popup(self) -> Popup:
        return MacPopup()
  
    def get_notification(self) -> Notification:
        return MacNotification()
  
  
class WindowsUIFactory(UIFactory):
    def get_popup(self) -> Popup:
        return WindowsPopup()
  
    def get_notification(self) -> Notification:
        return WindowsNotification()