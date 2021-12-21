'''
Wayne Mack
(c)2021 EngineerMinded


Program: Depth Difference indicator
Written in: Python
------------------------------------------
NOTE: This is an activity for:
Advent of Code
https://adventofcode.com/2021/day/3
------------------------------------------

ACHIEVEMENT: FIRST GOLD STAR:

ACHIEVMENT: OBTAINED SECOND GOLD STAR

'''
mostCommonArray = []
binaryListArray = []
gammaRate = ""
epsilonRate = ""

def PartOne():
    # First we want to read out binary numbers from fileName
    binaryListArray = getListFromFile("Day3.PZL")
    gammaRate = gammaRateDetermination(binaryListArray)
    epsilonRate = epsilonRateDetermination(gammaRate)
    print ("The gamma rate is : " + gammaRate + " or decimal " + str(binaryToDecimal(gammaRate)) + "!")
    print ("The epsilon rate is :"+ epsilonRate + " or decimal " + str(binaryToDecimal(epsilonRate))+ "!")
    print ("Multiplied, that is : " + str ( binaryToDecimal(gammaRate) * binaryToDecimal(epsilonRate)))

def getListFromFile(fileName):
    file = open (fileName)
    listing = file.read().splitlines()
    file.close()
    # the array is built, let's return it
    return listing

def gammaRateDetermination (arrayListToCheck):

    def binaryWordToCounter (BFC, binaryWord):
        for i in range(len(binaryWord)):
            if int(binaryWord[i]) == 1:
                BFC[i] = BFC[i] + 1
        return BFC

    binaryFrequencyCount = [0] * len(arrayListToCheck[0])
    gammaRateToReturn = ""
    for i in range(len(arrayListToCheck)):
        binaryFrequencyCount = binaryWordToCounter(binaryFrequencyCount, arrayListToCheck[i])
    for i in range (len(binaryFrequencyCount)):
        if binaryFrequencyCount[i] > len(arrayListToCheck) / 2:
            gammaRateToReturn = gammaRateToReturn + "1"
        else:
            gammaRateToReturn = gammaRateToReturn + "0"
    return gammaRateToReturn

def epsilonRateDetermination ( gammaRateInput):
    epsilonToReturn = ""
    for i in range(len(gammaRateInput)):
        if str(gammaRateInput[i]) == "1":
            epsilonToReturn += "0"
        else:
            epsilonToReturn += "1"
    return epsilonToReturn

def binaryToDecimal (rateInput):

    def exponent (n):
        a = 1
        count = 0
        while count < n:
            a = a * 2
            count += 1
        return a

    answer = 0
    for i in range(len(rateInput)):
        if rateInput[i] == "1":
            answer += exponent(len(rateInput) - 1 - i)
    return answer
# This function works with the part two part of this Program

def filterListToSpecificValue(lookingForSignifigantValue):

    def filterListAtBit(bitAddress, listToFilter):
        # create an empty revisedList
        revisedList = []
        # signifigantBitCounter tallies to count sought out bits
        signifigantBitCounter = 0
        for i in range(len(listToFilter)):
            if listToFilter[i][bitAddress] == "1":
                signifigantBitCounter+=1
        if (lookingForSignifigantValue):
            signifigantBitCriteria = (signifigantBitCounter >= (len(listToFilter) / 2))
        else :
            signifigantBitCriteria = (signifigantBitCounter < (len(listToFilter) / 2))
        for i in range(len(listToFilter)):
            if signifigantBitCriteria:
                if listToFilter[i][bitAddress] == "1":
                    revisedList.append(listToFilter[i])
            else:
                if listToFilter[i][bitAddress] == "0":
                    revisedList.append(listToFilter[i])
        return revisedList

    returnThisList = getListFromFile("Day3.PZL")
    for u in range(len(returnThisList[0])):
        returnThisList = filterListAtBit( u, returnThisList)
        if len(returnThisList) < 2:
            break
    return returnThisList[0]

def PartTwo():
    oxygenGeneratorValue = str(filterListToSpecificValue(True))
    cO2GeneratorValue = str (filterListToSpecificValue(False))
    o2GeneratorDecimal = binaryToDecimal(oxygenGeneratorValue)
    cO2GeneratorDecimal = binaryToDecimal(cO2GeneratorValue)
    print ("The Oxygen generator Value is : " + oxygenGeneratorValue + " with a decimal value of " + str(o2GeneratorDecimal))
    print ("The CO2 generator Value is : " + cO2GeneratorValue + " with a decimal value of " + str(cO2GeneratorDecimal))
    print ("Multiplied: That comes to :" + str(o2GeneratorDecimal * cO2GeneratorDecimal))


PartOne()
PartTwo()
