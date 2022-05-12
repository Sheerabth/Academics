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

def fuzzification(value: float, membership_values: dict) -> dict:
    fuzzified = dict()
    for fuzzy_set, dimensions in membership_values.items():
        if len(dimensions) == 4 and value >= dimensions[1] and value <= dimensions[2]:
            fuzzified[fuzzy_set] = 1
        
        elif value >= dimensions[0] and value <= dimensions[1] and dimensions[0] != dimensions[1]:
            fuzzified[fuzzy_set] = (value - dimensions[0]) / (dimensions[1] - dimensions[0])

        elif len(dimensions) == 4 and value >= dimensions[2] and value <= dimensions[3] and dimensions[2] != dimensions[3]:
            fuzzified[fuzzy_set] = (dimensions[3] - value) / (dimensions[3] - dimensions[2])
        
        elif len(dimensions) == 3 and value >= dimensions[1] and value <= dimensions[2] and dimensions[1] != dimensions[2]:
            fuzzified[fuzzy_set] = (dimensions[2] - value) / (dimensions[2] - dimensions[1])

        else:
            fuzzified[fuzzy_set] = 0

    return fuzzified

def rule_evaluation(fuzzified_1: dict, fuzzified_2: dict) -> dict:
    fuzzified_result = dict()
    for fuzzy_set in membership_values.keys():
        fuzzified_result[fuzzy_set] = 0

    for rule in rules:
        fuzzified_result[rule[2]] = max(fuzzified_result[rule[2]], min(fuzzified_1[rule[0]], fuzzified_2[rule[1]]))
    
    return fuzzified_result

def weighted_average(fuzzified: dict, membership_values: dict) -> float:
    average = 0
    for fuzzy_set, dimensions in membership_values.items():
        if len(dimensions) == 3:
            average += ((dimensions[2] + dimensions[0])/2) * fuzzified[fuzzy_set]

    average /= sum(fuzzified.values())
    return average



if __name__ == "__main__":
    fuzzified_speed = fuzzification(100, membership_values)
    fuzzified_acceleration = fuzzification(70, membership_values)
    fuzzified_throttle = rule_evaluation(fuzzified_speed, fuzzified_acceleration)
    print(fuzzified_throttle)
    print(weighted_average(fuzzified_throttle, membership_values))