from abc import ABC, abstractmethod
from __future__ import annotations


class EmployeePrototype(ABC):
    def __init__(self, name, age) -> None:
        super().__init__()
        self.name = name
        self.age = age

    @abstractmethod
    def clone(self):
        pass


class PermenantEmployee(EmployeePrototype):
    def __init__(self, name, age, roles) -> None:
        super().__init__(name, age)
        self.roles = list(roles)

    def __init__(self, permenant_employee: PermenantEmployee) -> None:
        self.__init__(
            permenant_employee.name, permenant_employee.age, permenant_employee.roles
        )

    def clone(self) -> PermenantEmployee:
        return PermenantEmployee(self)


class TemporaryEmployee(EmployeePrototype):
    def __init__(self, name, age, role) -> None:
        super().__init__(name, age)
        self.role = role

    def __init__(self, temporary_employee: TemporaryEmployee) -> None:
        super().__init__(
            temporary_employee.name, temporary_employee.age, temporary_employee.role
        )

    def clone(self):
        return TemporaryEmployee(self)
