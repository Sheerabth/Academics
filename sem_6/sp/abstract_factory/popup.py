from abc import ABC, abstractmethod


class Popup(ABC):
    @abstractmethod
    def display_popup(self):
        pass


class LinuxPopup(Popup):
    def display_popup(self):
        # code to display popup in linux
        print("Linux Popup")


class MacPopup(Popup):
    def display_popup(self):
        # code to display popup in mac os
        print("Mac Popup")


class WindowsPopup(Popup):
    def display_popup(self):
        # code to display popup in windows
        print("Windows Popup")
