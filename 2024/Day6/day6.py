''' Wayne Mack
    Advent Of Code
    Day 6          '''

import csv
from enum import Enum

class Direction(Enum):
    NORTH = 1
    SOUTH = 2
    EAST = 3
    WEST = 4

class Guard:
    def __init__(self,gaurdMap):

        def findInitialPosition(matrix,char):
            for row_index, row in enumerate(matrix):
                for col_index in range(len(row)):
                    if char == row[col_index]:
                        return row_index, col_index
            return (0,0)

        self.grid = gaurdMap
        startingCoordinate = findInitialPosition(self.grid,'^')
        self.x = startingCoordinate[0]
        self.y = startingCoordinate[1]
        self.direction = Direction.NORTH
        self.spacesTravelled = 0
        self.yMax = len(self.grid)
        self.xMax = len(self.grid[0])

    def changeDirection(originalDirection):
        if originalDirection == Direction.NORTH:
            return Direction.EAST
        elif originalDirection == Direction.EAST:
            return Direction.SOUTH
        elif originalDirection == Direction.SOUTH:
            return Direction.WEST
        else:
            return Direction.NORTH
          


    
    def part1Move(self):
        finished = False
        while not finished:
            print ("iteration run" + str(self.x) +" " + str(self.y))
            if self.direction == Direction.WEST:
                if self.y > 0:
                    if self.grid[self.x][self.y - 1] == "#":
                        self.direction = Direction.NORTH
                    else:
                        self.y -= 1
                        if (self.grid[self.x][self.y] != "X"):
                            self.spacesTravelled += 1
                        self.grid[self.x][self.y] = "X"
                        
                else:
                    finished = True
            elif self.direction == Direction.SOUTH:
                if self.x < self.xMax - 1:
                    if self.grid[self.x + 1][self.y] == "#":
                        self.direction = Direction.WEST
                    else:
                        self.x += 1
                        if (self.grid[self.x][self.y] != "X"):
                            self.spacesTravelled += 1
                        self.grid[self.x][self.y] = "X"

                else:
                    finished = True
            elif self.direction == Direction.EAST:
                if self.y < self.yMax - 1: 
                    if self.grid[self.x][self.y + 1] == "#": 
                        self.direction = Direction.SOUTH
                    else:
                        self.y += 1
                        if (self.grid[self.x][self.y] != "X"):
                            self.spacesTravelled += 1
                        self.grid[self.x][self.y] = "X"
                else:
                    finished = True
            elif self.direction == Direction.NORTH:
                if self.x > 0:
                    if self.grid[self.x - 1][self.y] == "#":
                        self.direction = Direction.EAST
                    else:
                        self.x -= 1
                        if (self.grid[self.x][self.y] != "X"):
                            self.spacesTravelled += 1
                        self.grid[self.x][self.y] = "X"
                else:
                    finished = True

filename = "day6.txt"

def getMapData(file_path):

    matrix = []
    
    # Open the file and read it
    with open(file_path, mode='r') as file:
        # Read each line from the file
        for line in file:
            # Convert the line into a list of characters (removing newline)
            matrix.append(list(line.strip()))
    
    return matrix

guard=Guard(getMapData(filename))

for row in guard.grid:
    print (row)

guard.part1Move()

for row in guard.grid:
    print (row)
print (guard.spacesTravelled)
