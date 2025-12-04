''' Wayne Mack
    Advent Of Code
    Day 3'''

fileName = "Day3.txt"

def read_2d_digit_array(filename):
    array_2d = []
    with open(filename, 'r') as file:
        for line in file:
            line = line.strip()
            if line:
                # Remove common delimiters and split into characters
                clean_line = line.replace(',', '').replace(' ', '').replace('\t', '')
                row = [int(char) for char in clean_line if char.isdigit()]
                array_2d.append(row)
    return array_2d

numbers = read_2d_digit_array(fileName)

#print (numbers)
part1total = 0

for n in numbers:
    highinrow = 0
    for u in range(len(n)):
        for v in range (len(n)):
            generatedNumber = (n[u] * 10) + n[v]
            if generatedNumber > highinrow and u != v and u < v:
                highinrow = generatedNumber
    part1total += highinrow

print (part1total)

def read_number_array_from_file(filename):
    number_array = []
    with open(filename, 'r') as file:
        for line in file:
            # Clean and split line by common delimiters
            line = line.strip()
            if line:
                parts = line.replace(',', ' ').replace('\t', ' ').split()
                number_array.extend([int(num) for num in parts])
    return number_array

    
def max_12_digit_number(digits):
    stack = []
    digits_needed = 12
    total_digits = len(digits)

    for i, digit in enumerate(digits):
        # While we can remove from stack to make room for bigger digits ahead
        while (stack and
               digit > stack[-1] and
               len(stack) + (total_digits - i - 1) >= digits_needed):
            stack.pop()
        if len(stack) < digits_needed:
            stack.append(digit)

    return ''.join(stack)

part2total = 0
    
p2numbers = read_number_array_from_file(fileName)

for p in p2numbers:
    part2total += (int(max_12_digit_number(list(str(p)))))
    
print (part2total)

