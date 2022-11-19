''' Day 5: Binary Boarding
    Wayne Mack
    Written in: Python
    Advent of Code 2020   '''

class BoardingPass:

    def __init__ (self, boardingPassData):
        self.passInfo = boardingPassData
        self.seatID = 0

    def findSeatID(self):
        binaryRange = [0,127]
        rowRange = [0,7]
        for letter in self.passInfo:
            if letter == "B":
                if (binaryRange[1] - binaryRange[0] == 1):
                    binaryRange[0] = binaryRange[1]
                else:
                    binaryRange[0] = binaryRange[0] + int(int(binaryRange[1] - binaryRange[0]) / 2) + 1
            elif letter == "F":
                if (binaryRange[1] - binaryRange[0] == 1):
                    binaryRange[1] = binaryRange[0]
                else:
                    binaryRange[1] = binaryRange[1] - int(int (binaryRange [1] - binaryRange[0]) /2) -1
            elif letter == "R":
                if (rowRange[1] - rowRange[0] == 1):
                    rowRange[0] = rowRange[1]
                else:
                    rowRange[0] = rowRange[0] + int(int(rowRange[1] - rowRange[0]) / 2) + 1
            elif letter == "L":
                if (rowRange[1] - rowRange[0] == 1):
                    rowRange[1] = rowRange[0]
                else:
                    rowRange[1] = rowRange[1] - int(int (rowRange [1] - rowRange[0]) /2) -1
            #print ( str(binaryRange) + " " + str(rowRange))
        #print ("FINAL: " + str(binaryRange) + " " + str(rowRange))
        self.seatID = (binaryRange[1] * 8) + rowRange[1]
        print ("Seat Number is :" + str(self.seatID) )


file = open ("Day5.data")
boardingPassData = file.read().splitlines
file.close()

occupiedSeatList = []
''' Part One '''
highestSeatNo = 0
for bpD in boardingPassData():
    d = BoardingPass(bpD)
    d.findSeatID()
    occupiedSeatList.append(d.seatID) # for part two
    if d.seatID > highestSeatNo:
        highestSeatNo = d.seatID
print ("The highest Seat Number number in this series is :" + str(highestSeatNo))

for u in range(highestSeatNo):
    foundNumber = False
    for v in occupiedSeatList:
        if u == v:
            foundNumber = True
    if not foundNumber:
        print (u)
