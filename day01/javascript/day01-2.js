let fs = require('fs');

try {
    var data = fs.readFileSync('../input.dat', 'utf8');
} catch (e) {
    console.log('Error:', e.stack);
}

let instructions = data.split(', ');
console.log(getDistance(instructions));

function getDistance(instructions) {

    let factor = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0]
    ];
    let compass = 0;
    let memorizeLocation = [
        [0, 0]
    ];
    let distance = 0;
    let location = [0, 0];

    // for (let i = 0; i < instructions.length; i++) {
    for (let instruction of instructions) {
        if (instruction[0] == 'L') {
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
        let blocks = parseInt(instruction.slice(1));


        for (let i = 0; i < blocks; i++) {
            location[0] += factor[compass][0];
            location[1] += factor[compass][1];
            let currentLocation = location.slice();

            for (let i = 0; i < memorizeLocation.length; i++) {
                if ((memorizeLocation[i][0] == currentLocation[0]) &&
                    (memorizeLocation[i][1] == currentLocation[1])) {
                    distance = Math.abs(currentLocation[0]) + Math.abs(currentLocation[1]);
                    return distance;
                }
            }
            memorizeLocation.push(currentLocation);
        }
    }
    return distance;
}