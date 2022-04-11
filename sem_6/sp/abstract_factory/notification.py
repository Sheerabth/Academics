from abc import ABC, abstractmethod


class Notification(ABC):
    @abstractmethod
    def display_notification(self):
        pass


class LinuxPopup(Notification):
    def display_notification(self):
        # code to display notification in linux
        print("Linux Popup")


class MacPopup(Notification):
    def display_notification(self):
        # code to display notification in mac os
        print("Mac Popup")


class WindowsPopup(Notification):
    def display_notification(self):
        # code to display notification in windows
        print("Windows Popup")
