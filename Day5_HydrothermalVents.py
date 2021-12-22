'''
Wayne Mack
(c)2021 EngineerMinded


Program: Hydrothermal Vents
Written in: Python
------------------------------------------
NOTE: This is an activity for:
Advent of Code
https://adventofcode.com/2021/day/5
------------------------------------------

'''
vectorArray = []
pointArray = []
pointCounter = []
Matrix = []

def fileRead(fileName):
    '''
    read the file data and return it's contents
    as an arrayToReturn
    '''
    file = open (fileName)
    arrayToReturn = file.read().splitlines()
    file.close()
    return arrayToReturn

def dechiperLineAndPlaceIntoMatrix(lineCommand):
    global Matrix
    intermediateArray = lineCommand.split()
    firstVector = intermediateArray[0].split(",")
    secondVector = intermediateArray[2].split(",")
    x1 = int(firstVector[0])
    y1 = int(firstVector[1])
    x2 = int(secondVector[0])
    y2 = int(secondVector[1])
    #print (str(x1) + " " + str(y1) + " " + str(y1) + " " + str(y2))
    if (x1 != x2) and (y1 != y2):
        return
    if (x1 != x2):
        if (x1 < x2):
            for i in range(x1, x2 + 1  ):
                Matrix[i][y1]+= 1
        else:
            for i in range(x2 + 1  , x1):
                Matrix[i][y1] += 1
    elif(y1 != y2):
        if (y1 < y2):
                for i in range(y1, y2 + 1  ):
                    Matrix[x1][i] += 1
        else:
            for i in range(y2 + 1  , y1):
                Matrix[x1][1] += 1


def PartOne():
    # Generate Matrix at all zeroes
    print ("Generating Matrix")
    global Matrix
    Matrix = [[0]* 10]*10
    print (Matrix)
    print ("Reading Data and placing into Matrix")
    rawData = fileRead("Day5_TestCase.PZL")
    for i in range(len(rawData)):
        dechiperLineAndPlaceIntoMatrix(rawData[i])
    print (Matrix)
    intersectCount = 0
    for u in range(10):
        for v in range(10):
            if Matrix[u][v] > 1:
                intersectCount+=1
    print ("Number of intersecting points has been evaluated as : " + str(intersectCount))
PartOne()
