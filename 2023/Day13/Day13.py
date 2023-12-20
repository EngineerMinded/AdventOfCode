''' Wayne Mack
    Advent Of Code
    --- Day 13: Point of Incidence ---

    Written in: Python

    FIRST STAR EARNED
'''

# Process the file and 
def process_file (file_path, function_to_call):
    returnThis = 0
    arrays = []
    with open(file_path, 'r') as file:
        current_array = []
        for line in file:
            if line.strip():  # Check if the line is not empty
                current_array.append(list(line.rstrip()))
            else:
                if current_array:  # Process the non-empty array
                    returnThis += function_to_call(current_array)
                    arrays.append(current_array)
                    current_array = []
        
        # Process the last array if it's not empty
        if current_array:
            returnThis += function_to_call(current_array)
            arrays.append(current_array)

    return returnThis

def get_summary(array):
    print("Processing 2D array:")
    for row in array:
        print(''.join(row))
    print("\n")
    # examine line horizontally

    def getStack(array):
        here = 0
        for a in range(1, len(array) ):
            if (array[a] == array[a - 1]):
                there = a
                a1 = a - 1
                a2 = a 
                while a1 >= 0 and a2 <= len(array) - 1:
                    if array[a1] != array [a2]:
                        there = 0
                    a1 = a1 - 1
                    a2 = a2 + 1
                if there > here:
                    here = there
        print (here)
        return here
   
    def getVerticalLine(array):
        verticalStack = []
        for a in range(len(array[0])):
            newLine = []
            for e in array:
                newLine.append(e[a])
            verticalStack.append(newLine)
        for g in verticalStack:
            print(g)
        return getStack(verticalStack)
        
    horizontal = getStack(array) * 100
    vertical = getVerticalLine(array)
    return horizontal + vertical

def findSmudge (array):
    firstAnswer = get_summary(array)
    for x in range(len(array)):
        for y in range(len(array[0])):
            previousValue = array[x][y]
            if array[x][y] == '#':
                array[x][y] = '.'
            else :
                array[x][y] = '#'
            if get_summary(array) != firstAnswer:
                return get_summary(array)
            else :
                array[x][y] = previousValue
    return get_summary(array)  


''' Main functional calls '''
file_path = 'example1.data'  # Replace with your file path containing 2D arrays
processed_arrays = process_file(file_path, get_summary)
print ("Part one: -> " + str(processed_arrays))
part2 = process_file(file_path,findSmudge)
print ("Part two: -> " + str(part2))

