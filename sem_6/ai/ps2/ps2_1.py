from __future__ import annotations
from operator import eq
from typing import Dict
import json

class FuzzySet:
    def __init__(self, elements: Dict[int, float]) -> None:
        self.elements = elements

    def __or__(self, other: object) -> FuzzySet:
        if not isinstance(other, FuzzySet):
            raise ValueError("Not a Fuzzy Set")

        result = dict()

        for value, membership in self.elements.items():
            if value in other.elements:
                result[value] = max(membership, other.elements[value])
            else:
                result[value] = membership

        for value, membership in other.elements.items():
            if value not in self.elements:
                result[value] = membership

        return FuzzySet(result)

    def __and__(self, other: object) -> FuzzySet:
        if not isinstance(other, FuzzySet):
            raise ValueError("Not a Fuzzy Set")

        return FuzzySet({value: min(membership, other.elements[value]) for value, membership in self.elements.items() if value in other.elements})

    def __invert__(self) -> FuzzySet:
        return FuzzySet({value: 1-membership for value, membership in self.elements.items()})

    def __str__(self) -> str:
        return json.dumps(self.elements)

    def __eq__(self, other: object) -> bool:
        if not isinstance(other, FuzzySet):
            raise ValueError("Not a Fuzzy Set")

        for value, membership in self.elements.items():
            if value not in other.elements or membership != other.elements[value]:
                return False
        
        for value, membership in other.elements.items():
            if value not in self.elements or membership != self.elements[value]:
                return False

        return True

    def __hash__(self) -> int:
        return hash(self.elements)

if __name__ == "__main__":
    set1 = FuzzySet({2:1, 3:0.4, 1:0.6, 4:0.2, 7:0.4})
    set2 = FuzzySet({2:0, 3:0.2, 1:0.2, 4:0.8, 5:0.3})
    lhs = ~(set1 & set2)
    rhs = ~set1 | ~set2
    print(lhs, rhs)
    print(lhs == rhs)