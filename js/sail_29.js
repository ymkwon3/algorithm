// 3진법 뒤집기

// function solution(n){
//     let a = n.toString(3);
//     a = a.split("").reverse().join("");
//     return parseInt(a, 3);
// }

function solution(n) {
    let n_3 = [];
    let answer = 0;
    while(true) {
        n_3 += n % 3;
        if(n < 3) 
            break;
        n = Math.floor(n / 3);
    }
    for(let i = n_3.length - 1, e = 0; i >= 0; i--, e++) {
        answer += n_3[i] * (3**e);
    }
    return answer;
}


console.log(solution(45));