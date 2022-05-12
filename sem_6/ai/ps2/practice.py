#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed May  4 17:23:52 2022

@author: apple
"""

# practice


import matplotlib.pyplot as plt


membership_values = {
    'NL': [0, 0, 31, 61],
    'NM': [31, 61, 95],
    'NS': [61, 95, 127],
    'ZE': [95, 127, 159],
    'PS': [127, 159, 191],
    'PM': [159, 191, 223],
    'PL': [191, 223, 255, 255]
}

rules = [
    ['NL', 'ZE', 'PL'],
    ['ZE', 'NL', 'PL'],
    ['NM', 'ZE', 'PM'],
    ['NS', 'PS', 'PS'],
    ['PS', 'NS', 'NS'],
    ['PL', 'ZE', 'NL'],
    ['ZE', 'NS', 'PS'],
    ['ZE', 'NM', 'PM']
]


def check_if_rule_is_valid(speed_rule, speed, acceleration_rule, acceleration):
    speed_membership = membership_values[speed_rule]
    acceleration_membership = membership_values[acceleration_rule]

    if speed >= speed_membership[0] and speed <= speed_membership[len(speed_membership)-1]:
        if acceleration >= acceleration_membership[0] and acceleration <= acceleration_membership[len(acceleration_membership) - 1]:
            return True

    return False


def fuzzyfication(rule, speed, acceleration):
    speed_mem = membership_values[rule[0]]
    acc_mem = membership_values[rule[1]]

    u_speed = max(min((speed - speed_mem[0])/(speed_mem[1] - speed_mem[0]),
                  (speed_mem[2] - speed)/(speed_mem[2] - speed_mem[1])), 0)
    u_acceleration = max(min((acceleration - acc_mem[0])/(
        acc_mem[1] - acc_mem[0]), (acc_mem[2] - acceleration)/(acc_mem[2] - acc_mem[1])), 0)

    return min(u_speed, u_acceleration)


def calculate_area_and_weighted_area(rule, fuzzy_value):
    throttle_mem = membership_values[rule[2]]

    m1 = (1 - 0)/(throttle_mem[1] - throttle_mem[0])
    m2 = (0 - 1)/(throttle_mem[2] - throttle_mem[1])

    a1 = (fuzzy_value - 0 + m1*throttle_mem[0])/m1
    a2 = (fuzzy_value - 1 + m2*throttle_mem[1])/m2

    a = a2 - a1
    b = throttle_mem[2] - throttle_mem[0]

    plt.plot([a1, a2], [fuzzy_value, fuzzy_value])

    area = 0.5 * fuzzy_value * (a + b)
    weighted_area = area * throttle_mem[1]

    return (area, weighted_area)


def plot_graph():
    for labels in membership_values:
        if len(membership_values[labels]) == 4:
            plt.plot(membership_values[labels], [0, 1, 1, 0], label=labels)
        else:
            plt.plot(membership_values[labels], [0, 1, 0], label=labels)


def calculate_throttle_control(speed, acceleration):
    weighted_area_sum = 0
    area_sum = 0

    for rule in rules:
        if check_if_rule_is_valid(rule[0], speed, rule[1], acceleration):
            fuzzy_value = fuzzyfication(rule, speed, acceleration)
            x, y = calculate_area_and_weighted_area(rule, fuzzy_value)
            area_sum += x
            weighted_area_sum += y

    print(weighted_area_sum/area_sum)


if __name__ == '__main__':
    plot_graph()

    plt.xlabel("throttle_control")
    plt.ylabel("membership_value")

    calculate_throttle_control(100, 70)
    # calculate_throttle_control(40, 40)

    plt.legend()
    plt.show()
