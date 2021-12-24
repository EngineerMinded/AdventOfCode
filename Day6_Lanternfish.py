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
    # Create a list for the potential of new LanternFish
    newLanternFish = []
    # Change the numbers of the current lanternfish and add new ones to the new list if need be
    for x in range(len(lanternFishList)):
        if int(lanternFishList [x]) > 0:
            lanternFishList[x] -= 1
        else:
            lanternFishList[x] = 6
            newLanternFish.append(8)
    for x in range(len(newLanternFish)):
        lanternFishList.append(newLanternFish[x])
    return lanternFishList

''' Main Program starts here '''

lanternFishMetaData = getFileInformation(fileName).split(",")
for i in range(len(lanternFishMetaData)):
    lanternFish.append(int(lanternFishMetaData[i]))
Day = 0
while Day <= 256:
    print ("Day " + str(Day) + " : Number Of LanternFish : " + str(len(lanternFish)) )
    lanternFish = evaluateLanternFishList(lanternFish)
    Day+=1
