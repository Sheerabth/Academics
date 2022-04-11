from typing import List
import copy


class JugProblem:
    def __init__(self, final_state: List[int]) -> None:
        self.final_state = final_state

    def calculate_utility(self, state: List[int]) -> int:
        utility = 0
        if self.final_state[0] != -1:
            utility += abs(self.final_state[0] - state[0])

        if self.final_state[1] != -1:
            utility += abs(self.final_state[1] - state[1])

        return utility

    def compare_states(self, current_state: List[int]) -> bool:
        if (self.final_state[0] != -1 and current_state[0] != self.final_state[0]) or (
            self.final_state[1] != -1 and current_state[1] != self.final_state[1]
        ):
            return False
        return True

    def find(self, init_state: List[int]) -> List[int]:
        visied = set()
        waiting_queue = list()

        waiting_queue.append(init_state)

        # for i in range(0, 10):
        while len(waiting_queue) != 0:
            current_state = waiting_queue.pop(0)

            if self.compare_states(current_state):
                return current_state

            visied.add(tuple(current_state))

            if current_state[0] != 4:
                temp_state = copy.deepcopy(current_state)
                temp_state[0] = 4
                if tuple(temp_state) not in visied and temp_state not in waiting_queue:
                    waiting_queue.append(temp_state)

            if current_state[1] != 3:
                temp_state = copy.deepcopy(current_state)
                temp_state[1] = 3
                if tuple(temp_state) not in visied and temp_state not in waiting_queue:
                    waiting_queue.append(temp_state)

            if current_state[0] != 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[0] = 0
                if tuple(temp_state) not in visied and temp_state not in waiting_queue:
                    waiting_queue.append(temp_state)

                if current_state[1] != 3:
                    temp_state = copy.deepcopy(current_state)
                    total = temp_state[0] + temp_state[1]
                    if total > 3:
                        temp_state[0] = total - 3
                        temp_state[1] = 3
                    else:
                        temp_state[0] = 0
                        temp_state[1] = total

                    if (
                        tuple(temp_state) not in visied
                        and temp_state not in waiting_queue
                    ):
                        waiting_queue.append(temp_state)

            if current_state[1] != 0:
                temp_state = copy.deepcopy(current_state)
                temp_state[1] = 0
                if tuple(temp_state) not in visied and temp_state not in waiting_queue:
                    waiting_queue.append(temp_state)

                if current_state[0] != 4:
                    temp_state = copy.deepcopy(current_state)
                    total = temp_state[0] + temp_state[1]
                    if total > 4:
                        temp_state[0] = 4
                        temp_state[1] = total - 4
                    else:
                        temp_state[0] = total
                        temp_state[1] = 0

                    if (
                        tuple(temp_state) not in visied
                        and temp_state not in waiting_queue
                    ):
                        waiting_queue.append(temp_state)

            print(current_state, waiting_queue, "\n")

        return current_state


if __name__ == "__main__":
    init_state = [0, 0]
    final_state = [2, -1]

    problem = JugProblem(final_state)
    print(problem.find(init_state))
