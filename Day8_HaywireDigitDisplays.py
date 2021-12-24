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
NumericValues = []
metaData = []
FileName = ("Day8_TestCase.PZL")
FileName = ("Day8.PZL")

def numericDigitDetermination (dataSet):
    ''' output is number '''
    dataSetNumber = len(dataSet):
    if dataSet = 2:
        return 1
    if dataSet = 3:
        return 7
    if dataSet = 4:
        return 4
    if dataSet = 5:
        print ("either 2, 3 or 5")
        return 2
    if dataSet = 6:
        print("either 6, 9 or 0")
        return 6
    if dataset = 7:
        return 8

def readInformationFromFile (FileName):
    ''' Read Data from the file and, return as list to be evaluated '''
    File = open (fileName)
    returnThisList = File.read().splitlines()
    File.close()
    return returnThisList

def ParseDataForPartOne (metaData):


def extractLast4Numbers (dataLine):
    numberList = []
    lineSplit = dataline.split("|")
    numericMetaData = lineSplit[1].split()
    for a in range len(numericMetaData):
        numberList.append(numericDigitDetermination(numericMetaData[a]))
    return numberList
