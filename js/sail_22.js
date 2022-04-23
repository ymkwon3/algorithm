// 자릿수 더하기

// function solution(n)
// {
//     let answer = 0;
//     while (n > 0) {
//         answer += n % 10;
//         n = Math.floor(n / 10);
//     }
//     return answer;
// }

const solution = n => (n + "").split("").reduce((sum,value) => sum + parseInt(value), 0);

console.log(solution(123));