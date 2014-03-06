var start = Date.now();
var scores = {
    'A': 4,
    'B': 3,
    'C': 2,
    'D': 1,
    'F': 0,
};

function Main(input) {
    input = input.split('\n');
    var total = 0;
    for (var i = 0; i < input[0]; i++) {
        total += scores[input[1].charAt(i)];
    } 
    console.log(total / input[0]);
}   
 
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
var end = Date.now();
console.log(end - start);


