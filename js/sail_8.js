// 평균 구하기

// function solution(arr) {
//     let result = 0;
//     for(let i = 0; i < arr.length; i++) {
//         result += arr[i];
//     }
//     result /= arr.length;
//     return result;
// }

// solution([1,2,3,4])

let arr = [1,2,3,4]
result = arr.reduce((acc, cur) => acc + cur, 0);

console.log(result / arr.length)