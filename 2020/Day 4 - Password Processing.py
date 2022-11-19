''' Day 4: Passport Processing
    Wayne Mack
    Written in: Python
    Advent of Code 2020 '''

class ListFields:
    def __init__ (self, inputData):
        self.byr = "" #birth year
        self.iyr = "" #issue year
        self.eyr = "" #expiration year
        self.hgt = "" #height
        self.hcl = "" #hair color
        self.ecl = "" #eye color
        self.pid = "" #passport id
        self.cid = "" #country id
        parsedData = inputData.split()
        for p in parsedData:
            q = p.split(":")
            if q[0] == "byr":
                self.byr = q[1]
            elif q[0] == "iyr":
                self.iyr = q[1]
            elif q[0] == "eyr":
                self.eyr = q[1]
            elif q[0] == "hgt":
                self.hgt = q[1]
            elif q[0] == "hcl":
                self.hcl = q[1]
            elif q[0] == "ecl":
                self.ecl = q[1]
            elif q[0] == "pid":
                self.pid = q[1]
            elif q[0] == "cid":
                self.cid = q[1]
            else:
                print ("unusable data :" + q[0] +" - " + q[1])

    def passportIsValidPartOne (self):
        return not (self.ecl == "" or self.byr == "" or self.iyr == "" or self.eyr == "" or self.hgt == "" or self.hcl == "" or self.pid == "")

    def passportIsValidPartTwo(self):
        # Check birth Year
        if  self.byr == "" or int(self.byr) < 1920 or int(self.byr) > 2002:
            return False
        # Check issue year
        elif self.iyr == "" or int(self.iyr) < 2010 or int(self.iyr) > 2020:
            return False
        # Check expire year
        if self.eyr == "" or int(self.eyr) < 2020 or int(self.eyr) > 2030:
            return False
        # Height criteria
        if self.hgt == "":
            return False
        height = 0
        completeHeight = False
        for n in self.hgt:
            if n == "i":
                if height < 59 or height > 76:
                    return False
            elif n == "c":
                if height < 150 or height > 193:
                    return False
            elif n == "m" or n == "n":
                completeHeight = True
            else:
                height = (height * 10) + int(n)
        if not completeHeight:
            return False
        # Check hair color
        if self.hcl == "" or self.hcl[0] != "#" or len(self.hcl) != 7:
            return False
        #Check eye color
        if not (self.ecl == "amb" or self.ecl == "blu" or self.ecl == "brn" or self.ecl == "gry" or self.ecl == "grn" or self.ecl == "hzl" or self.ecl == "oth"):
            return False
        #Check Passport ID
        try:
            id = int(self.pid)
        except ValueError:
            return False
        if len(self.pid) != 9:
            return False
        return True

    def printLineOfData(self):
        print ("ecl: " + self.ecl +"byr: " + self.byr + " iyr: " + self.iyr + " eyr: " + self.eyr + " hgt: " + self.hgt + " hcl: " + self.hcl + " pid : " + self.pid + " cid: " + self.cid)
    # END ListFields Class
class PassportInfo:
    def __init__ (self, listData):
        self.dataList = []
        self.listData = listData
        dataBlock = "" #temporary holding space for data
        for dList in listData:
            if dList == "" and dataBlock != "" : #detect blank line and avoid missed dataList
                self.dataList.append(ListFields(dataBlock))
                dataBlock = "" #clear data Block for next use
            else:
                dataBlock = dataBlock + " " + dList
        if dataBlock != "":
            self.dataList.append(ListFields(dataBlock))

    def printAllData(self):
        for lineToPrint in self.dataList:
            lineToPrint.printLineOfData()
# END PassportInfo Class

file = open ("Day4.data")
passportData = PassportInfo(file.read().splitlines())
file.close()
#passportData.printAllData()

''' Part One and Part Two '''
validEntryCount = 0
validrequirements = 0
for line in passportData.dataList:
    if line.passportIsValidPartOne():
        validEntryCount += 1
    if line.passportIsValidPartTwo():
        validrequirements += 1
print ("The number of valid entries for part one is: " + str(validEntryCount))
print ("The number of satisfied conditions for part two is " + str(validrequirements))
