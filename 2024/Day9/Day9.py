''' Wayne Mack  
    Advent Of Code
    Day 9          '''

''' BOTH STARS: BE PAITENT, IT TAKES 25 MINUTES TO GET AN ANSWER '''

def getCheckSumArray (origNumbers):
    returnThis = []
    getNumValue = False
    counter = -1
    for x in origNumbers:
        getNumValue =  not getNumValue
        if getNumValue:
            counter+=1
            for g in range(int(x)):
                returnThis.append(counter)
        else:
            for g in range(int(x)):
                returnThis.append('.');
    return returnThis

def allPartsAreFilled(testThis):
    dotcount = 0
    for x in testThis:
        if x == '.':
            dotcount +=1
    #print ("Dot Count :" + str(dotcount) + " (PAITENCE GRASSHOPPER!!!!!)")
    return dotcount == 0

def fillInAllDots(returnThis):
    while not allPartsAreFilled(returnThis):
        nextPoint = returnThis.pop()
        if nextPoint != '.':
            count = 0;
            while returnThis[count] != ".":
                count +=1
            returnThis[count] = nextPoint
    return returnThis;

def tallyAnswer(charData):
    returnThis = 0
    count = 0
    for i in charData:
        if i != '.': 
           returnThis += count * int(i)
        count+= 1
    return returnThis

def part2Sequence(returnThis):
    
    def findHighestNumber(array):
        returnThis = 0
        for num in array:
            if num != '.':
                if int(num) > int(returnThis):
                    returnThis = num
        return str(returnThis);

    def howManyOfThisNumber(find, array):
        returnThis = 0
        for num in array:
            if find == str(num):
                returnThis+= 1
        print ("The number" + str(find) + " has " + str(returnThis))
        return returnThis

    def fillNumbersWhereYouCan(returnThis, numberToFill, size):
        Repeat = 0
        Accomplished = False
        for i in range(len(returnThis)):
            if Repeat > 0:
                returnThis[i] = str(numberToFill)
                Repeat = Repeat - 1
            else:
                if returnThis[i] == '.' and not Accomplished:
                    Fits = True
                    for j in range(size):
                        if returnThis[i + j] != '.':
                            Fits = False
                    if Fits:
                        returnThis[i] = str(numberToFill)
                        Repeat = size -1
                        Accomplished = True
                elif returnThis[i] == str(numberToFill) and Accomplished:
                        returnThis [i] = "."
                elif returnThis[i] == str(numberToFill) and not Accomplished:
                        return returnThis)
        return returnThis

    highestNumber = findHighestNumber(returnThis)
    for i in range(int(highestNumber), -1, -1):
        returnThis = fillNumbersWhereYouCan(returnThis.copy(),i,howManyOfThisNumber(str(i),returnThis))
    return returnThis

def makeEntireArrayCharArray(oldArray):
    returnThis = []
    for x in oldArray:
        returnThis.append(str(x))
    return returnThis

def read_file_to_char_array(file_name):
    try:
        # Open the file in read mode
        with open(file_name, 'r') as file:
            # Read the content of the file and convert it to a list of characters
            content = file.read()
            char_array = list(content)
            return char_array
    except FileNotFoundError:
        print(f"Error: The file {file_name} was not found.")
        return []
    except IOError:
        print(f"Error: Could not read the file {file_name}.")
        return []

file_name = 'day9.txt'  
char_array = read_file_to_char_array(file_name)


removeThis = char_array.pop()

checkSumData = getCheckSumArray(char_array)



checkSumData = getCheckSumArray(char_array)



charNewArray = makeEntireArrayCharArray(checkSumData)

print (charNewArray)

part2Data = part2Sequence(charNewArray)


print ("Part Two:" + str(tallyAnswer(part2Data)))
