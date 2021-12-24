'''
Wayne Mack
(c)2021 EngineerMinded


Program: Crabs with Submarines
Written in: Python
------------------------------------------
NOTE: This is an activity for:
Advent of Code
https://adventofcode.com/2021/day/7
------------------------------------------

ACHIEVMENT: OBTAINED FIRST GOLD STAR
'''
fileName = ("Day7_TestCase.PZL")
fileName = ("Day7.PZL")
crabPositions = []
def getFileInformation (fName):
    ''' Read Data from the file and, return as list to be evaluated '''
    File = open (fName)
    returnThisList = File.read().splitlines()
    File.close()
    return returnThisList[0]

def determineBestPosition(listFromSource):
    # get the minimum Number
    lowestNumber = 9999999999999
    highestNumber = -9999999999999
    for u in range(len(listFromSource)):
        if listFromSource[u] < lowestNumber:
            lowestNumber = listFromSource[u]
        if listFromSource[u] > highestNumber:
            highestNumber = listFromSource[u]
    def tallyTotalPoints (medianNumber, listFromSource):
        totalPoints = 0
        for x in range(len(listFromSource)):
            totalPoints += abs(listFromSource[x] - medianNumber)
        return totalPoints
    bestNumber = 999999999999999
    for v in range(highestNumber - lowestNumber):
        if tallyTotalPoints(v,listFromSource) < bestNumber:
            bestNumber = tallyTotalPoints(v,listFromSource)
    return bestNumber


def PartOne():
    global crabPositions
    getData = (getFileInformation(fileName).split(","))
    for n in range(len(getData)):
        crabPositions.append(int(getData[n]))
    bestPoints = determineBestPosition(crabPositions)
    print ("The bestpoints points tallied are :" + str(bestPoints))

PartOne()
