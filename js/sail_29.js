// 3진법 뒤집기

function solution(n){
    let a = n.toString(3);
    a = a.split("").reverse().join("");
    return parseInt(a, 3);
}

console.log(solution(45));