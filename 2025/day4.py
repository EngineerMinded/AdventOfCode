'''
Wayne Mack
Advent Of Code
Day 4

'''


def read_file_to_array(filename):
    """Reads file into a 2D character array (list of lists)."""
    array = []
    with open(filename, 'r') as f:
        for line in f:
            array.append(list(line.strip()))  # strip newline, convert to list of chars
    return array

def transform_array(arr):
    """Transforms '@' into 'x' if fewer than 4 neighbors are '@' or 'x'."""
    rows, cols = len(arr), len(arr[0]) if arr else 0
    # Make a copy so we don’t overwrite while checking
    temp = [row[:] for row in arr]

    # Directions for 8 neighbors
    directions = [(-1,-1), (-1,0), (-1,1),
                  (0,-1),          (0,1),
                  (1,-1),  (1,0),  (1,1)]

    for i in range(rows):
        for j in range(cols):
            if temp[i][j] == '@':
                count = 0
                for dx, dy in directions:
                    ni, nj = i + dx, j + dy
                    if 0 <= ni < rows and 0 <= nj < cols:
                        if temp[ni][nj] in ('@', 'x'):
                            count += 1
                if count < 4:
                    arr[i][j] = 'x'

def print_array(arr):
    """Prints the 2D array row by row."""
    for row in arr:
        print(''.join(row))

def count_x(arr):

    count = 0
    for row in arr:
        for ch in row:
            if ch == 'x':
                count += 1
    return count

def count_at(arr, char):

    count = 0
    for row in arr:
        for ch in row:
            if ch == char:
                count += 1
    return count

def replace_x_with_r(arr):

    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if arr[i][j] == 'x':
                arr[i][j] = 'r'
    return arr



# Example usage
if __name__ == "__main__":
    filename = "2025Day4.txt"   # replace with your file
    arr = read_file_to_array(filename)

    transform_array(arr)

    print (count_x(arr))

    arr = read_file_to_array(filename)

    previous_roll_count = -1

    while (previous_roll_count != count_at(arr,'@')):
        previous_roll_count = count_at(arr,'@')
        replace_x_with_r(arr)
        transform_array(arr)
        
    print (count_at(arr,'r'))
