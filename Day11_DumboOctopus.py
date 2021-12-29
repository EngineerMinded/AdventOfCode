'''
Wayne Mack
(c)2021 EngineerMinded

------------------------------------
Day 11 : Dumbo Octopus
Written in: Python
------------------------------------
https://adventofcode.com/2021/day/11

ACHIEVMENT : FIRST GOLD STAR
ACHIEVMENT : SECOND GOLD STAR

'''
octopusMatrix = []
generation = 0
numberOfFlashes = 0
fileName = ("Day11.Puzzle")
#fileName = ("Day11_TestCase.Puzzle")
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
print (" ")
def generationChange(oldOctopusMatrix):

    def flash(oldOctopusMatrix, x, y):
        global numberOfFlashes
        numberOfFlashes += 1
        oldOctopusMatrix[x][y] = 0
        xLow = x - 1
        xHigh = x + 1
        yLow = y - 1
        yHigh = y + 1
        if x == 0:
            xLow = x
        if x == len(oldOctopusMatrix) - 1:
            xHigh = x
        if y == 0:
            yLow = y
        if y == len(oldOctopusMatrix[x]) - 1:
            yHigh = y
        for u in range(xLow, xHigh + 1):
            for v in range(yLow, yHigh+ 1):
                if oldOctopusMatrix[u][v] > 0:
                    oldOctopusMatrix[u][v] += 1
                    if oldOctopusMatrix[u][v] > 9:
                        oldOctopusMatrix = flash(oldOctopusMatrix,u,v)
        return oldOctopusMatrix

    for column in range(len(oldOctopusMatrix)):
        for point in range(len(oldOctopusMatrix[column])):
            oldOctopusMatrix[column][point] +=1
    for column in range(len(oldOctopusMatrix)):
        for point in range(len(oldOctopusMatrix[column])):
            if oldOctopusMatrix[column][point] > 9:
                oldOctopusMatrix = flash(oldOctopusMatrix,column,point)
    return oldOctopusMatrix

def everyOctopusIsSynchronizing(currentOctopusMatrix):
    synchronizingCheck = currentOctopusMatrix[0][0]
    for u in range(len(currentOctopusMatrix)):
        for v in range(len(currentOctopusMatrix[u])):
            if (currentOctopusMatrix[u][v] != synchronizingCheck):
                return False
    return True

''' NOTE: comment out line below and replace with :
    while generation < 100:
    to demonstrate part one '''
    
while not everyOctopusIsSynchronizing(octopusMatrix):
    octopusMatrix =  generationChange(octopusMatrix)
    for octo in octopusMatrix:
        print octo
    print(" ")
    generation +=1
print ("After " + str (generation) + " steps, there have been " + str (numberOfFlashes) + " flashes!")
