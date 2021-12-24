'''
Wayne Mack
(c)2021 EngineerMinded


Program: Something about Lanternfish
Written in: Python
------------------------------------------
NOTE: This is an activity for:
Advent of Code
https://adventofcode.com/2021/day/6
------------------------------------------
ACHIEVMENT: EARNED FIRST STAR
ACHIEVMENT: EARNED SECOND STAR

'''
lanternFish = []
fileName = ("Day6_TestCase.PZL")
fileName = ("Day6.PZL")

def getFileInformation (fName):
    ''' Read Data from the file and, return as list to be evaluated '''
    File = open (fName)
    returnThisList = File.read().splitlines()
    File.close()
    return returnThisList[0]

def evaluateLanternFishList (lanternFishList):
    ''' An original lanternFish List by day will be the argument. The List
        returned will be the new list for that day
        Rules:
        - For Each day that passes (the calling of this function, a LanternFish's
          number will deplete by one unless it is zero.
        - If it is zero, it will reset to 6 and produce another lanternfish that
          starts off with a number of 8
        - The cycle contines the next day even with the new Lanternfish)'''
    newLanternFish = []
    for x in range(len(lanternFishList)):
        if int(lanternFishList [x]) > 0:
            lanternFishList[x] -= 1
        else:
            lanternFishList[x] = 6
            newLanternFish.append(8)
    for x in range(len(newLanternFish)):
        lanternFishList.append(newLanternFish[x])
    return lanternFishList

def PartOne():
    ''' Part one will use a simple approach but as we will find out in part two,
        This is terribly innefficent                                            '''
    def currentCount(LFList):
        tempList = [0] * 8
        for a in range(len(LFList)):
            tempList[LFList[a] - 1] +=1
        return tempList
    global lanternFish
    lanternFishMetaData = getFileInformation(fileName).split(",")
    for i in range(len(lanternFishMetaData)):
        lanternFish.append(int(lanternFishMetaData[i]))
    Day = 0
    while Day <= 80:
        print ("Day " + str(Day) + " : Number Of LanternFish : " + str(len(lanternFish)) )
        lanternFish = evaluateLanternFishList(lanternFish)
        Day+=1

def PartTwo():
    ''' For Part two, it had to be completed object orientated and differently
        because the program in part one would tie up system resources and take
        a long time to finish. This program will demonstrate both             '''
    lanternFish = []
    lanternFishMetaData = getFileInformation(fileName).split(",")
    for i in range(len(lanternFishMetaData)):
        lanternFish.append(int(lanternFishMetaData[i]))
    Day = 0
    fishByQuantity = [0] * 9
    for i in range(len(lanternFish)):
        fishByQuantity[lanternFish[i] ] += 1
    print (fishByQuantity)

    def tallyAllFish(currentList):
        newCycle = currentList[0]
        for i in range(8):
            currentList[i] = currentList[i + 1]
        currentList[8] = newCycle
        currentList[6] += newCycle
        return currentList

    def getTotalNumberOfFish (currentList):
        Total = 0
        for r in range(len(currentList)):
            Total += currentList[r]
        return Total
    while Day <= 256:
        print ("Day " + str(Day) + " Total LanternFish :" + str(getTotalNumberOfFish(fishByQuantity)) )
        Day +=1
        fishByQuantity = tallyAllFish(fishByQuantity)

PartOne()
PartTwo()
