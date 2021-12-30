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
class Cave :

    def __init__(self, ID ):
        # CONSTRUCTOR
        self.ID = ID
        self.subCaves = []
        self.numberOfEnds = 0

    def addCave(self, cave2BeAdded):
        # create a new cave. add it if it already does not exist
        foundExisting = False
        for u in self.subCaves:
            if u.ID == cave2BeAdded.ID:
                for v in self.cave2BeAdded.subCaves:
                    u.addCave(v)
                    foundExisting = True
        if not foundExisting:
            self.subCaves.append(cave2BeAdded)

    def countEnds(endCount):
        # count caves that say End
        for w in subCaves:
            if w.ID == "end":
                endCount += 1
            endCount = w.countEnds(endCount)
        return endCount

    def printAllCaves(self, spaceNumber):
        for x in self.subCaves:
            print ("   " * spaceNumber + " " + x.ID )
            x.printAllCaves(spaceNumber + 1)



fileName = ("Day12.Puzzle")
fileName = ("Day12_TestCase1.Puzzle")
fileName = ("Day12_TestCase2.Puzzle")
fileName = ("Day12_TestCase3.Puzzle")

commandList = []
listOfCaves = []
File = open(fileName)
commandList = File.read().splitlines()
File.close()
for command in commandList:
    commandSet = command.split("-")
    duplicatePresent = False
    for currentList in listOfCaves:
        if commandSet[0] == currentList.ID:
            currentList.addCave(Cave(commandSet[1]))
            duplicatePresent = True
    if not duplicatePresent:
        listOfCaves.append(Cave(commandSet[0]))
        listOfCaves[-1].addCave(Cave(commandSet[1]))
print (len(listOfCaves))
print (len(commandList))
for x in listOfCaves:
    print ( x.ID)
    x.printAllCaves(0)

for e in commandList:
    commandSet = e.split("-")
    if commandSet[0] == "start":
        CaveList = Cave(commandSet[0])
        CaveList.addCave(commandSet[1])
        pop(e)
print (commandList)
