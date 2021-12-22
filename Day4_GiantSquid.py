'''
Wayne Mack
(c)2021 EngineerMinded


Program: Depth Difference indicator
Written in: Python
------------------------------------------
NOTE: This is an activity for:
Advent of Code
https://adventofcode.com/2021/day/4
------------------------------------------

'''
class BingoCard:
    ''' These are individual bingo Card Objects '''
    cardNumbers = []
    winningSquares = []

    def populateCards(dataInput):
        cardNumbers = dataInput.split()
        winningSquares = [0] * 25

def fileRead(fileName):
    file = open (fileName)
    arrayToReturn = file.read().splitlines()
    file.close()
    return arrayToReturn

def parseBingoData (inputData):
    '''
    The Bingo data consist of the called number as list level 0, use The
    mathematic equation numberOfCards = (totalNumberOfItemsInList / 10) - 1
    to make sense of parseing the data.

    '''
    selectedNumbers = inputdata[0].split(",")
    numberOfCards = (len(inputData) / 10) - 1

    bingocards = []
    arrayaddressCounter = 1
    for i in range(numberOfCards):
        bingoCards[i] =
