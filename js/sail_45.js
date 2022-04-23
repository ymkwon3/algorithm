// K번째 수

function solution(array, commands) {
    let ans = [];

    for(let i = 0; i < commands.length; i++) {
        let arr = [];
        for(let j = commands[i][0] - 1; j < commands[i][1]; j++) {
            arr.push(array[j]);
        }
        arr.sort((a, b) => a - b);
        ans.push(arr[commands[i][2] - 1])
    }
    return ans;
}

console.log(solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]))


























// function solution(array, commands) {
//     var answer = [];
//     for(let i of commands) {
//         answer.push(array.slice(i[0]-1, i[1]).sort(
//             function(a, b) {
//                 if (a > b) {
//                     return 1;
//                 }
//                 if (a < b) {
//                     return -1;
//                 }
//                 return 0;
//             }
//         )[i[2]-1]);
//     }
//     return answer;
// }