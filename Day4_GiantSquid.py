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
        ''' Constructor '''
        cardNumbers = dataInput.split()
        winningSquares = [0] * 25

    def addWinningNumberAndDetermineWinner (winningNumber):
        '''
        Add a number and determine if this card is the winner by returning
        the next function
        '''
        for x in range(len(cardNumbers)):
            if cardNumber[x] == winningNumber:
                winningSquares[x] = 1
                break
        return thereIsAWinner(winningNumber)

    def thereIsAWinner (winningNumber):
        '''
        Determine if any rows or columns have called Bingo
        '''
        for u in range(5):
            if winningSquares[u] == 1 and winningSquares [u + 5] == 1 and winningSquares [u + 10] == 1 and winningSquares [u + 15] == 1 and winningSquares [u + 20] == 1:
                gameWinningNumber = winningNumber
                return True
        for v in range (5):
            if winningSquares[( u * 5) ] == 1 and winningSquares [( u * 5) + 1] == 1 and winningSquares [( u * 5) + 2] == 1 and winningSquares [( u * 5) + 3] == 1 and winningSquares [( u * 5) + 4] == 1:
                gameWinningNumber = winningNumber
                return True
        # if the program made it here there was not row and now, it has been ruled as False
        return False

    def tallyWinningScore():
        '''
        If a winner is declared, tally up the score and
        return the winning score. this is the objective
        of the Program
        '''
        returnAnswer = 0
        for i in range(25):
            if winningSquare[i] == 0:
                returnAnswer += winningSquare[i]
        return returnAnswer * gameWinningNumber
def fileRead(fileName):
    '''
    read the file data and return it's contents
    as an arrayToReturn
    '''
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
        #print (dataToBingoCard)
        bingoCards.append (BingoCard(dataToBingoCard))
        arrayAddressCounter += 5
def Main():
    '''
    This function will draw numbers from the array of winning
    numbers until a winner in the BIngo cards are declared. it
    will then return the winning tallyWinningScore
    '''
    numbersToDraw = fileRead("Day4.PZL")
    parseBingoData (numbersToDraw)
    for i in range(len(numbersToDraw)):
        for j in range(len(bingoCards)):
            if bingoCards[j].addWinningNumberAndDetermineWinner(numbersToDraw[i]):
                print ("Bingo card " + str(j + 1) + " has won. The score for this card is :" + str(bingoCards[j].tallyWinningScore))
    print ("Apparently something is wrong. there is no winner")
Main()
