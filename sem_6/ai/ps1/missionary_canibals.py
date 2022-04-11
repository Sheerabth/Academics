from pprint import pprint
from typing import List, Tuple
import copy

class MissionaryAndCannibals:
    def __init__(self, final_state: List[List[int]]) -> None:
        self.final_state = final_state

    def check_goal(self, state: List[List[int]]):
        return state[0][0] == self.final_state[0][0] and state[0][1] == self.final_state[0][1] and state[1][0] == self.final_state[1][0] and state[1][1] == self.final_state[1][1]

    def calculate_heuristic(self, current_state: List[List[int]]) -> int:
        return abs(self.final_state[0][0] - current_state[0][0]) + abs(self.final_state[0][1] - current_state[0][1]) + abs(self.final_state[1][0] - current_state[1][0]) + abs(self.final_state[1][1] - current_state[1][1])
    
    def check_constraint(self, current_state: List[List[int]]) -> bool:
        return (current_state[0][0] == 0 or current_state[0][0] >= current_state[1][0]) and (current_state[0][1] == 0 or current_state[0][1] >= current_state[1][1])

    def check_boat(self, waiting_queue: List[List[List[int]]], visited: List[List[List[int]]], temp_state: List[List[int]], current_state: List[List[int]], boat_side: bool) -> None:
        if self.check_constraint(temp_state) and (temp_state, boat_side) not in visited and temp_state not in waiting_queue:
            waiting_queue.append(temp_state)

    def waiting_queue_pop(self, waiting_queue: List[List[List[int]]]) -> List[List[int]]:
        min_index = 0
        min_value = 10000
        for i in range(len(waiting_queue)):
            current_value = self.calculate_heuristic(waiting_queue[i])
            if current_value < min_value:
                min_value = current_value
                min_index = i
        
        return waiting_queue.pop(min_index)

    def a_star(self, boat_side: bool, current_state: List[List[int]], waiting_queue: List[List[List[int]]], visited: List[List[List[int]]]) -> bool:
        while len(waiting_queue) != 0:
            current_state = self.waiting_queue_pop(waiting_queue)

            visited.append((copy.deepcopy(current_state), boat_side))
            if self.check_goal(current_state):
                return True

            new_waiting_queue = list()
            if boat_side:

                if current_state[0][0] > 0:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[0][0] -= 1
                    temp_state[0][1] += 1
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)

                if current_state[1][0] > 0:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[1][0] -= 1
                    temp_state[1][1] += 1
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)

                if current_state[0][0] > 1:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[0][0] -= 2
                    temp_state[0][1] += 2
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)

                if current_state[1][0] > 1:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[1][0] -= 2
                    temp_state[1][1] += 2
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)
                
                if current_state[0][0] > 1 and current_state[1][0] > 1:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[0][0] -= 1
                    temp_state[0][1] += 1
                    temp_state[1][0] -= 1
                    temp_state[1][1] += 1
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)

            else:

                if current_state[0][1] > 0:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[0][1] -= 1
                    temp_state[0][0] += 1
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)

                if current_state[1][1] > 0:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[1][1] -= 1
                    temp_state[1][0] += 1
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)
            
                if current_state[0][1] > 1:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[0][1] -= 2
                    temp_state[0][0] += 2
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)

                if current_state[1][1] > 1:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[1][1] -= 2
                    temp_state[1][0] += 2
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)
                
                if current_state[0][1] > 1 and current_state[1][1] > 1:
                    temp_state = copy.deepcopy(current_state)
                    temp_state[0][1] -= 1
                    temp_state[0][0] += 1
                    temp_state[1][1] -= 1
                    temp_state[1][0] += 1
                    self.check_boat(new_waiting_queue, visited, temp_state, current_state, not boat_side)

            if not self.a_star(not boat_side, current_state, new_waiting_queue, visited):
                visited.pop(visited.index((current_state, boat_side)))
            
            else:
                return True

        return False


if __name__ == "__main__":
    init_state = [[3, 0], [3, 0]]
    final_state = [[0, 3], [0, 3]]

    problem = MissionaryAndCannibals(final_state)
    visited = []
    print(problem.a_star(True, init_state, [init_state], visited))
    print(visited)