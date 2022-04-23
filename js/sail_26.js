// 제일 작은 수 제거하기

// function solution(arr) {
//     // 전개구문 배열이나 객체를 펼쳐줌...
//     let min = Math.min(...arr);
//     for(let i = 0; i < arr.length; i++) {
//         if (arr[i] == min) {
//             arr.splice(i, 1);
//             if(arr.length == 0)
//                 arr.push(-1)
//             return arr;
//         }
//     }
// }

function solution(arr) {
    let min = Math.min(...arr);
    arr.splice(arr.indexOf(min), 1);
    return arr.length > 1? arr : [-1];
}

console.log(solution([4,3,2,1]))