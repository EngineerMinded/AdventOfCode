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
fileName = ("Day10_TestCase.PZL")

File = open(fileName)
fileMetaData = File.read().splitlines()
File.close()
totalSyntaxErrors = 0
syntaxLines = []
for a in range(len(fileMetaData)):
    syntaxLines.append(list(fileMetaData[a]))
'''
 chunk Balance properties:
 0 = "(" - 3 points
 1 = "[" - 57 points
 2 = "{" - 1197 points
 3 = "<" - 25137 points
 '''
for g in range (len(syntaxLines)):
    print (syntaxLines[g])

def syntaxCheck (lineNumber) :
    print ("Line Number" + str(lineNumber))
    chunkBalances = []
    print (chunkBalances)
    for a in range(len(syntaxLines[lineNumber])):
        print (str(chunkBalances) + " : " + syntaxLines[lineNumber][a])
        if syntaxLines[lineNumber][a] == "(" or syntaxLines[lineNumber][a] == "[" or syntaxLines[lineNumber][a] == "{" or syntaxLines[lineNumber][a] == "<":
            chunkBalances.append(syntaxLines[lineNumber][a])
        elif syntaxLines[lineNumber][a] == ")":
            if chunkBalances.pop() != "(":
                print ("Corrupted")
                return 3
        elif syntaxLines[lineNumber][a] == "]":
            if chunkBalances.pop() != "[":
                print ("Corrupted")
                return 57
        elif syntaxLines[lineNumber][a] == "}":
            if chunkBalances.pop() != "{":
                print ("Currupted")
                return 1197
        elif syntaxLines[lineNumber][a] == ">":
            if chunkBalances.pop() != "<":
                print ("Corrupted")
                return 25137
    print ("Not corrupted")
    syntaxLines[lineNumber] = chunkBalances
    return 0

corruptedLines = []
for c in range(len(syntaxLines)):
    if syntaxCheck(c) != 0:
        corruptedLines.append(c)
        totalSyntaxErrors += syntaxCheck(c)
print("The syntax error total is :" + str(totalSyntaxErrors))
print("The corrupted Lines are: " + str(corruptedLines))
previousNumber = 0
for l in corruptedLines:

    syntaxLines.pop(l - previousNumber)
    previousNumber = l
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
        print (totalbyLine)
        r -= 1
    print ("Final " + str(totalbyLine))
    return totalbyLine

part2Answer = 0
for q in range(len(syntaxLines)):
    part2Answer +=remainingScoreDeterminationByLine(q)
