let fs = require('fs');

try {
    var data = fs.readFileSync('../input.txt', 'utf8');
} catch (e) {
    console.log('Error:', e.stack);
}

let sides = [];
let dimension = data.trim().split('\n');
for (let i = 0; i < dimension.length; i++) {
    dimension[i].trim();
    let temp = dimension[i].replace(/(^\s+|\s+$)/g, '');

    sides.push(temp.replace(/\s+/g, ',').split(','));
}

let total = 0;
for (let side of sides) {
    // sides of the triangle
    let a = parseInt(side[0]);
    let b = parseInt(side[1]);
    let c = parseInt(side[2]);

    if (a + b > c && a + c > b && b + c > a) {
        total++;
    }
}
console.log(total);