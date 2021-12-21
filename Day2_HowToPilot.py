'''
Wayne Alexander Mack Jr.

(c)2021 EngineerMinded

----------------------------------------
How To Pilot

written in: Python

----------------------------------------
Day2 Activity on Advent To Code:

https://adventofcode.com/2021/day/2

ACHIEVEMENT: Earned GOLD STAR FOR PART ONE
ACHIEVEMENT: Earned SECOND GOLD STAR



'''
# Global VARIABLES
dataArray = 0
horizontalPosition = 0
Depth = 0
Aim = 0
def Main(partNumber):
    global dataArray
    global horizontalPosition
    global Depth
    global Aim
    print ("Program Start . . .")
    isAimFunction = False
    if partNumber == 2 :
        isAimFunction = True
    global dataArray
    dataArray = fileRead("Day2.PZL")
    for i in range(len(dataArray)):
        readAndDecipherData(dataArray[i],isAimFunction)
    reviewResults()
def fileRead(fileName):
    file = open (fileName)
    arrayToReturn = file.read().splitlines()
    file.close()
    return arrayToReturn
def readAndDecipherData(dataInput, isAimFunction):
    global horizontalPosition
    global Depth
    global Aim
    localInfo = dataInput.split()
    # print (localInfo)
    if (localInfo[0] == "forward"):
        if (isAimFunction):
            if (Aim != 0):
                Depth = Depth + (int(Aim) * int(localInfo[1]))
        horizontalPosition = horizontalPosition + int(localInfo[1])
    elif (localInfo[0] == "up"):
        if (isAimFunction):
            Aim = Aim - int(localInfo[1])
        else:
            Depth = Depth - int(localInfo[1])
    elif (localInfo[0] == "down"):
        if (isAimFunction):
            Aim = Aim + int(localInfo[1])
        else:
            Depth = Depth + int(localInfo[1])
    #END readAndDecipherData
def clearGlobalVariables():
    dataArray = 0
    Aim = 0
    Depth = 0
    horizontalPosition = 0
def reviewResults():
    print ("The horizontal Position is: " + str(horizontalPosition))
    print ("The Depth Position is: " + str(Depth))
    print ("Multiplied, the answer is: " + str(horizontalPosition * Depth))
Main(1)
clearGlobalVariables()
Main(2)
