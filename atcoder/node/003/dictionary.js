var start = Date.now();




function Main(input) {
    input = input.split('\n');
    var list = qsort(input.slice(1, input.length - 1));
    for (var i = 0; i < input[0]; i++) {
        console.log(list[i]);
    }
}   
 
function qsort(list) {
    if (list.length <= 1) return list;

    var left = [], 
        right = [], 
        pivot = list[0];
        count = list.length;
    for (var i = 1; i < count; i++) {
        var str = list[i];
        if (isSmall(str, pivot)) {
            left.push(list[i]);
        } else {
            right.push(list[i]);
        }
    }
    return qsort(left).concat([pivot]).concat(qsort(right));
}

function isSmall(str1, str2) {
    var len1 = str1.length,
        len2 = str2.length,
        char1 = str1.charAt(len1 - 1),
        char2 = str2.charAt(len2 - 1);
    if (char1 < char2) {
        return true;
    } else if (char2 < char1) {
        return false;
    } else {
        if (len1 === 1) return true;
        if (len2 === 1) return false;
        return isSmall(str1.substring(0, len1 - 1), str2.substring(0, len2 - 1));
    }
}

Main(require("fs").readFileSync("/dev/stdin", "utf8"));



var end = Date.now();
console.log(end - start);


