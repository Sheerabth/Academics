from subject import TemperatureSensor
from observer import SmartPhone

if __name__ == "__main__":
    temperature_sensor = TemperatureSensor()
    smart_phone = SmartPhone()

    temperature_sensor.register_observer(smart_phone)

    temperature_sensor.notify_observers()
