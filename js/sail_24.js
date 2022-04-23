// 정수 내림차순으로 배치하기

// function solution(n) {
//     let arr = [];
//     while( n > 0) {
//         arr.push(n % 10);
//         n = Math.floor(n / 10);
//     }
//     arr.sort(function(a, b) {
//         return b - a;
//     });
    
//     let ans = 0;
//     for(let i = 0; i < arr.length; i++) {
//         ans *= 10;
//         ans += arr[i];
//     }
//     return ans;
// }

const solution = n => +(n + "").split("").sort().reverse().join("");

console.log(solution(118372));