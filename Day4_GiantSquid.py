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
    gameWinningNumber = 0

    def __init__ (self, dataInput):
        cardNumbers = dataInput.split()
        winningSquares = [0] * 25

    def addWinningNumber (winningNumber):
        for x in range(len(cardNumbers)):
            if cardNumber[x] == winningNumber:
                winningSquares[x] = 1
                break
        return thereIsAWinner(winningNumber)

    def thereIsAWinner (winningNumber):
        for u in range(5):
            if winningSquares[u] == 1 and winningSquares [u + 5] = 1 and winningSquares [u + 10] = 1 and winningSquares [u + 15] = 1 and winningSquares [u + 20] = 1:
                gameWinningNumber = winningNumber
                return True
        for v in range (5):
            if winningSquares[( u * 5) ] == 1 and winningSquares [( u * 5) + 1] = 1 and winningSquares [( u * 5) + 2] = 1 and winningSquares [( u * 5) + 3] = 1 and winningSquares [( u * 5) + 4] = 1:
                gameWinningNumber = winningNumber
                return True
        return False

    def tallyWinningScore():
        returnAnswer = 0
        for i in range(25):
            if winningSquare[i] = 0:
                returnAnswer += winningSquare[i]
        return returnAnswer * gameWinningNumber
def fileRead(fileName):
    file = open (fileName)
    arrayToReturn = file.read().splitlines()
    file.close()
    return arrayToReturn


selectedNumbers = []
bingoCards = []

def parseBingoData (inputData):
    '''
    The Bingo data consist of the called number as list level 0, use The
    mathematic equation numberOfCards = (totalNumberOfItemsInList / 10) - 1
    to make sense of parseing the data.
    '''
    selectedNumbers = inputData[0].split(",")
    numberOfCards = (len(inputData) / 6)
    arrayAddressCounter = 1
    for i in range(int(numberOfCards)):
        arrayAddressCounter += 1
        dataToBingoCard = inputData[arrayAddressCounter] + " " + inputData[arrayAddressCounter + 1] + " " + inputData[arrayAddressCounter + 2]+ " " + inputData[arrayAddressCounter + 3]+ " " + inputData[arrayAddressCounter + 4]
        print (dataToBingoCard)
        bingoCards.append (BingoCard(dataToBingoCard))
        arrayAddressCounter += 5

parseBingoData (fileRead ("Day4.PZL"))
