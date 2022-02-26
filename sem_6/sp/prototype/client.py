from prototype import EmployeePrototype, PermenantEmployee, TemporaryEmployee

if __name__ == "__main__":
    employee_list = list()
    employee_list.append(PermenantEmployee("Rithesh", 20, ["Scrum Master", "Backend Developer"]))
    employee_list.append(TemporaryEmployee("Dawg", 21, "Frontend Developer"))
    employee_list.append(PermenantEmployee("Baxx", 19, ["Backend Developer", "Worker"]))

    employee_copy = list
    for employee in employee_list:
        employee_copy.append(employee.clone())
