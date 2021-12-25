
fileName = ("Day8_TestCase.PZL")
fileName = ("Day8.PZL")

def readInformationFromFile (fileName):
    ''' Read Data from the file and, return as list to be evaluated '''
    File = open (fileName)
    returnThisList = File.read().splitlines()
    File.close()
    return returnThisList
inputs = readInformationFromFile(fileName)

ans = sum(
  len(chars) in (2, 3, 4, 7)
  for line in inputs
  for chars in line.split('|')[1].strip().split()
)
print(f'Times do digits 1, 4, 7, or 8 appear: {ans}')

code = []
mapping = {2: 1, 3: 7, 4: 4, 7: 8}
for input in inputs:
    temp = {}
    for word in input:
        if len(word) in mapping:
            temp[mapping[len(word)]] = word

    # Find 6
    for word in input:
        if len(word) == 6 and any(char not in word for char in temp[1]):
            temp[6] = word
            break
# Find 0
    for word in input:
        if len(word) == 6 and any(char not in word for char in temp[4]) and word not in temp.values():
            temp[0] = word
            break

    # Find 9 after 6 and 0 with length 6
    for word in input:
        if len(word) == 6 and word not in temp.values():
            temp[9] = word
            break
# Find 5
    for word in input:
        if len(word) == 5 and all(char in temp[6] for char in word):
            temp[5] = word
            break

    # Find 3
    for word in input:
        if len(word) == 5 and all(char in temp[9] for char in word) and word not in temp.values():
            temp[3] = word
            break

    # Find 2 after 3 and 5 with length 5
    for word in input:
        if len(word) == 5 and word not in temp.values():
            temp[2] = word

    # Transform key-value to value-key
    code.append({v: k for k, v in temp.items()})
total = 0
for i, output in enumerate(outputs):
    total += int(''.join(map(str, [code[i][word] for word in output])))
print(f'Sum of the output values is {total}')
