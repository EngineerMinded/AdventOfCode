''' Wayne Mack
    Advent Of Code
    Day 2      '''

import numbers

fileName = "Day2.txt"

def parse_number_file(filename):
    result = []
    with open(filename, 'r') as file:
        content = file.read().strip()
        items = content.split(',')
        for item in items:
            if '-' in item:
                start, end = map(int, item.split('-'))
                result.extend(range(start, end + 1))
            else:
                result.append(int(item))
    return result

numbers = parse_number_file(fileName)

def is_symmetric_split(number, onlyTwo):
    num_str = str(number)
    length = len(num_str)

    if onlyTwo:
        if length % 2 != 0:
            return False
        mid = length // 2
        return num_str[:mid] == num_str[mid:]

    else:
        for i in range(1, length // 2 + 1):
            if length % i == 0:
                part = num_str[:i]
                if part * (length // i) == num_str:
                    return True
        return False



part1Total = 0
part2Total = 0

for n in numbers:
    if is_symmetric_split(n, True):
        part1Total += n
    if is_symmetric_split(n, False):
        part2Total += n

print (part1Total)
print (part2Total)