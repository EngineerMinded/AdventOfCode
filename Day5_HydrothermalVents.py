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

class Vector:
    x1 = 0
    x2 = 0
    y1 = 0
    y2 = 0
    def __init__ (self, metaData):
        self.metaData = metaData
        parseData = metaData.split()
        parseData[1] = ","
        metaData = str(parseData[0]) + str(parseData[1]) + str(parseData[2])
        parseData = metaData.split(",")
        self.x1 = int(parseData[0])
        self.y1 = int(parseData[1])
        self.x2 = int(parseData[2])
        self.y2 = int(parseData[3])
    def addPoints (self,currentArray):
        # iteration to disregard diagional lines
        if (self.x1 != self.x2) and (self.y1 != self.y2):
            return currentArray
        if (self.x1 != self.x2):
            if (self.x1 < self.x2):
                for i in range(self.x1, self.x2 +1 ):
                    currentArray.append(str(i) + "," + str(self.y1))
            else:
                for i in range(self.x2 +1 , self.x1):
                    currentArray.append(str(i) + "," + str(self.y1))
        elif(self.y1 != self.y2):
            if (self.y1 < self.y2):
                    for i in range(self.y1, self.y2 +1 ):
                        currentArray.append(str(self.x1) + "," + str(i))
            else:
                for i in range(self.y2 +1 , self.y1):
                    currentArray.append(str(self.x1) + "," + str(i))
        else:
            currentArray.append(str(self.x1) + "," + str(self.x2))
        return currentArray

def fileRead(fileName):
    '''
    read the file data and return it's contents
    as an arrayToReturn
    '''
    file = open (fileName)
    arrayToReturn = file.read().splitlines()
    file.close()
    return arrayToReturn
vectorArray = []
pointArray = []
pointCounter = []
def PartOne():
    global vectorArray
    global pointArray
    global pointCounter
    rawData = fileRead("Day5.PZL")
    for i in range(len(rawData)):
        vectorArray.append(Vector(rawData[i]))
        pointArray = vectorArray[i].addPoints(pointArray)
    # Now you have your point array and even duplicate. Let's sparce them to see which are duplicates
    # start by adding the first One

    def duplicatePointExists(pointToFind):
        global pointCounter
        for i in range(len(pointCounter)):
            if pointCounter[i].pointExists(pointToFind):
                return True
        return False
    #print (pointArray)
    duplicateCount = 0
    for i in range(len(pointArray)):
        #print (str(i))
        for j in range(len(pointArray)):
            if (i != j and pointArray[i] == pointArray [j]):
                alreadyExists = False
                for k in range(len(pointCounter)):
                    if pointCounter[k] == pointArray[i]:
                        alreadyExists = True
                if not alreadyExists:
                    pointCounter.append(pointArray[i])
                    duplicateCount += 1
                    print (str(pointArray[i]) + " Found Duplicate : " + str(duplicateCount)) + " of Total :" + str(i) + " / " +str(len(pointArray))
    print str(len(pointCounter))










PartOne()
