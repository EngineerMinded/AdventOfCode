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
#fileName = ("Day9_TestCase.PZL")
lowPoints = 0
File = open (fileName)
fileMeta = File.read().splitlines()
File.close()
MapMatrix = []
basinCenterList = []
for n in range(len(fileMeta)):
    MapMatrix.append(list(fileMeta[n]))
    #print (MapMatrix[n])
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
    return answer

for x in range(len(MapMatrix)):
    for y in range(len(MapMatrix[0])):
        if isLowPoint(x,y):
            basinCenterList.append(str(x)  + "," + str(y))
            lowPoints += int(MapMatrix[x][y]) + 1
print ("The value of the low points has been evaluated as " + str(lowPoints) )
''' With part one done, we move to Part 2 '''
previouslyAccessedNodes = []
def calculateBasinSize(x,y):

    def getMemberInformation(x,y):
        #print ("Accessing : " + str(x) +" "+ str(y))
        localTotalWellCount = 1
        previouslyAccessedNodes.append(str(x) +","+ str(y))

        def nodeHasNotBeenAccessed(x,y):
            for g in range(len(previouslyAccessedNodes)):
                coordinates = previouslyAccessedNodes[g].split(",")
                if int(coordinates[0]) == x and int(coordinates[1]) == y:
                    return False
            return True

        ''' Check surrounding points and return getMemberInforMation '''
        if x > 0:
            if int(MapMatrix[x - 1][y]) < 9 and nodeHasNotBeenAccessed(x - 1 , y):
                localTotalWellCount += getMemberInformation(x - 1, y)
        if y > 0:
            if int(MapMatrix[x][y - 1]) < 9 and nodeHasNotBeenAccessed(x, y - 1):
                localTotalWellCount += getMemberInformation(x, y - 1)
        if x < len(MapMatrix) - 1:
            if int(MapMatrix[x + 1][y]) < 9 and nodeHasNotBeenAccessed(x + 1, y):
                localTotalWellCount += getMemberInformation(x + 1, y)
        if y < len(MapMatrix[x]) - 1:
            if int(MapMatrix[x][y + 1]) < 9 and nodeHasNotBeenAccessed(x, y + 1):
                localTotalWellCount += getMemberInformation(x, y + 1)
        return localTotalWellCount

    return getMemberInformation(x, y)

finalValues = []
for h in range(len(basinCenterList)):
    basinListMetaData = basinCenterList[h].split(",")
    #print ("Starting low point " + str(h))
    finalValues.append(calculateBasinSize(int(basinListMetaData[0]), int(basinListMetaData[1])))
#print (finalValues)
finalCalculation = 1
for e in range(3):
    currentHighAddress = 0
    currentHighValue = 0
    for d in range(len(finalValues)):
        if finalValues[d] > currentHighValue:
            currentHighValue = finalValues[d]
            currentHighAddress = d
    finalValues.pop(currentHighAddress)
    finalCalculation *= currentHighValue
print (" The final calculation was evauated as :" + str(finalCalculation))
