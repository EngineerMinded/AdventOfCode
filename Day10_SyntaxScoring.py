'''
Wayne Mack
(c)2021 EngineerMinded

------------------------------------
Day 10 : Syntax Scoring
Written in: Python
------------------------------------
https://adventofcode.com/2021/day/10


'''
fileName = ("Day10.PZL")
#fileName = ("Day10_TestCase.PZL")
File = open(fileName)
fileMetaData = File.read().splitlines()
File.close()
totalSyntaxErrors = 0
syntaxLines = []
for a in range(len(fileMetaData)):
    syntaxLines.append(list(fileMetaData[a]))

def syntaxCheck (lineNumber) :
    chunkBalances = []
    for a in range(len(syntaxLines[lineNumber])):
        if syntaxLines[lineNumber][a] == "(" or syntaxLines[lineNumber][a] == "[" or syntaxLines[lineNumber][a] == "{" or syntaxLines[lineNumber][a] == "<":
            chunkBalances.append(syntaxLines[lineNumber][a])
        elif syntaxLines[lineNumber][a] == ")":
            if chunkBalances.pop() != "(":
                return 3
        elif syntaxLines[lineNumber][a] == "]":
            if chunkBalances.pop() != "[":
                return 57
        elif syntaxLines[lineNumber][a] == "}":
            if chunkBalances.pop() != "{":
                return 1197
        elif syntaxLines[lineNumber][a] == ">":
            if chunkBalances.pop() != "<":
                return 25137
    syntaxLines[lineNumber] = chunkBalances
    return 0

corruptedLines = []
for c in range(len(syntaxLines)):
    if syntaxCheck(c) != 0:
        corruptedLines.append(c)
        totalSyntaxErrors += syntaxCheck(c)
print("The final answer for Part 1 is :" + str(totalSyntaxErrors))
previousNumber = 0
for l in corruptedLines:

    syntaxLines[l] = []
''' Begin procedures for Part 2 '''
totalPoints = 0
def remainingScoreDeterminationByLine (lineNumber):
    totalbyLine = 0
    charactertoFind = "X"
    r = len(syntaxLines[lineNumber]) -1
    while r >= 0:
        if charactertoFind == "X":
            totalbyLine *=5
        g = syntaxLines[lineNumber][r]
        if g == "(" :
            if charactertoFind == "X":
                totalbyLine += 1
            elif charactertoFind =="(":
                charactertoFind = "X"
        elif g == "[":
            if charactertoFind == "X":
                totalbyLine += 2
            elif charactertoFind =="[":
                charactertoFind = "X"
        elif g == "{":
            if charactertoFind == "X":
                totalbyLine += 3
            elif charactertoFind =="{":
                charactertoFind = "X"
        elif g == "<":
            if charactertoFind == "X":
                totalbyLine += 4
            elif charactertoFind =="<":
                charactertoFind = "X"
        elif g == ")":
            charactertoFind = "("
        elif g == "]":
            charactertoFind = "["
        elif g == "}":
            charactertoFind = "{"
        elif g == ">":
            charactertoFind = "<"
        r -= 1
    return totalbyLine
finalList = []
part2Answer = 0
for q in range(len(syntaxLines)):
    localAnswer = remainingScoreDeterminationByLine(q)
    if (localAnswer > 0):
        finalList.append(localAnswer)
''' evaluate final list to find Median '''

def returnFinalAnswer(finalList):
    Answer = 0

    def isThisMedian(numberToEvaluate):
        high = 0
        low = 0
        for j in finalList:
            if j < numberToEvaluate:
                low += 1
            elif j > numberToEvaluate:
                high += 1
        return high == low

    for i in finalList:
        if isThisMedian(i):
            Answer = i
    return Answer
print ("The final answer for Part 2 is :" + str(returnFinalAnswer(finalList)))
