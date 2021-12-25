'''
Wayne Mack
(c)2021 EngineerMinded


Program: Haywire Digit Displays
Written in: Python
------------------------------------------
NOTE: This is an activity for:
Advent of Code
https://adventofcode.com/2021/day/8
------------------------------------------

'''

FileName = ("Day8_TestCase.PZL")
FileName = ("Day8.PZL")



def numericDigitDetermination (dataSet):
    ''' output is number '''
    dataSetNumber = int(len(dataSet))

    if dataSetNumber == 2:
        return 1
    if dataSetNumber == 3:
        return 7
    if dataSetNumber == 4:
        return 4
    if dataSetNumber == 5:
        #print ("either 2, 3 or 5")
        return 2
    if dataSetNumber == 6:
        #print("either 6, 9 or 0")
        return 6
    if dataSetNumber == 7:
        return 8

def readInformationFromFile (fileName):
    ''' Read Data from the file and, return as list to be evaluated '''
    File = open (fileName)
    returnThisList = File.read().splitlines()
    File.close()
    return returnThisList

def extractLast4Numbers (dataLine):
    numberList = []
    lineSplit = dataLine.split("|")
    # print (lineSplit[1])
    numericMetaData = lineSplit[1].split()
    for a in range (len(numericMetaData)):
        numberList.append(numericDigitDetermination(numericMetaData[a]))
    return numberList

def ParseDataForPartOne ():
    global Filename
    numericValues = []
    metaData = readInformationFromFile(FileName)
    for i in range(len(metaData)):
        next4Numbers = extractLast4Numbers(metaData[i])
        for j in  range(len(next4Numbers)):
            numericValues.append(next4Numbers[j])
    return numericValues

def PartOne():
    numericValues = ParseDataForPartOne()
    # print (numericValues)
    countFor147or8 = 0
    for h in range(len(numericValues)):
        if numericValues[h] == 1 or numericValues[h] == 4 or numericValues[h] == 7 or numericValues[h] == 8:
            countFor147or8 += 1
    print ("There are " + str(countFor147or8) + " instances of numbers being 1, 4, 7, or 8.")

PartOne()
