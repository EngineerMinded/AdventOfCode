'''
Wayne Mack
(c)2021 EngineerMinnded


Program: Depth Difference indicator
Written in: Python
------------------------------------------
NOTE: This is an activity for:
Advent of Code
https://adventofcode.com/2021/day/1
------------------------------------------

ACHIEVEMENT: ONE GOLD STAR (DAY ONE)
The answer was 1154

ACHIEVMENT: SECOND GOLD STAR FOR PART TWO

First working python program: Keep going!

'''
''' GLOBAL VARIABLES '''
currentValue = -1 #when the initial value is -1, it indicates the first value
previousValue = 0
numberOfDecreases = 0
numberOfIncreases = 0
# for Part Two: we shall make this a global variable
infoArray = 0
''' BEGIN PART ONE '''
def PARTONE():
    def Main():
        print ("Reading and Tallying the data.")
        global infoArray
        infoArray = readFile("Day1.PZL")
        tallyAllIncreasesAndDecreases(infoArray)
        # Let's read the contents of the file
    def readFile(fileName):
        file = open (fileName)
        listing = file.read().splitlines()
        file.close()
        # the array is built, let's return it
        return listing
        # END readFlie
    def valueIncreased (previous, current): # RETURNS boolean
        if (int (current) > int (previous)):
            return True
        else:
            return False
    # END valueIncreased
    def tallyAllIncreasesAndDecreases (arrayInput): # changes GLOBAL VALUES
        global numberOfIncreases
        global numberOfDecreases
        global currentValue
        global previousValue
        for i in range(len(arrayInput)):
            previousValue = currentValue
            currentValue = arrayInput[i]
            if (previousValue != -1):
                if (valueIncreased(previousValue,currentValue)):
                    numberOfIncreases = numberOfIncreases + 1
                else:
                    numberOfDecreases = numberOfDecreases + 1
        # END tallyAllIncreasesAndDecreases
    def displayResults(increases, decreases): #Voided function
        print ("\nThe number of individual increases are : " + str(increases))
        '''
        print ("the number of decreases are : " + str(decreases) + "\n")
        if (increases > decreases):
            print ("There are " + str (increases - decreases) + " increases than decreases!")
        else :
            print ("There are " + str (decreases - increases) + " decreases than increases!")
        '''
    Main()
    displayResults(numberOfIncreases,numberOfDecreases)
''' BEGIN PART TWO, END PART ONE '''
def PARTTWO():
    def Main():
        previousSum = 0
        currentSum =  -1
        global numberOfIncreases
        numberOfIncreases = 0
        for i in range (len(infoArray) - 2):
            previousSum = currentSum
            currentSum = str(int(infoArray[i]) + int(infoArray [i + 1]) + int(infoArray [i + 2]))
            if (previousSum != -1):
                if (int(currentSum) > int(previousSum)):
                    numberOfIncreases +=1
        print ("\nThe number of Sum Increases are: " + str(numberOfIncreases))
    Main()
    # END PART TWO
''' Functional Calls '''
PARTONE()
PARTTWO()
