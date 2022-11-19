''' Day 1: Report Repair
    Wayne Mack
    written in: Python
    Advent of Code 2020 '''

print ("Reading Data")

file = open ("Day1.data")
numberList = file.read().splitlines()
file.close()

def partOne(listToCheck):
    for a in listToCheck:
        for b in listToCheck:
            if int (a) + int (b) == 2020:
                return int(a) * int(b)
    print ("number not found")
    return 0

print ("The answer to part one is : " + str(partOne(numberList)))

def partTwo(listToCheck):
    for a in listToCheck:
        for b in listToCheck:
            for c in listToCheck:
                u = int(a)
                v = int(b)
                w = int(c)
                if u + v + w == 2020:
                    return u * v * w
    return 0

print ("The answer to part two is :" + str(partTwo(numberList)))
