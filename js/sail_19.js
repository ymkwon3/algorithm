// 수박수박수박수박수박수?

// function solution(n) {
//     var answer = '';
//     for(let i = 0; i < n; i++) {
//         answer += i % 2 == 0 ? "수" : "박"
//     }
//     return answer;
// }

const solution = (n) => "수박".repeat(n / 2) + (n % 2 != 0 ? '수' : '');

console.log(solution(3))