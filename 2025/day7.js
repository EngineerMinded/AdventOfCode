/*
   Wayne Mack
   Advent Of Code
   Day 7
   RUNS WITH NODE.js
*/

const fs = require('fs');

function createCharArray(filename) {
  // Read file contents
  const data = fs.readFileSync(filename, 'utf8');

  // Split into lines and then into characters
  const charArray = data
    .split('\n')                // break into rows
    .map(line => line.split('')); // split each row into characters

  return charArray;
}

// Example usage:
const arr = createCharArray('2025Day7.txt');

function part1(data) {
    let returnThis = 0
    let COLUMNS = data.length;
    let ROWS = data[0].length;
    for (let x = 0; x < COLUMNS; x++) {
        for (let y = 0; y < ROWS; y++) {
            if (data[x][y] == '.') {
                if (x > 0 ) { if (data[x - 1][y] == 'S' || data[x - 1][y] == '|') { data[x][y] = '|' }}
            }
            if (data[x][y] == '^') {
                if (x > 0 ) {
                    if (data[x - 1][y] == '|' || data[x - 1][y] == 'S') {
                        returnThis++;
                        if (y > 0) { data[x][y - 1] = '|';}
                        if (y < data[0].length - 1) { data[x][y + 1] = '|';  }
                    }
                }
            }
        }
    }
    //data.forEach((line) => {console.log(line);})
    return returnThis
}

function part2Revised (data){
    /******************************************
     * Ah Ha, Bottom up approach works better *
     ******************************************/
    let COLUMNS = data.length - 1;
    let ROWS    = data[0].length - 1;
    // Generate a numeric grid to hold number of paths
    let numberGrid =[];
    for (let a = 0; a < data.length; a++) {
        let newLine = [];
        for (let b = 0; b < data[0].length; b++) {
            newLine.push(0);
        }
        numberGrid.push(newLine);
    }
    
    function checkPath(numberGrid,data,column,row) {
        if (data[column][row] == '|' || data[column][row] == 'S') {
            if (column < COLUMNS) numberGrid[column][row] = numberGrid[column + 1][row];
            else numberGrid[column][row] = 1;
        }
    }
    function checkFork(numberGrid,data,column,row) { 
          if (data[column][row] == '^') numberGrid[column][row] = numberGrid[column+ 1][row - 1]  + numberGrid[column + 1][row + 1];
    }
    for (let x = COLUMNS; x > -1; x--) {
        for (let y = ROWS; y >= 0; y--) {
            checkPath(numberGrid,data,x,y);
            checkFork(numberGrid,data,x,y);
        }
    }
    returnThis = 0;
    for (let z = 0; z < ROWS; z++) {
        if (returnThis < numberGrid[0][z]) returnThis = numberGrid[0][z];
    }
    return returnThis;
}
console.log("Part One: ", part1(arr));
console.log("Part Two: ", part2Revised(arr));
