''' Day 3: Toboggan Trajectory
    Wayne Mack
    Written in: Python
    Advent Of Code 2020       '''

class TobogganMap:

    def __init__ (self, mapData):
        self.mapMatrix = []
        for u in mapData:
            line = []
            for v in u:
                line.append(v)
            self.mapMatrix.append(line)

    def plotSlope (self, down, right):

        def plotAtPoint (down, right):
            if self.mapMatrix[down][right] == "#":
                self.mapMatrix[down][right] = "X"
            else:
                self.mapMatrix[down][right] = "O"

        yRange = len(self.mapMatrix)
        xRange = len(self.mapMatrix[0])
        originalRight = right
        originalDown = down
        while down < yRange :

            if right > xRange - 1:
                right = right - xRange
            plotAtPoint(down,right)
            down += originalDown
            right += originalRight

file = open ("Day3.data")
mapData = file.read().splitlines()
file.close()

map = TobogganMap(mapData)
map.plotSlope(1,3)

def getTreeCount (right, down):
    mapInFunction = TobogganMap(mapData)
    mapInFunction.plotSlope(down,right)
    treeCount = 0
    for x in mapInFunction.mapMatrix:
        for y in x:
            if y == "X":
                treeCount += 1
    return treeCount

''' Part One '''

print ("You will encounter " + str(getTreeCount(3,1)) + " trees!")

''' Part Two '''

totalTreeCount = 1
totalTreeCount *= getTreeCount(1,1)
totalTreeCount *= getTreeCount(3,1)
totalTreeCount *= getTreeCount(5,1)
totalTreeCount *= getTreeCount(7,1)
totalTreeCount *= getTreeCount(1,2)

print ("The total count with all trails taken are : " + str(totalTreeCount))
