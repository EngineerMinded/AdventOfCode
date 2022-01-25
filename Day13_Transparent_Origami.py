'''
  Wayne Mack
  (c)2020 EngineerMinded
  -------------------------------------
  Day 13 : Transparent Origami
  Written in: Python
'''
import sys
coordinates = []
origamiPlot = []
parsedInstructions = []
xMax = 0
yMax = 0
fileName = ("Day13.TestCase.Puzzle")
File = open(fileName)
plotData  = File.read().splitlines()
File.close()

def readAndParseData (plotData):
    global xMax
    global yMax
    global coordinates
    global parsedInstructions

    for line in plotData:
        if line != "":
            dataLine = line.split()
            if len(dataLine) == 3:
                # if this is true, it is a instructions so . . .
                plotValue = dataLine[2].split("=")
                parsedInstructions.append(plotValue)
            else :
                numberSet = line.split(",")
                if int(numberSet[0]) > xMax:
                    xMax = int(numberSet[0])
                if int(numberSet[1]) > yMax:
                    yMax = int(numberSet[1])
                coordinates.append(numberSet)

readAndParseData(plotData)
print ("xMax : " + str(xMax))
print ("yMax : " + str(yMax))
print (coordinates)
print (parsedInstructions)

def foldOrigami (coordinates, parsedInstructions):
    for fold in parsedInstructions:
        if fold[0] == "x":
            
