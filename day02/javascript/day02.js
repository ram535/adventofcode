let fs = require('fs');

try {
    var data = fs.readFileSync('../input.dat', 'utf8');
} catch (e) {
    console.log('Error:', e.stack);
}

let lines = data.split('\n');

let rowCoordinate = 1;
let columnCoordinate = 1;
let board = ["     ", " 123 ", " 456 ", " 789 ", "     "];


for (var i = 0; i < (lines.length - 1); i++) {
    for (var j = 0; j < lines[i].length; j++) {
        // console.log(lines[i][j]);
        let direction = lines[i][j];
        let dr = 0;
        let dc = 0;
        switch (direction) {
            case 'U':
                dr = -1;
                break;
            case 'D':
                dr = 1;
                break;
            case 'L':
                dc = -1;
                break;
            case 'R':
                dc = 1;
                break;
        }
        if (board[rowCoordinate + dr][columnCoordinate + dc] !== ' ') {
            rowCoordinate = rowCoordinate + dr;
            columnCoordinate = columnCoordinate + dc;
        }
    }
    console.log(board[rowCoordinate][columnCoordinate]);
}