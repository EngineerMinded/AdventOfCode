'''
Wayne Mack
(c)2021 EngineerMinded


Program: Something about Bingo and a Squid
Written in: Python
------------------------------------------
NOTE: This is an activity for:
Advent of Code
https://adventofcode.com/2021/day/4
------------------------------------------

ACHIEVMENT: OBTAINED FIRST GOLD STAR
ACHIEVMENT: OBTAINED SECOND GOLD STAR

'''

def fileRead(fileName):
    '''
    read the file data and return it's contents
    as an arrayToReturn
    '''
    file = open (fileName)
    arrayToReturn = file.read().splitlines()
    file.close()
    return arrayToReturn
winningFinalNumber = 0
selectedNumbers = []
bingoCards = []
bingoSelectedGrids = []
def parseBingoData (inputData):
    '''
    The Bingo data consist of the called number as list level 0, use The
    mathematic equation numberOfCards = (totalNumberOfItemsInList / 6) 
    to make sense of parseing the data.
    '''
    global selectedNumbers
    selectedNumbers = inputData[0].split(",")
    numberOfCards = (len(inputData) / 6)
    arrayAddressCounter = 1
    for i in range(int(numberOfCards)):
        arrayAddressCounter += 1
        dataToBingoCard = inputData[arrayAddressCounter] + " " + inputData[arrayAddressCounter + 1] + " " + inputData[arrayAddressCounter + 2]+ " " + inputData[arrayAddressCounter + 3]+ " " + inputData[arrayAddressCounter + 4]
        bingoCards.append (dataToBingoCard.split())
        bingoSelectedGrids.append (["0"] * 25)
        arrayAddressCounter += 5
def addSelectedNumberAndWinningCardDetermination (bingoCard, selectedNumber):
    for i in range(len(bingoCards[bingoCard])):
        #print (str(selectedNumber) + " " + str(bingoCards[bingoCard][i]))
        if selectedNumber == bingoCards[bingoCard][i]:
            bingoSelectedGrids[bingoCard][i] = "1"
    return bingoCardIsAWinner(bingoCard, selectedNumber)

def bingoCardIsAWinner (bingoCard, selectedNumber):
    global winningFinalNumber
    for u in range(5):
        if bingoSelectedGrids[bingoCard][u] == "1" and bingoSelectedGrids[bingoCard][u + 5] == "1" and bingoSelectedGrids[bingoCard][u + 10] == "1" and bingoSelectedGrids[bingoCard][u + 15] == "1" and bingoSelectedGrids[bingoCard][u + 20] == "1":
            winningFinalNumber = selectedNumber
            return True
        if bingoSelectedGrids[bingoCard][( u * 5) ] == "1" and bingoSelectedGrids[bingoCard] [( u * 5) + 1] == "1" and bingoSelectedGrids[bingoCard] [( u * 5) + 2] == "1" and bingoSelectedGrids[bingoCard] [( u * 5) + 3] == "1" and bingoSelectedGrids[bingoCard] [( u * 5) + 4] == "1":
            winningFinalNumber = selectedNumber
            return True
    return False

def finalScoreTally (bingoCard):
    #print (bingoSelectedGrids[bingoCard])
    #print (bingoCards[bingoCard])
    #print (winningFinalNumber)
    Answer = 0
    for i in range(25):
        if bingoSelectedGrids[bingoCard][i] == "0":
            Answer += int(bingoCards[bingoCard][i])
    return Answer * int(winningFinalNumber)

def PartOne():
    '''
    This function will draw numbers from the array of winning
    numbers until a winner in the BIngo cards are declared. it
    will then return the winning tallyWinningScore
    '''
    global selectedNumbers
    numbersToDraw = fileRead("Day4.PZL")
    parseBingoData (numbersToDraw)
    #print (bingoCards)
    #print (selectedNumbers)
    for i in range(len(numbersToDraw)):
        for j in range(len(bingoCards)):
            if addSelectedNumberAndWinningCardDetermination(j, selectedNumbers[i]):
                print ("Bingo Card Number " + str(j) + " is the winning one with a score of : " + str(finalScoreTally(j)))
                exit()
    print ("Apparently something is wrong. there is no winner")
completedBingoCards = []
def bingoCardWasNotAlreadyCalled(checkThisNumber):
    global completedBingoCards
    for i in range(len(completedBingoCards)):
        if completedBingoCards[i] == checkThisNumber:
            return False

    completedBingoCards.append(checkThisNumber)
    return True

def PartTwo():
    '''
    Alot of this will be a modification of the Part One program.
    We now need to figure out the last one that is going to win
    '''
    global selectedNumbers
    numbersToDraw = fileRead("Day4.PZL")
    parseBingoData (numbersToDraw)
    #print (bingoCards)
    #print (selectedNumbers)
    for i in range(len(numbersToDraw)):
        for j in range(len(bingoCards)):
            if (addSelectedNumberAndWinningCardDetermination(j, selectedNumbers[i])) and (bingoCardWasNotAlreadyCalled(j)):
                print ("Bingo Card Number " + str(j) + " won with a score of : " + str(finalScoreTally(j)))
# NOTE: Comment out PartOne() below to execute Part 2
PartOne()
PartTwo()
