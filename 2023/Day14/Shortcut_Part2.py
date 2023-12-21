''' Wayne Mack
    Advent Of Code - Day 14
    Written in: Python
'''
# SHORTCUP TO AVOID BRUTE STRENGTH ANSWER

startingNumber = 81817

def getNextNumber (previousValue):
    if previousValue == 96345:
        return 96340
    if previousValue == 96340:
        return 96317
    if previousValue == 96317:
        return 96293
    if previousValue == 96293:
        return 96297
    if previousValue == 96297:
        return 96314
    if previousValue == 96314:
        return 96325
    if previousValue == 96325:
        return 96333
    if previousValue == 96333:
        return 96344
    else:
        return 96345

destinationNumber = 1000000000
multiplier =         999900000

startHere = startingNumber + multiplier
while (destinationNumber > startHere):
    startHere = startHere + 9
    print ("follow : " + str(startHere))
startHere = startHere - 9
answer = 0
while (startHere < 1000000000):
    answer = getNextNumber(answer)
    startHere += 1
print ("answer: " + str(answer))
    

