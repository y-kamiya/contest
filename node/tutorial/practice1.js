function Main(input) {
    input = input.split('\n');
    var bc = input[1].split(' ');
    var a = parseInt(input[0]);
    var b = parseInt(bc[0]);
    var c = parseInt(bc[1]);
    console.log('%d %s',a+b+c, input[2]);
}

Main(require("fs").readFileSync("data", "utf8"));
