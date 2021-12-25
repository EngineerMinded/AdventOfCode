'''
Wayne Mack
(c)2021 Engineerminded

------------------------------------
Day 9 : Smoke Basin
Written in: Python
------------------------------------
https://adventofcode.com/2021/day/9

ACHIEVED FIRST GOLD COIN

'''

fileName = ("Day9.PZL")
fileName = ("Day9_TestCase.PZL")
lowPoints = 0
File = open (fileName)
fileMeta = File.read().splitlines()
File.close()
MapMatrix = []
for n in range(len(fileMeta)):
    MapMatrix.append(list(fileMeta[n]))
    print (MapMatrix[n])
''' We now have our map matrix, let's continue '''

def isLowPoint(x,y):
    if x == 0:
        xu = 10
    else:
      xu = int(MapMatrix[x - 1][y])
    if x == len(MapMatrix) - 1:
        xd = 10
    else:
        xd = int(MapMatrix[x + 1][y])
    if y == 0:
        yl = 10
    else:
        yl = int(MapMatrix[x][y - 1])
    if y == len(MapMatrix[0]) - 1:
        yr = 10
    else:
        yr = int(MapMatrix[x][y + 1])
    xTarget = int(MapMatrix[x][y])
    answer  = xTarget < xu and xTarget < xd and xTarget < yl and xTarget < yr
    print (str(xTarget)+": "+ str(xd) +" "+ str(xu) +" "+ str(yl) +" "+ str(yr) + " "+ str(answer))
    return answer

for x in range(len(MapMatrix)):
    for y in range(len(MapMatrix[0])):
        if isLowPoint(x,y):
            lowPoints += int(MapMatrix[x][y]) + 1
print ("The value of the low points has been evaluated as " + str(lowPoints) )
