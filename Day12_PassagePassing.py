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

    def __init__(self, *args):
        self.firstSubID = "none"
        if len(args) > 1:
            self.ID = args[0]
            self.firstSubID = [1]
        else:
            self.ID = args[0]


        subCaves = []
        if self.firstSubID != "none":
            subCaves.append(Cave(self.firstSubID))
        self.numberOfEnds = 0
        print ("Cave :" + str(self.ID))

    def addCave(cave2BeAdded):
        print ( iD + " :" + str(subcaves))
        # create a new cave. add it if it already does not exist
        for u in subCaves:
            foundExisting = False
            if u.ID == cave2BeAdded.ID:
                for v in cave2BeAdded.subCaves:
                    u.addCave(v)
                    foundExisting = True
        if not foundExisting:
            subCaves.append(Cave(cave2BeAdded, "none"))

    def countEnds(endCount):
        # count caves that say End
        for w in subCaves:
            if w.ID == "end":
                endCount += 1
            endCount = w.countEnds(endCount)
        return endCount


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

    commandData = command.split("-")
    if (commandData[0] != "start"):
        foundExisting = False
        for w in listOfCaves:
            if w.ID == commandData[0]:
                command1 = commandData[1]
                w.addCave(command1)
                foundExisting = True
        if not foundExisting:
            listOfCaves.append(Cave(commandData[0],commandData[1]))
