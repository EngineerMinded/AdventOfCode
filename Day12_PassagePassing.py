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

    def __init__ (self, iD) :
        #initializing a new Cave
        self.ID = iD
        self.subCaves = []
        numberOfEnds = 0

    def addCave(cave2BeAdded):
        # create a new cave. add it if it already does not exist
        duplicateCave = False
        for u in subCaves:
            if u.ID == cave2BeAdded.ID:
                for v in cave2BeAdded.subCaves:
                    u.addCave(v)
                    duplicateCave = True
            if not duplicateCave:
                subCaves.append(cave2BeAdded)

    def countEnds(endCount):
        # count caves that say End
        for w in subCaves:
            if w.ID == "end":
                endCount += 1
            endCount = w.countEnds(endCount)
        return endCount

commandList = []
listOfCaves = []
