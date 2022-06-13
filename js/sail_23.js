// 자연수 뒤집어 배열로 만들기

// function solution(n) {
//     let ans = [];
//     while (n > 0) {
//         ans.push(n % 10);
//         n = Math.floor(n /10);
//     }
//     return ans;
// }

const solution = n => (n + "").split('').reverse().map(a => parseInt(a));

console.log(solution(12345));