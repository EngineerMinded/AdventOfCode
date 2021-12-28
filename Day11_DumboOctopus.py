'''
Wayne Mack
(c)2021 EngineerMinded

------------------------------------
Day 11 : Dumbo Octopus
Written in: Python
------------------------------------
https://adventofcode.com/2021/day/11


'''
octopusMatrix = []
generation = 0
numberOfFlashes = 0

fileName = ("Day11.Puzzle")
fileName = ("Day11_TestCase.Puzzle")
#fileName = ("Day11_TestCase2.Puzzle")
File = open(fileName)
fileMetaData  = File.read().splitlines()
File.close()
for i in  range(len(fileMetaData)):

     def columnFillIn (columnNumber):
         numberSet = []
         stringData = str(fileMetaData[columnNumber])
         columnMetaData = list(stringData)
         for j in range(len(columnMetaData)):
             numberSet.append(int(columnMetaData[j]))
         return numberSet

     octopusMatrix.append(columnFillIn(i))
for i in octopusMatrix:
    print (i)
# from here add the generational procedure

print ("After " + str (generation) + " steps, there have been " + str (numberOfFlashes) + " flashes!")
