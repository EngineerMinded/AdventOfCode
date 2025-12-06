// Wayne Mack
// Advent Of Code
// Day 6

/* NOTE: Run this using Node.js */
let fileName = "2025Day6.txt";


const fs = require('fs');

// Read the file contents (assuming UTF-8 encoding)
const data = fs.readFileSync(fileName, 'utf8');

// Split into rows
const rows = data.trim().split('\n');

// Create an array to hold all row arrays
const arrays = rows.map((row, index) => {
  const tokens = row.trim().split(/\s+/);

  // Try to parse as numbers if all tokens look numeric
  const allNumeric = tokens.every(token => !isNaN(token));

  if (allNumeric) {
    return tokens;
  } else {
    return tokens; // keep as strings
  }
});

const data2 = fs.readFileSync(fileName, 'utf8');

const lines = data2.split('\n');

let charArray = lines.map(line => line.split(''));

function transpose(array) {
    const rows = array.length;
    const cols = array[0].length;
    let transposed = [];

    for (let c = 0; c < cols; c++) {
        transposed[c] = [];
        for (let r = 0; r < rows; r++) {
            transposed[c][r] = array[r][c];
        }
    }
    return transposed;
}

function computeSegment(data){
    
    let size = data.length;
    let returnThis = 0;
    if (data[size - 1] == '+') {
        for (let i = 0; i < size - 1; i++) {
            returnThis += parseInt(data[i],10);
        }
    }
    else if (data[size - 1] == '*') {
        returnThis = 1;
        for (let i = 0; i < size - 1; i++) {
            returnThis *= parseInt(data[i],10);
        }
    }
    return returnThis;
}

function solve(data){
    let total = 0;
    numOfRows = data.length;
    numOfColumns = data[0].length;
    for (let i = 0; i < numOfColumns; i++) {
        let problem = []
        for (let j = 0; j < numOfRows; j++) {
            //console.log(data[j][i]);
            problem.push(data[j][i]);
        }

        total += computeSegment(problem);
    }
    return total;
}


function computePart2(data) {
    let lastItem = data.pop();
    console.log(data);
    data.push(lastItem);
    return data;
}

let transposedArray = transpose(charArray);



console.log ("Part One: ",solve(arrays));

// part two
let total2 = 0;
let subtotal2 = 0;

function allSpaces(charArray) {
    // Check if every element is exactly a space
    return charArray.every(ch => ch === ' ');
}

let sign = '+';
transposedArray.forEach((line) => {
    let newNum = 0;
    line.forEach((character) => {
        if (!isNaN(character) && character.trim() !== '') {
          newNum = (newNum * 10) + Number(character);
        }
        if (character == '+') {
          sign = '+';
        }
        if (character == '*') {
          sign = '*';
        }

    });
    if (sign == '*' && newNum != 0) {
      if (subtotal2 == 0) {subtotal2 = 1;}
      subtotal2 *= newNum;
    }
    if (sign == '+') {
      subtotal2 += newNum;
    }
    if (allSpaces(line)) {
      total2 += subtotal2;
      subtotal2 = 0;
    }
});
total2 += subtotal2;
subtotal2 = 0;

console.log("Part Two: " + total2);