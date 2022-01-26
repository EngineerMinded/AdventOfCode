'''
Wayne Mack
(c)2022 EngineerMinded

Day 14: Extended Polymerization
Written in: Python
'''

Formula = []
Instructions = []
metaData = []
fileName = "Day14.TestCase.Puzzle";
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
print (Formula)
for e in Instructions:
    print (e)


def stepFormulaModifications (numberOfSteps, Formula, Instructions):

    def insertInstruction(Formula, instruction):
        Answer = []
        for i in range(len(Formula) - 1):
            if Formula[i] == instruction[0] and Formula[i + 1] == instruction[1]:
                Answer.append(Formula[i])
                Answer.append(instruction[2])
            else:
                Answer.append(Formula[i])
        Answer.append(Formula[len(Formula) - 1])
        return Answer
    if (numberOfSteps == 0):
        return Formula

    for ins in Instructions:
        Formula = insertInstruction(Formula, ins)
    print (Formula)
    return (stepFormulaModifications(numberOfSteps - 1, Formula, Instructions))

Formula = stepFormulaModifications(10,Formula,Instructions)




