let fs = require('fs');

try {
    var data = fs.readFileSync('../input.dat', 'utf8');
} catch (e) {
    console.log('Error:', e.stack);
}

let instructions = data.split(', ');
let compass = 0;
let directionSteps = [0, 0, 0, 0];
let totalSteps = 0;

for (let instruction of instructions) {
    if (instruction[0] == 'R') {
        compass--;
    } else {
        compass++;
    }
    // keeps the range of compass form -3,-2,-1,0,1,2,3
    // to use them as index for the array directionSteps[]
    compass %= 4;

    // transforms the negative values to positive so it is can be used as a
    // valid index for the array directionSteps[]
    if (compass < 0) {
        compass += 4;
    }
    directionSteps[compass] += parseInt(instruction.slice(1));
}
totalSteps += Math.abs(directionSteps[0] - directionSteps[2]) + Math.abs(directionSteps[1] - directionSteps[3]);

console.log(totalSteps);