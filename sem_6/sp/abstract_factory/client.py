from ui_factory import LinuxUIFactory, WindowsUIFactory, MacUIFactory

if __name__ == "__main__":
    linux_ui = LinuxUIFactory()
    linux_popup = linux_ui.get_popup()
    linux_notification = linux_ui.get_notification()
    linux_notification.display_notification()
    linux_popup.display_popup()

    mac_ui = MacUIFactory()
    mac_popup = mac_ui.get_popup()
    mac_notification = mac_ui.get_notification()
    mac_notification.display_notification()
    mac_popup.display_popup()
