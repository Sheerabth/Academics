def people(dictionary):
    result = {}
    for x in dictionary:
        person = dictionary.get(x)
        if person.get("instrument") in result:
            result[person.get("instrument")].append(x)
        else :
            result[person.get("instrument")] = [x]
    return result

def get_people(dictionary,instrument):
    result = {}
    for x in dictionary:
        person = dictionary.get(x)
        if person.get("instrument") == instrument:
            result[x] = person
    return result

alonzo = {"age": 10, "height": 42, "weight": 175, "instrument": "fiddle" }
turing = {"age": 41, "height": 70, "weight": 160, "instrument": "theremin"}
bertha = {"age": 32, "height": 97, "weight": 587, "instrument": "cello"}
tinkerB = {"age":100, "height": 4, "weight": 0.5, "instrument": "cello"}
dictionary = {"Alonzo": alonzo, "Turing": turing, "Bertha": bertha, "TinkerB": tinkerB}
# print(people(dictionary))
if __name__ == "__main__":
    instrument = input('Enter instrument name : ')
    print(get_people(dictionary,instrument))   