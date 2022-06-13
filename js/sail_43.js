// 예산

function solution(d, budget) {
    d.sort((a,b) => a - b);
    let sum = 0;
    let i = 0;
    for(; i < d.length; i++) {
        sum += d[i];
        if (sum > budget)
            break;
    }
    return i;
}

console.log(solution([1, 5, 3, 2], 10))



// function solution(d, budget) {
//     var answer = 0;
//     d = d.sort(function (a, b) {
//         if (a > b) return 1;
//         if (a < b) return -1;
//         return 0;
//     });
//     for (let val of d) {
//         budget -= val;
//         if (budget < 0) {
//           break;
//         }
//         answer++;
//     }
//     return answer;
// }