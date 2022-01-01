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

caveList = dict()
fileName = ("Day12.Puzzle")
fileName = ("Day12_TestCase.Puzzle")
fileName = ("Day12_TestCase2.Puzzle")
fileName = ("Day12_TestCase3.Puzzle")
File = open(fileName)
fileMetaData  = File.read().splitlines()
print (fileMetaData)
for a in fileMetaData:
    data = (a.split("-"))
    caveList.update({data[0] : data[1]})
print (caveList)
