''' Day 6: Custom Customs
    Wayne Mack
    Written in: Python
    Advent of Code 2020    '''

class Questionaire:

    def __init__ (self, dataInput):
        self.count = 0
        self.answerList = []

        def characterExists(characterToTest):
            if len(self.answerList) == 0:
                return False
            for nextCharacter in self.answerList:
                if characterToTest == nextCharacter:
                    return True
            return False

        for nextChar in dataInput:
            if not characterExists(nextChar):
                self.answerList.append(nextChar)
                self.count += 1

listOfQuestionaires = []

def parseData (dataToParse):
    cumulativeData = []
    for i in dataToParse():
        if i == "":
            listOfQuestionaires.append(Questionaire(cumulativeData))
            cumulativeData = []
        else:
            cumulativeData += i
    if cumulativeData != "":
        listOfQuestionaires.append(Questionaire(cumulativeData))

file = open("Day6.data")
parseData(file.read().splitlines)
file.close

''' Part One '''
yesCount = 0
for x in listOfQuestionaires:
    #print (str (x.answerList) + " " + str (x.count))
    yesCount += x.count

print ("The sum of the first counts are : " + str(yesCount))

'''Part Two '''
