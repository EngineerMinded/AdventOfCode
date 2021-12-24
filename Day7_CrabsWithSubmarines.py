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
def getFileInformation (fName):
    ''' Read Data from the file and, return as list to be evaluated '''
    File = open (fName)
    returnThisList = File.read().splitlines()
    File.close()
    return returnThisList[0]

def determineBestPosition(listFromSource,trueForPart2):
    # get the minimum Number
    lowestNumber = 9999999999999
    highestNumber = -9999999999999
    for u in range(len(listFromSource)):
        if listFromSource[u] < lowestNumber:
            lowestNumber = listFromSource[u]
        if listFromSource[u] > highestNumber:
            highestNumber = listFromSource[u]

    def tallyTotalPoints (medianNumber, listFromSource, trueForPart2):
        totalPoints = 0
        for x in range(len(listFromSource)):
                # This loop determines fuel consumption for part one
                totalPoints += abs(listFromSource[x] - medianNumber)
                if trueForPart2:
                    accumulator = 0
                    for y in range(abs(listFromSource[x] - medianNumber) + 1):
                        if y > 0:
                            accumulator += y - 1
                    totalPoints += accumulator
        return totalPoints

    bestNumber = 99999999999999
    print (highestNumber - lowestNumber)
    for v in range(highestNumber - lowestNumber):
        if tallyTotalPoints(v,listFromSource,trueForPart2) < bestNumber:
            bestNumber = tallyTotalPoints(v,listFromSource,trueForPart2)
            #print (str (v) + " " +str(bestNumber))
    return bestNumber


def Main(trueForPart2):
    crabPositions = []
    getData = (getFileInformation(fileName).split(","))
    for n in range(len(getData)):
        crabPositions.append(int(getData[n]))
    bestPoints = determineBestPosition(crabPositions,trueForPart2)
    print ("The bestpoints points tallied are :" + str(bestPoints))

Main(False)
Main(True)
