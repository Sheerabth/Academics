import scipy.integrate as integrate

rules = [
    ['L', 'G', 'VL'],
    ['M', 'G', 'L'],
    ['S', 'G', 'L'],
    ['L', 'M', 'L'],
    ['M', 'M', 'M'],
    ['S', 'M', 'M'],
    ['L', 'NG', 'M'],
    ['M', 'NG', 'S'],
    ['S', 'NG', 'VS']
]

dirtness_membership = {
    'S': [0, 0, 50],
    'M': [0, 50, 100],
    'L': [50, 100, 100]
}

type_of_dirt_membership = {
    'NG': [0, 0, 50],
    'M': [0, 50, 100],
    'G': [50, 100, 100]
}

wash_time_membership = {
    'VS': [0, 8, 12],
    'S': [8, 12, 20],
    'M': [12, 20, 40],
    'L': [20, 40, 60],
    'VL': [40, 60, 60]
}


def get_membership_value(value: float, dimensions: list, cutoff: float = 1):
    v1, v2, v3 = dimensions

    left_value = None
    right_value = None

    if v1 != v2:
        left_value = (value - v1) / (v2 - v1)
    
    if v2 != v3:
        right_value = (v3 - value) / (v3 - v2)

    if left_value == None: value = right_value
    elif right_value == None: value = left_value
    else: value = min(left_value, right_value)

    return min(max(value, 0), cutoff)



def fuzzification(value: float, membership: dict):
    fuzzified = dict()
    for fuzzy_set, dimensions in membership.items():
        fuzzified[fuzzy_set] = get_membership_value(value, dimensions)

    return fuzzified

def rule_evaluation(fuzzified_1: dict, fuzzified_2: dict, result_membership: dict, rules: list):
    evaluated_fuzzified = dict()
    for fuzzy_set in result_membership.keys():
        evaluated_fuzzified[fuzzy_set] = 0
    
    for rule in rules:
        evaluated_fuzzified[rule[2]] = max(evaluated_fuzzified[rule[2]], min(fuzzified_1[rule[0]], fuzzified_2[rule[1]]))

    return evaluated_fuzzified


def get_aggregated_membership_value(value: float, fuzzified: dict, membership: dict):
    aggregated_membership_value = 0
    for fuzzy_set, dimensions in membership.items():
        aggregated_membership_value = max(aggregated_membership_value, get_membership_value(value, dimensions, fuzzified[fuzzy_set]))

    return aggregated_membership_value

def center_of_gravity(fuzzified: dict, membership: dict):
    numerator = lambda value: value * get_aggregated_membership_value(value, fuzzified, membership)
    denominator = lambda value: get_aggregated_membership_value(value, fuzzified, membership)

    numerator_integrated = integrate.quad(numerator, 0, 60)
    denominator_integrated = integrate.quad(denominator, 0, 60)

    return numerator_integrated[0] / denominator_integrated[0]



if __name__ == "__main__":
    fuzzified_dirtiness = fuzzification(100, dirtness_membership)
    fuzzified_type_of_dirt = fuzzification(100, type_of_dirt_membership)
    fuzzified_wash_time = rule_evaluation(fuzzified_dirtiness, fuzzified_type_of_dirt, wash_time_membership, rules)
    
    print(center_of_gravity(fuzzified_wash_time, wash_time_membership))