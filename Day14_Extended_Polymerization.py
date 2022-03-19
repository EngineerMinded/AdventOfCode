'''
Wayne Mack
(c)2022 EngineerMinded

Day 14: Extended Polymerization
Written in: Python
'''

Formula = []
Instructions = []
metaData = []
fileName = "Day14.TestCase.Puzzle"
File = open(fileName)
metaData = File.read().splitlines()
File.close()

def parseMetaData (metaData):
    global Formula
    global Instructions
    for characters in metaData[0]:
        Formula.append(characters)
    for line in range(2, len(metaData)):
        forLoopData = metaData[line].split("-> ")
        pair = (list(forLoopData[0]))
        segment = []
        segment.append(pair[0])
        segment.append(pair[1])
        segment.append(forLoopData[1])
        Instructions.append(segment)

parseMetaData(metaData)

def stepFormulaModifications (numberOfSteps, Formula, Instructions):

    def printAsString (Formula):
        printMe = ""
        for g in Formula:
            printMe += g
        print (printMe)
    printAsString(Formula)
    def insertInstruction(Formula, instructions):
        Answer = []
        for i in range(len(Formula) - 1):
            Answer.append(Formula[i])
            for ins in instructions:
                if Formula[i] == ins[0] and Formula[i + 1] == ins[1]:
                    Answer.append(ins[2])
        Answer.append(Formula[len(Formula) - 1])
        return Answer
    Answer = Formula
    for i in range(numberOfSteps):
        Answer = insertInstruction(Answer, Instructions)
        printAsString(Answer)
    return Answer

Answer = stepFormulaModifications(10,Formula, Instructions)

def tallyVariables (completedFormula):
    valueList =[]

    def addVariable (letterValue):
            for value in valueList:
                if value[0] == letterValue:
                    value[1] += 1
                    return
            LV = []
            LV.append (letterValue)
            LV.append (1)
            valueList.append(LV)

    for cF in completedFormula:
        addVariable(cF)
    print (valueList)
    return valueList

def partAnswer (valueList):
    biggestNumber = 0
    smallestNumber = 99999999999999
    for v in valueList:
        if v[1] > biggestNumber:
            biggestNumber = v[1]
        if v[1] < smallestNumber:
            smallestNumber = v[1]
    print ("The Biggest and smallest Range is : "+ str(biggestNumber) +" - " + str(smallestNumber) )
    print ("Subtracted, that equals : " + str( biggestNumber - smallestNumber) )

partAnswer(tallyVariables(Answer))

Part2Answer = stepFormulaModifications(40,Formula, Instructions)
partAnswer (tallyVariables(Part2Answer))

tmp_poly = Counter(a+b for a,b in zip(polymer, polymer[1:]))
print(tmp_poly)
chars = Counter(polymer)
