'''
Wayne Mack
(c)2021 EngineerMinded


Program: Haywire Digit Displays
Written in: Python
------------------------------------------
NOTE: This is an activity for:
Advent of Code
https://adventofcode.com/2021/day/8
Day 8: Part 2
------------------------------------------

'''
def calc_digits(dig_output):
    req_dig_len = [2, 4, 3, 7]
    qty = 0
    for item in dig_output:
        if len(item) in req_dig_len:
            qty += 1
    return qty


def clean_input(dig_input, digits):
    '''Just clean already found digits
    '''
    for key in digits:
        if dig_input.count(digits[key]) > 0:
            dig_input.pop(dig_input.index(digits[key]))


def analyze_digit(dig_input):
    # length for digits
    digs_length = {
        2: 1,
        5: [2, 3, 5],
        4: 4,
        6: [6, 9, 0],
        3: 7,
        7: 8
    }

    '''
     #1#
    #   #
    2   3
    #   #
     #4#
    #   #
    5   6
    #   #
     #7#
    '''
    wires = {
        1: '',
        2: '',
        3: '',
        4: '',
        5: '',
        6: '',
        7: ''
    }
    digits = {}
    digits_s = {}

    # find 1, 4, 7, 8
    for item in dig_input:
        if type(digs_length[len(item)]) == int:
            digits[digs_length[len(item)]] = item
            digits_s[item] = digs_length[len(item)]
    clean_input(dig_input, digits)

    # find 6, 3
    for item in dig_input:
        if len(item) == 6:
            if len(set(digits[1]) - set(item)) == 1:
                digits[6] = item
                digits_s[item] = 6
                wires[3] = set(digits[1]) - set(item)
                wires[6] = set(digits[1]) - wires[3]
        elif len(item) == 5:
            if len(set(item) - set(digits[7])) == 2:
                digits[3] = item
                digits_s[item] = 3
    clean_input(dig_input, digits)

    # find 9, 0
    for item in dig_input:
        if len(item) == 6:
            if len(set(digits[8]) - set(digits[3]) - set(item)) == 1:
                digits[9] = item
                digits_s[item] = 9
                wires[5] = set(digits[8]) - set(digits[3]) - set(item)
                wires[2] = set(digits[9]) - set(digits[3])
                wires[4] = set(digits[4]) - set(digits[7]) - wires[2]
                wires[7] = set(digits[3]) - set(digits[7]) - wires[4]
            elif len(set(digits[8]) - set(digits[3]) - set(item)) == 0:
                digits[0] = item
                digits_s[item] = 0
    clean_input(dig_input, digits)

    # find 5, 2
    for item in dig_input:
        if len(set(digits[9]) - wires[3] - set(item)) == 0:
            digits[5] = item
            digits_s[item] = 5
        else:
            digits[2] = item
            digits_s[item] = 2
    clean_input(dig_input, digits)
    wires[1] = set(digits[7]) - set(digits[1])

    return digits_s


def calc_outputs(digits_s, dig_output):
    number = 0
    for item in dig_output:
        for digit in digits_s:
            if set(item) == set(digit):
                number = number * 10 + digits_s[digit]
    return int(number)


def main():
    qty = 0
    sum_output = 0
    with open("Day8.PZL") as f:
        for line in f:
            dig_input, dig_output = line.replace('\n', '').split(' | ')
            qty += calc_digits(dig_output.split())
            digits_s = analyze_digit(dig_input.split())
            sum_output += calc_outputs(digits_s, dig_output.split())
    print(qty)
    print(sum_output)


if __name__ == "__main__":
    main()
