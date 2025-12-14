''' Wayne Mack
    Advent Of Code
    Day 10
'''

# TAKING A LONG TIME TO RUN
# NEED TO BE MORE DYNAMIC
from collections import deque

import re
import heapq

class Machine:
    def __init__(self):
        self.lights = []       # character array (list of strings)
        self.buttons = []      # 2D integer array (list of lists of ints)
        self.joltage = []      # integer array (list of ints)

    def read_line(self, line: str):
        # Extract lights inside []
        lights_matches = re.findall(r'\[(.*?)\]', line)
        for match in lights_matches:
            self.lights.append(match)

        # Extract buttons inside ()
        buttons_matches = re.findall(r'\((.*?)\)', line)
        for match in buttons_matches:
            nums = [int(x.strip()) for x in match.split(',') if x.strip().isdigit()]
            self.buttons.append(nums)

        # Extract joltage inside {}
        joltage_matches = re.findall(r'\{(.*?)\}', line)
        for match in joltage_matches:
            nums = [int(x.strip()) for x in match.split(',') if x.strip().isdigit()]
            self.joltage.extend(nums)

    def __repr__(self):
        return (f"Machine(\n"
                f"  lights={self.lights},\n"
                f"  buttons={self.buttons},\n"
                f"  joltage={self.joltage}\n"
                f")")
    
def get_light_numeric_value(light_string):
 
    result_list = re.split(r'([.#])', light_string)

    # Filter out any empty strings that might result from the split
    char_list = [item for item in result_list if item]
    final_list = []
    for i in range(len(char_list)):
        if char_list[i] == '#':
            final_list.append(i)
    return final_list

def load_machines_from_file(filename: str):
    machines = []
    try:
        with open(filename, 'r') as file:
            for line in file:
                line = line.strip()
                if not line:  # skip empty lines
                    continue
                m = Machine()
                m.read_line(line)
                machines.append(m)
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
    return machines

sampleMachine = load_machines_from_file("Day10Sample.txt")
puzzleMachine = load_machines_from_file("Day10Puzzle.txt")

# test to prove proper object data
for i, m in enumerate(sampleMachine, start=1):
    print(f"Machine {i}: {m}")

def min_button_presses(lights, buttons):
    #print(lights,buttons)

    """
    Find the minimum number of button arrays needed to transform
    a blank array [] into the target lights array.
    """
    target = tuple(sorted(lights))  # canonical form
    start = tuple()  # empty array
    
    # BFS queue: (current_state, steps)
    queue = deque([(start, 0)])
    visited = {start}
    
    while queue:
        state, steps = queue.popleft()
        
        # Check if we reached target
        if state == target:
            return steps
        
        # Try pressing each button
        for btn in buttons:
            new_state = set(state)
            for num in btn:
                if num in new_state:
                    new_state.remove(num)
                else:
                    new_state.add(num)
            new_state = tuple(sorted(new_state))
            
            if new_state not in visited:
                visited.add(new_state)
                queue.append((new_state, steps + 1))
    
    return -1  # if impossible

sample1 = 0
puzzle1 = 0

for sm in sampleMachine:
    answer = min_button_presses(get_light_numeric_value(sm.lights[0]),sm.buttons)
    print (answer)
    if answer != -1:
        
        sample1 += answer

for sm in puzzleMachine:
    answer = min_button_presses(get_light_numeric_value(sm.lights[0]),sm.buttons)
    print (answer)
    if answer != -1:
        
        puzzle1 += answer

print ("Sample Part 1: " + str(sample1))
print ("Puzzle part 1: " + str(puzzle1))
# STAR 1 ACHIEVED 

def min_button_presses_2(lights, buttons):

    n = len(lights)
    target = tuple(lights)
    start = tuple([0] * n)

    # BFS queue: (current_state, steps)
    queue = deque([(start, 0)])
    visited = {start}

    while queue:
        
        state, steps = queue.popleft()

        print (state,target)

        # Check if we reached target
        if state == target:
            return steps

        # Try pressing each button (multiple times allowed)
        for btn in buttons:
            new_state = list(state)
            for idx in btn:
                if 0 <= idx <= n - 1:  # ensure valid index
                    new_state[idx] += 1
            new_state = tuple(new_state)

            # Only explore if not exceeding target
            if all(new_state[i] <= target[i] for i in range(n)):
                if new_state not in visited:
                    visited.add(new_state)
                    queue.append((new_state, steps + 1))

    return -1  # impossible


def min_button_presses_dynamic(lights, buttons):
    n = len(lights)
    target = tuple(lights)
    start = tuple([0] * n)

    def heuristic(state):
        return sum(target[i] - state[i] for i in range(n))

    pq = [(heuristic(start), 0, start)]
    visited = {start}

    while pq:
        _, steps, state = heapq.heappop(pq)
        if state == target:
            return steps
        print (state,target)

        for btn in buttons:
            new_state = list(state)
            for idx in btn:
                if 0 <= idx <= n - 1:
                    new_state[idx] += 1
            new_state = tuple(new_state)

            if all(new_state[i] <= target[i] for i in range(n)):
                if new_state not in visited:
                    visited.add(new_state)
                    heapq.heappush(pq, (steps + 1 + heuristic(new_state), steps + 1, new_state))
    return -1


sample2 = 0
puzzle2 = 0

for sm in sampleMachine:
    answer = min_button_presses_dynamic(sm.joltage,sm.buttons)
    print (answer)
    if answer != -1:
        
        sample2 += answer

print ("Sample Part 2: " + str(sample2))

for sm in puzzleMachine:
    answer = min_button_presses_dynamic(sm.joltage,sm.buttons)
    print (answer)
    if answer != -1:
        
        puzzle2 += answer


print ("Puzzle Part 2: " + str(puzzle2))