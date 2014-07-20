function Main(input) {
    input = input.split('\n');
    var str = input[1];
    var point = {
        "1": 0,
        "2": 0,
        "3": 0,
        "4": 0,
    };
    for (var i = 0; i < input[0]; i++) {
        point[str[i]]++;
    }

    var max = 0, min = parseInt(input[0]);
    for (var i = 0; i < 4; i++) {
        max = Math.max(point[str[i]], max);
        min = Math.min(point[str[i]], min);
    }
    console.log(max, min);
}


// ※この行以降は編集しない (標準入力から一度に読み込みMainを呼び出します)
Main(require("fs").readFileSync("/dev/stdin", "utf8"));
