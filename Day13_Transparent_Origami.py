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
        dataLine = line.split()
        if len(dataLine)  == 1:
            # if this is true, it is a coordinate so . . .
            xNow,yNow = dataLine.split(",")
            if xNow > xMax:
                xMax = xNow
            if yNow > yMax:
                yMax = yNow
            data2Insert = []
            data2Insert.append(xNow)
            data2Insert.append(yNow)
            coordinates.append(data2Insert)
        elif len(dataLine) == 3:
            # if this is true, it is a instructions so . . .
            plot,value = dataLine[2].split("=")
            data2Insert = []
            data2Insert.append(plot)
            data2Insert.append(value)
            parsedInstructions.append(data2Insert)
print (plotData)
readAndParseData(plotData)
print (coordinates)
print (parsedInstructions)
