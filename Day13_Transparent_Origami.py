'''
  Wayne Mack
  (c)2020 EngineerMinded
  -------------------------------------
  Day 13 : Transparent Origami
  Written in: Python
'''
coordinates = []
origamiPlot = []
parsedInstructions = []

fileName = ("Day13.Puzzle")
File = open(fileName)
plotData  = File.read().splitlines()
File.close()

def readAndParseData (plotData):
    global coordinates
    global parsedInstructions

    for line in plotData:
        if line != "":
            dataLine = line.split()
            if len(dataLine) == 3:
                # if this is true, it is a instructions so . . .
                plotValue = dataLine[2].split("=")
                passThisList = []
                passThisList.append(plotValue[0])
                passThisList.append(int(plotValue[1]))
                parsedInstructions.append(passThisList)
            else :
                numberSet = line.split(",")
                passThisList = []
                passThisList.append(int(numberSet[0]))
                passThisList.append(int(numberSet[1]))
                coordinates.append(passThisList)

readAndParseData(plotData)
print (coordinates)
print (parsedInstructions)

def foldOrigami (coordinates, parsedInstructions):

    def foldAlongXAxis (xFold, coordinates):
        for unit in range(len(coordinates)):
            if coordinates[unit][0] > xFold:
                deviation = coordinates[unit][0] - xFold
                coordinates[unit][0] = xFold - deviation
        return coordinates

    def foldALongYAxis (yFold, coordinates):
        for unit in range(len(coordinates)):
            if coordinates[unit][1] > yFold:
                deviation = coordinates[unit][1] - yFold
                coordinates[unit][1] = yFold - deviation
        return coordinates

    for fold in parsedInstructions:
        if fold[0] == "x":
            coordinates = foldAlongXAxis(fold[1],coordinates)
        elif fold[0] == "y":
            coordinates = foldALongYAxis(fold[1],coordinates)
    return coordinates

coordinates = foldOrigami(coordinates, parsedInstructions)
print (coordinates)

def plotWithCoordinates (coordinates):
    xMax = 0
    yMax = 0
    for n in coordinates:
        if n[0] > xMax:
            xMax = n[0]
        if n[1] > yMax:
            yMax = n[1]
    print (str(xMax) +" " + str(yMax))
    matrix = [ ["."] * (yMax+1) for _ in range(xMax + 1)]
    for i in coordinates:
        matrix[i[0]][i[1]] = "#"
    return matrix

finalMatrix = (plotWithCoordinates(coordinates))
part1Count = 0
for x in finalMatrix:
    for y in x:
        if y == "#":
            part1Count += 1
print ("The number of Elements in the Matrix in part one is :" +str(part1Count))
for i in finalMatrix:
    TextLine = ""
    for j in i:
        if j == "#":
            TextLine += "#"
        else:
            TextLine += " "
    print (TextLine)
