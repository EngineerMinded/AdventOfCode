'''
Wayne Mack
Advent Of Code
Day 4

'''

def read_file(filename):
    """Reads file and separates ranges and single numbers."""
    ranges = []
    singles = []
    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            if '-' in line:
                # It's a range like "31-34"
                parts = line.split('-')
                start, end = int(parts[0]), int(parts[1])
                ranges.append((start, end))
            else:
                # It's a single number
                singles.append(int(line))
    return ranges, singles


def count_matches(ranges, singles):
    """Counts how many single numbers fall into any range."""
    count = 0
    for num in singles:
        for start, end in ranges:
            if start <= num <= end:
                count += 1
                break  # stop after first matching range
    return count

def merge_ranges_and_counts(ranges):

    if not ranges:
        return []
    
    # Sort ranges by start
    ranges = sorted(ranges, key=lambda x: x[0])
    
    merged = []
    current_start, current_end = ranges[0]
    
    for start, end in ranges[1:]:
        if start <= current_end + 1:  # overlap or adjacency
            current_end = max(current_end, end)
        else:
            merged.append((current_start, current_end))
            current_start, current_end = start, end
    
    # Add the last range
    merged.append((current_start, current_end))
    
    # Compute counts
    counts = [(end - start + 1) for start, end in merged]
    return_this = 0
    for total_counts in counts:
        return_this += total_counts 
    return return_this

def main():
    filename = "2025Day5.txt"  # replace with your file name
    ranges, singles = read_file(filename)

    print("Ranges:", ranges)
    print("Singles:", singles)

    matches = count_matches(ranges, singles)
    print("Number of single numbers that fall into ranges:", matches)
    print("Number of Ingredients:" , merge_ranges_and_counts(ranges))

if __name__ == "__main__":
    main()