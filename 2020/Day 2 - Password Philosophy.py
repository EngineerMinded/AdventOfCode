''' Day 2: Password Philosophy
    Wayne Mack
    Written in Python
    Advent of Code 2020 '''

class PasswordData:
    #This class parses the data and includes functions to
    #determine if it is valid
    def __init__(self, passwordLine):
        self.rawData = passwordLine.split()
        self.range = self.rawData[0].split("-")
        self.keyLetter = self.rawData[1][0]
        self.password = self.rawData[2]

    def passwordHasValidLetterCount(self):
        count = 0
        for l in self.password:
            if l == self.keyLetter:
                count += 1
        return count >= int(self.range[0]) and count <= int(self.range[1])

    def letterPositionsAreValid(self):

        def firstPositionIsValid(self):
            return self.password[int(self.range[0]) - 1] == self.keyLetter

        def secondPositionIsValid(self):
            return self.password[int(self.range[1]) - 1] == self.keyLetter

        return (firstPositionIsValid(self) or secondPositionIsValid(self)) and not (firstPositionIsValid(self) and secondPositionIsValid(self))


file = open ("Day2.data")
passwordList = file.read().splitlines()
file.close()

''' Part One '''
count = 0
for x in passwordList:
    test = PasswordData(x)
    if test.passwordHasValidLetterCount():
        count += 1
print ("The number of valid Passwords for the first  is: " + str(count))

''' Part Two '''
count = 0
for x in passwordList:
    test = PasswordData(x)
    if test.letterPositionsAreValid():
        count += 1

print ("The number of passwords that pass the second criteria is: " + str(count))
