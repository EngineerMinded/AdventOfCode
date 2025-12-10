''' Wayne Mack
    Advent Of Code
    Day 9
'''
filename = "2025Day9Ex.txt"

def read_numbers_from_file(filename):
    """
    Reads a text file where each line contains two numbers separated by a comma.
    Returns a 2D list (list of lists) with the two numbers from each line.
    """
    result = []
    with open(filename, 'r') as file:
        for line in file:
            # Strip whitespace and split by comma
            parts = line.strip().split(',')
            if len(parts) == 2:  # Ensure exactly two numbers
                try:
                    # Convert to floats (or ints if you prefer)
                    num1 = int(parts[0])
                    num2 = int(parts[1])
                    result.append([num1, num2])
                except ValueError:
                    # Skip lines that don't contain valid numbers
                    continue
    return result

def get_area(row,col):
   r1, c1 = row
   r2, c2 = col
   return ((abs(r2 - r1) +1 ) * (abs(c2 - c1) + 1))


redTiles = read_numbers_from_file(filename)
part1 = 0
for r in redTiles:
    for s in redTiles:
        if (get_area(r,s) > part1) and r != s:
            part1 = get_area(r,s) 

print ("Part1 :" + str(int(part1)))


def populate_green_tiles(red_tile_set):
    minY = -1
    minX = -1
    maxX = -1
    maxY = -1
    returnThis = []
    #populate the outer perimeter
    for a in red_tile_set:
        for b in red_tile_set:
            a1,a2 = a
            b1,b2 = b
            if (a1 == b1):
                for x in range(a2 + 1,b2):
                    newCoor = []
                    newCoor.append(a1)
                    newCoor.append(x)
                    if not newCoor in returnThis:
                        returnThis.append(newCoor)
            if (a2 == b2):
                for x in range(a1 + 1,b1):
                    newCoor = []
                    newCoor.append(x)
                    newCoor.append(a2)
                    if not newCoor in returnThis:
                        returnThis.append(newCoor)
    return returnThis

greenTiles = populate_green_tiles(redTiles)

def is_green_tile(coor,green_tiles,red_tiles):
    x,y = coor
    l = False
    r = False
    u = False
    d = False
    for rx,ry in red_tiles:
        if rx == x and ry < y:
            u = True
        if rx == x and ry > y:
             d = True
        if ry == y and rx < x:
             l = True
        if ry == y and rx > x:
             r = True
        if l and r and d and u:
            break
    for rx,ry in green_tiles:
         if rx == x and ry < y:
            u = True
         if rx == x and ry > y:
           d = True
         if ry == y and rx < x:
            l = True
         if ry == y and rx > x:
            r = True
         if l and r and d  and u:
             break
    return l and d and u and r
