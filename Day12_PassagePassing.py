'''
Wayne Mack
(c)2021 EngineerMinded

------------------------------------
Day 11 : Passage Passing
Written in: Python
------------------------------------
https://adventofcode.com/2021/day/12

'''
''' This is the first time we will be using a class
    in Python. This may start a trend for the remainder
    of the projects '''

fileName = ("Day12.Puzzle")
fileName = ("Day12_TestCase1.Puzzle")
commandList = []

File = open(fileName)
commandList = File.read().splitlines()
File.close()
listEstablished = False

class Cave :

    def __init__(self, ID ):
        # CONSTRUCTOR
        self.ID = ID
        self.subCaves = []
        self.numberOfEnds = 0

    def countEnds(endCount):
        # count caves that say End
        for w in subCaves:
            if w.ID == "end":
                endCount += 1
            endCount = w.countEnds(endCount)
        return endCount

    def printAllCaves(self, spaceNumber):
        print (" " * spaceNumber + self.ID)
        for x in self.subCaves:
            x.printAllCaves(spaceNumber + 1)


    def addCave(self, parentCave , nextCave):
        returnThus = False
        # create a new cave. add it if it already does not exist
        if parentCave == self.ID:
            self.subCaves.append(Cave(nextCave))
            returnThus = True
        elif len(self.subCaves) == 0:
            return False
        for name in self.subCaves:
                    if name.addCave(parentCave , nextCave):
                        returnThus =  True
        return returnThus


caveEntrance = Cave("start")
print (commandList)
while len(commandList) > 0:
    addressesToPop = []
    for i in range(len(commandList)):

        splitData = commandList[i].split("-")
        if caveEntrance.addCave(splitData[0] , splitData [1]):
            commandList.pop(i)
            break
caveEntrance.printAllCaves(0)
