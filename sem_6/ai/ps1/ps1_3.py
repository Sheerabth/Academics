from typing import List, Dict, Tuple
import copy
from pprint import pprint


class PuzzleProblem:
    def __init__(self, final_state: List[List[int]]) -> None:
        self.final_state = final_state
        self.final_state_mapping = self.generate_mapping(final_state)

    def compare_states(self, state1: List[List[int]], state2: List[List[int]]) -> bool:
        for row1, row2 in zip(state1, state2):
            for state1_element, state2_element in zip(row1, row2):
                if state1_element != state2_element:
                    return False
        return True

    def generate_mapping(self, state: List[List[int]]) -> Dict[int, Tuple[int, int]]:
        state_mapping = dict()
        for i in range(len(state)):
            for j in range(len(state[i])):
                state_mapping[state[i][j]] = (i, j)

        return state_mapping

    def calculate_heuristic(self, current_state: List[List[int]]) -> int:
        heuristic = 0
        for i in range(len(current_state)):
            for j in range(len(current_state[i])):
                if current_state[i][j] != 0:
                    heuristic += abs(
                        i - self.final_state_mapping[current_state[i][j]][0]
                    ) + abs(j - self.final_state_mapping[current_state[i][j]][1])

        return heuristic

    def waiting_queue_pop(self, waiting_queue: List[List[List[int]]], depth: List[int]) -> Tuple[List[List[int]], int]:
        min_index = 0
        min_value = 10000
        for i in range(len(waiting_queue)):
            current_value = self.calculate_heuristic(waiting_queue[i])
            if current_value < min_value:
                min_value = current_value
                min_index = i
        
        print("Min:", min_value)
        return waiting_queue.pop(min_index), depth.pop(min_index)

    def a_star(self, init_state: List[List[int]]):
        visited = list()
        waiting_queue = list()
        depth = list()
        visited.append(init_state)
        waiting_queue.append(init_state)
        depth.append(0)
        index = 0
        while len(waiting_queue) != 0:
            print("index:", index)
            current_state, current_depth = self.waiting_queue_pop(waiting_queue, depth)
            
            if self.compare_states(current_state, self.final_state):
                return current_state
            
            visited.append(copy.deepcopy(current_state))

            current_state_mapping = self.generate_mapping(current_state)
            i, j = current_state_mapping[0]
            if i > 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = temp_state[i - 1][j]
                temp_state[i - 1][j] = 0
                if temp_state not in waiting_queue and temp_state not in visited:
                    waiting_queue.append(temp_state)
                    depth.append(current_depth+1)

            if i < len(init_state) - 1:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = temp_state[i + 1][j]
                temp_state[i + 1][j] = 0
                if temp_state not in waiting_queue and temp_state not in visited:
                    waiting_queue.append(temp_state)
                    depth.append(current_depth+1)

            if j > 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = current_state[i][j - 1]
                temp_state[i][j - 1] = 0
                if temp_state not in waiting_queue and temp_state not in visited:
                    waiting_queue.append(temp_state)
                    depth.append(current_depth+1)

            if j < len(init_state[i]) - 1:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = current_state[i][j + 1]
                temp_state[i][j + 1] = 0
                if temp_state not in waiting_queue and temp_state not in visited:
                    waiting_queue.append(temp_state)
                    depth.append(current_depth+1)

            pprint(current_state)
            index += 1
            print("\n")

        return current_state     

    def hill_climbing(self, init_state: List[List[int]]):
        prev_heuristic = 10000
        current_heuristic = self.calculate_heuristic(init_state)
        current_state = init_state
        # for i in range(0, 2):
        while current_heuristic < prev_heuristic:
            current_state_mapping = self.generate_mapping(current_state)
            i, j = current_state_mapping[0]
            states = list()
            heuristics = list()
            if i > 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = temp_state[i - 1][j]
                temp_state[i - 1][j] = 0
                states.append(temp_state)
                heuristics.append(self.calculate_heuristic(temp_state))

            if i < len(init_state) - 1:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = temp_state[i + 1][j]
                temp_state[i + 1][j] = 0
                states.append(temp_state)
                heuristics.append(self.calculate_heuristic(temp_state))

            if j > 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = current_state[i][j - 1]
                temp_state[i][j - 1] = 0
                states.append(temp_state)
                heuristics.append(self.calculate_heuristic(temp_state))

            if j < len(init_state[i]) - 1:
                temp_state = copy.deepcopy(current_state)
                temp_state[i][j] = current_state[i][j + 1]
                temp_state[i][j + 1] = 0
                states.append(temp_state)
                heuristics.append(self.calculate_heuristic(temp_state))

            pprint(current_state)
            print("\n")
            pprint(states)
            print("\n")

            min_index = heuristics.index(min(heuristics))
            prev_heuristic = current_heuristic
            current_heuristic = min(heuristics)

            if current_heuristic < prev_heuristic:
                current_state = copy.deepcopy(states[min_index])
                pprint(current_state)
                print("\n")

        return current_state

if __name__ == "__main__":
    init_state = [[7, 2, 4], [5, 0, 6], [8, 3, 1]]

    final_state = [[0, 1, 2], [3, 4, 5], [6, 7, 8]]

    problem = PuzzleProblem(final_state)
    print(problem.a_star(init_state))
