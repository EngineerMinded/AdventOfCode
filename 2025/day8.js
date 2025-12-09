/*
  Wayne Mack
  Advent Of Code
  Day 8
*/

const fs = require('fs');

function readXYZFile(filename) {
  try {
    // Read the file contents as text
    const data = fs.readFileSync(filename, 'utf8');

    // Split into lines, filter out empty ones
    const lines = data.split(/\r?\n/).filter(line => line.trim() !== '');

    // Map each line into an object {x, y, z}
    const result = lines.map(line => {
      const [x, y, z] = line.trim().split(',').map(Number);
      return { x, y, z };
    });

    return result;
  } catch (err) {
    console.error(`Error reading file ${filename}:`, err);
    return [];
  }
}

function euclideanDistance (x1,y1,z1,x2,y2,z2) {
  return (((x1 - x2)**2) + ((y1 - y2)**2) + ((z1- z2)**2) ) ** .5;
}

function numberOfShortestCircuits(numberOfCircuits, inputData) {
    returnThisCircuit=[];
    let previousNumber = 0;
    for ( let count = 0;  count< numberOfCircuits; count++) {
        let currentNumber = 9999999999999999999999999999999;
        let curpoint1 = [];
        let curpoint2 = [];
        inputData.forEach((point1) => {
            inputData.forEach((point2) => {
                if (point1 != point2) {
                    currentEuc = euclideanDistance(point1.x,point1.y,point1.z,point2.x,point2.y,point2.z);
                    if ((currentEuc < currentNumber) && (currentEuc != 0) && (currentEuc > previousNumber)) {
                        currentNumber = currentEuc;
                        curpoint1 = point1;
                        curpoint2 = point2;
                    }
                }
            });
        });
        previousNumber = currentNumber;
        returnThisCircuit = addToCircuit(curpoint1,curpoint2,returnThisCircuit);
    }
    return returnThisCircuit;
}

function dataPart2( inputData) {
    returnThisCircuit=[];
    let previousNumber = 0;
    let curpoint1 = [];
    let curpoint2 = [];
    do {
        let currentNumber = 9999999999999999999999999999999;
        curpoint1 = [];
        curpoint2 = [];
        inputData.forEach((point1) => {
            inputData.forEach((point2) => {
                if (point1 != point2) {
                    currentEuc = euclideanDistance(point1.x,point1.y,point1.z,point2.x,point2.y,point2.z);
                    if ((currentEuc < currentNumber) && (currentEuc != 0) && (currentEuc > previousNumber)) {
                        currentNumber = currentEuc;
                        curpoint1 = point1;
                        curpoint2 = point2;
                    }
                }
            });
        });
        previousNumber = currentNumber;
        returnThisCircuit = addToCircuit(curpoint1,curpoint2,returnThisCircuit);
        console.log ((returnThisCircuit[0].length / inputData.length) *100, " % to the Answer");
        
    } while (returnThisCircuit[0].length < inputData.length);
    return curpoint1.x * curpoint2.x;
}

function mergeArraysWithCommonValues(twoDArray) {
  let merged = [...twoDArray]; // copy input

  let changed = true;
  while (changed) {
    changed = false;

    for (let i = 0; i < merged.length; i++) {
      for (let j = i + 1; j < merged.length; j++) {
        // Check if arrays i and j share any common value
        const hasCommon = merged[i].some(val => merged[j].includes(val));

        if (hasCommon) {
          // Merge arrays and remove duplicates
          const combined = Array.from(new Set([...merged[i], ...merged[j]]));

          // Replace i with merged, remove j
          merged[i] = combined;
          merged.splice(j, 1);

          changed = true;
          break; // restart inner loop since merged changed
        }
      }
      if (changed) break; // restart outer loop
    }
  }

  return merged;
}

function addToCircuit(circuit1,circuit2,circuitData) {
    circuitData = mergeArraysWithCommonValues(circuitData);
    circuitData.forEach((circuits) => {
        circuits.forEach((numberSet) => {
            if (numberSet == circuit1 ) {
                circuits.push(circuit2);
                return;
            }
            if (numberSet == circuit1) {
                circuits.push(circuit1);
                return;
            }
        });
    });
    let newCircuit = [];
    newCircuit.push(circuit1);
    newCircuit.push(circuit2);
    circuitData.push(newCircuit);
    circuitData = mergeArraysWithCommonValues(circuitData);
    return circuitData;
}

let fileName = ('2025Day8.txt');
const xyzArray = readXYZFile(fileName);
console.log("WAIT :");
let answerPart1 = 1;
let countTheseNumbers = 3;
let numberOfPasses = 1000;
let dataPart1 = numberOfShortestCircuits(numberOfPasses,xyzArray);
let circuitCounts = [];
dataPart1.forEach((line) => {
    circuitCounts.push(line.length);
});
circuitCounts.sort((a, b) => b - a);

for (let u = 0; u < countTheseNumbers; u++) {
    answerPart1 *= circuitCounts[u];
}
let Part2 = dataPart2(xyzArray);
console.log("Part 1 :", answerPart1);
console.log("Part 2:" ,Part2);
