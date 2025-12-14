# Wayne Mack
# Advent Of Code 2025
# Day 6: 

''' ONLY THE FIRST STAR: SECOND SECTION FUNCTIONALLY SOUND
    BUT NEEDS TO BE DYNAMIC                                   '''

import sys
sys.setrecursionlimit(500)

def read_file_to_2d_array(filename):
    result = []
    with open(filename, 'r', encoding='utf-8') as file:
        for line in file:
            # Split line into words by spaces
            words = line.strip().split()
            # Remove colons from each word
            cleaned_words = [word.replace(":", "") for word in words]
            # Add this line's words as a subarray
            result.append(cleaned_words)
    return result

# Example usage:
sample_data = read_file_to_2d_array("2025Day11Sample.txt")
puzzle_Data = read_file_to_2d_array("2025Day11.txt")

def get_paths(data_input,current_word,target_word, start_loop = ""):
    #print(current_word)
    if (current_word == target_word):
        return 1
    if ((current_word == 'out' and target_word != 'out') or (current_word == start_loop)):
        return 0
    if start_loop == "":
        start_loop = current_word
    returnThis = 0
    for g in data_input:
        if g[0] == current_word:
            for m in g:
                if m != g[0]:
                    returnThis += get_paths(data_input,m,target_word, start_loop)
    return returnThis

def bottom_approach(data_input, first_word, final_word):
    if (final_word == first_word):
        #print ("okay")
        return 1
    returnThis = 0
    for di in data_input:
        # print (di)
        for i in range(len(di) -1, 0, -1):
            if (di[i] == final_word):
                returnThis += bottom_approach(data_input,first_word,di[0])
    #print ('end list ' + first_word)
    return returnThis

    

sample_data_2 = read_file_to_2d_array("2025Day11Sample2.txt")

print("Part 1 sample :" + str(get_paths(sample_data,'you','out')))
print("Part 1 puzzle :" + str(get_paths(puzzle_Data,'you','out')))


def part2Revised (puzzle):
    returnThis = 1
    returnThis *= bottom_approach(puzzle,'svr','fft')
    print ("part 1 of 3: " + str(returnThis))
    returnThis *= bottom_approach(puzzle,'fft','dac')
    print ("Part 2 of 3: " + str(returnThis))
    returnThis *= bottom_approach(puzzle,'dac','out')
    return returnThis

for r in sample_data:
    print (r)
print("Part 2 sample 1 :" + str(get_paths(sample_data_2,'svr','out')))
print("Part 2 sample 2 :" + str(part2Revised(sample_data_2)))
print("Part 2 puzzle   :" + str(part2Revised(puzzle_Data)))
