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

ACHIEVMENT: OBTAINED FIRST GOLD STAR
'''
vectorArray = []
pointArray = []
pointCounter = []
Matrix = []
matrixBounds = 10
fileName = "Day5_TestCase.PZL"
numberOfAccesses = 0

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
    global numberOfAccesses
    intermediateArray = lineCommand.split()
    firstVector = intermediateArray[0].split(",")
    secondVector = intermediateArray[2].split(",")
    x1 = int(firstVector[0])
    y1 = int(firstVector[1])
    x2 = int(secondVector[0])
    y2 = int(secondVector[1])

    print (str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2))
    if (x1 != x2) and (y1 != y2):
        # Diagonal Modification for Part 2
        if abs(x2 - x1) == abs(y2 - y1):
            countUpX = True
            countUpY = True
            if (x2 < x1):
                countUpX = False
            if (y2 < y1):
                countUpY = False
            for i in range(abs(x2 - x1) +1):
                if countUpX:
                    dx = x1 + i
                else:
                    dx = x2 - i
                if countUpY:
                    dy = y1 + i
                else:
                    dy = y2 - i
                print str(dx) + " " + str(dy)
                Matrix[dx][dy] +=1
        else:
            print ("(Sequence not Used)")
        return
    if (x1 != x2):
        if (x1 < x2):
            for i in range(x1, x2 +1, 1):
                print (str(i) + " " + str(y1))
                Matrix[i][y1] +=1
                numberOfAccesses +=1
        else:
            for i in range(x1, x2 -1, -1):
                print (str(i) + " " + str(y1))
                Matrix[i][y1] +=1
                numberOfAccesses +=1
    elif(y1 != y2):
        if (y1 < y2):
            for i in range(y1, y2 +1, 1  ):
                print (str(x1) + " " + str(i))
                Matrix[x1][i] +=1
                numberOfAccesses +=1
        else:
            for i in range(y1, y2 - 1, -1):
                print (str(x1) + " " + str(i))
                Matrix[x1][i] +=1
                numberOfAccesses +=1
def Main():
    # Generate Matrix at all zeroes
    print ("Generating Matrix")
    global Matrix
    Matrix =[ [0] * matrixBounds for _ in range(matrixBounds)]
    #print (Matrix)
    print ("Reading Data and placing into Matrix")
    rawData = fileRead(fileName)
    for i in range(len(rawData)):
        dechiperLineAndPlaceIntoMatrix(rawData[i])
    for i in range(matrixBounds):
        print (Matrix[i])
    intersectCount = 0
    for u in range(matrixBounds):
        for v in range(matrixBounds):
            if Matrix[u][v] > 1:
                intersectCount+=1
    print ("Number of intersecting points has been evaluated as : " + str(intersectCount))
    print (numberOfAccesses)
Main()
